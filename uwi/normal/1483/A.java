//package round709;
import java.io.*;
import java.util.*;

public class A {
	InputStream is;
	FastWriter out;
	String INPUT = "";
	
	void solve()
	{
		for(int T = ni();T > 0;T--)go();
	}

	void go()
	{
		int n = ni(), m = ni();
		int src = n+m, sink = n+m+1;
		List<Edge> es = new ArrayList<>();
		for(int i = 0;i < m;i++){
			for(int v : na(ni())){
				es.add(new Edge(v-1, i+n, 1));
			}
		}
		for(int i = 0;i < n;i++){
			es.add(new Edge(src, i, (m+1)/2));
		}
		for(int i = 0;i < m;i++){
			es.add(new Edge(n+i, sink, 1));
		}
		long F = fifopp(compileWD(sink+1, es), src, sink);
		if(F == m){
			out.println("YES");
			int[] frs = new int[m];
			for(Edge e : es){
				if(e.from < n && e.to >= n && e.to < n+m && e.flow == 1){
					frs[e.to-n] = e.from;
				}
			}
			for(int v : frs){
				out.print(v+1).print(" ");
			}
			out.println();
		}else{
			out.println("NO");
		}
	}

	public static class Edge
	{
		public int from, to;
		public long capacity;
		public long flow;
		public Edge complement;
		public boolean cloned;

		public Edge(int from, int to, long capacity) {
			this.from = from;
			this.to = to;
			this.capacity = capacity;
		}
	}

	public static void reset(Edge[][] g)
	{
		for(Edge[] row : g){
			for(Edge e : row){
				e.flow = e.cloned ? e.capacity : 0;
			}
		}
	}

	public static Edge[][] compileWD(int n, List<Edge> edges)
	{
		Edge[][] g = new Edge[n][];
		// cloning
		for(int i = edges.size()-1;i >= 0;i--){
			Edge origin = edges.get(i);
			Edge clone = new Edge(origin.to, origin.from, origin.capacity);
			clone.flow = origin.capacity - origin.flow;
			clone.complement = origin;
			clone.cloned = true;
			origin.complement = clone;
			edges.add(clone);
		}

		int[] p = new int[n];
		for(Edge e : edges)p[e.from]++;
		for(int i = 0;i < n;i++)g[i] = new Edge[p[i]];
		for(Edge e : edges)g[e.from][--p[e.from]] = e;
		return g;
	}

	public static Edge[][] compileWU(int n, List<Edge> edges)
	{
		Edge[][] g = new Edge[n][];
		// cloning
		for(int i = edges.size()-1;i >= 0;i--){
			Edge origin = edges.get(i);
			Edge clone = new Edge(origin.to, origin.from, origin.capacity*2);
			origin.flow = origin.capacity;
			clone.flow = origin.capacity;
			clone.complement = origin;
			clone.cloned = true;
			origin.complement = clone;
			origin.capacity *= 2;
			edges.add(clone);
		}

		int[] p = new int[n];
		for(Edge e : edges)p[e.from]++;
		for(int i = 0;i < n;i++)g[i] = new Edge[p[i]];
		for(Edge e : edges)g[e.from][--p[e.from]] = e;
		return g;
	}

	private static void add(int[] first, int[] next, int[] prev, int level, int x)
	{
		next[x] = first[level];
		if(next[x] != -1)prev[next[x]] = x;
		first[level] = x;
	}

	private static void remove(int[] first, int[] next, int[] prev, int level, int x)
	{
		int p = prev[x];
		int n = next[x];
		if(p == -1)first[level] = n;
		if(p != -1)next[p] = n;
		if(n != -1)prev[n] = p;
		prev[x] = next[x] = -1;
	}

	private static int labelGrobally(Edge[][] g, int source, int sink, int[] label,
	                                 EQ q,
	                                 int[] gapFirst, int[] gapNext, int[] gapPrev,
	                                 long[] excess)
	{
		Arrays.fill(gapFirst, -1);
		Arrays.fill(gapNext, -1);
		Arrays.fill(gapPrev, -1);
		int n = g.length;
		q.clear();

		Arrays.fill(label, n);
		label[sink] = 0;
		int[] lq = new int[n];
		int p = 0;
		lq[p++] = sink;
		for(int z = 0;z < p;z++){
			int cur = lq[z];
			for(Edge e : g[cur]){
				if(e.flow > 0 && label[e.to] > label[e.from] + 1){
					label[e.to] = label[e.from] + 1;
					lq[p++] = e.to;
				}
			}
		}
		int highest = 0;
		for(int i = 0;i < n;i++){
			if(label[i] < n){
				if(excess[i] > 0){
					highest = Math.max(highest, label[i]);
					q.add(i);
				}
				add(gapFirst, gapNext, gapPrev, label[i], i);
			}
		}
		return highest;
	}

	public static long fifopp(Edge[][] g, int source, int sink)
	{
		long big = Long.MAX_VALUE / 2;
		int n = g.length;
		int[] label = new int[n];
		long[] excess = new long[n];
		excess[source] = big;
		excess[sink] = -big;

		EQ q = new EQ();
		//		Q q = new Q(3*n);
		int[] gapFirst = new int[n];
		int[] gapNext = new int[n];
		int[] gapPrev = new int[n];

		labelGrobally(g, source, sink, label, q, gapFirst, gapNext, gapPrev, excess);

		// flow (src, *)
		for(Edge se : g[source]){
			if(excess[se.to] == 0 && label[se.to] < n){
				q.add(se.to);
			}
			push(se, excess);
		}

		int nUpdate = 0;
		while(!q.isEmpty()){
			int cur = q.poll();
			if(label[cur] == n)continue;
			for(Edge e : g[cur]){
				if(excess[cur] == 0)break;
				if(label[e.from] == label[e.to] + 1 && e.flow < e.capacity){
					if(excess[e.to] == 0)q.add(e.to);
					push(e, excess);
				}
			}
			if(excess[cur] > 0){
				int oldh = label[cur];
				remove(gapFirst, gapNext, gapPrev, label[cur], cur);
				relabel(cur, g, label);
				if(label[cur] < n){
					add(gapFirst, gapNext, gapPrev, label[cur], cur);
				}

				if(gapFirst[oldh] == -1){
					// gap-relabelling
					for(int h = oldh+1;h < n;h++){
						for(int y = gapFirst[h];y != -1;y = gapNext[y]){
							label[y] = n;
							gapNext[y] = gapPrev[y] = -1;
						}
						gapFirst[h] = -1;
					}
				}else if(label[cur] < n){
					nUpdate++;
					q.add(cur);
				}
			}
			if(nUpdate > 4*n){
				nUpdate = 0;
				// verify label
				//					for(int u = 0;u < n;u++){
				//						for(int x = gapFirst[u];x != -1;x = gapNext[u]){
				//							if(label[x] != u)throw new RuntimeException();
				//							if(gapPrev[x] != -1){
				//								if(gapNext[gapPrev[x]] != x){
				//									throw new RuntimeException();
				//								}
				//							}else{
				//								if(gapFirst[u] != x){
				//									throw new RuntimeException();
				//								}
				//							}
				//						}
				//					}
				labelGrobally(g, source, sink, label, q, gapFirst, gapNext, gapPrev, excess);
			}
		}
		return excess[sink] + big;
	}

	private static void push(Edge e, long[] excess)
	{
		long f = Math.min(excess[e.from], e.capacity - e.flow);
		e.flow += f;
		e.complement.flow -= f;
		excess[e.from] -= f;
		excess[e.to] += f;
	}

	private static void relabel(int cur, Edge[][] g, int[] label)
	{
		int n = g.length;
		int min = n;
		for(Edge e : g[cur]){
			if(e.flow < e.capacity)min = Math.min(min, label[e.to] + 1);
		}
		label[cur] = min;
	}

	public static class EQ {
		public int[] q;
		protected int pt, ph;
		public EQ(){ q = new int[2]; pt = ph = 0; }
		public void add(int x){
			if(ph == q.length)scale();
			q[ph++] = x;
		}
		public void scale()
		{
			int n = q.length;
			int[] nq = new int[n*3/2];
			System.arraycopy(q, pt, nq, 0, ph-pt);
			q = nq;
			ph = ph-pt;
			pt = 0;
		}
		public void clear(){ pt = ph = 0; }
		public int poll(){ return q[pt++]; }
		public int size(){ return ph-pt; }
		public boolean isEmpty(){ return ph==pt; }
	}


	void run() throws Exception
	{
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new FastWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new A().run(); }
	
	private byte[] inbuf = new byte[1024];
	public int lenbuf = 0, ptrbuf = 0;
	
	private int readByte()
	{
		if(lenbuf == -1)throw new InputMismatchException();
		if(ptrbuf >= lenbuf){
			ptrbuf = 0;
			try { lenbuf = is.read(inbuf); } catch (IOException e) { throw new InputMismatchException(); }
			if(lenbuf <= 0)return -1;
		}
		return inbuf[ptrbuf++];
	}
	
	private boolean isSpaceChar(int c) { return !(c >= 33 && c <= 126); }
	private int skip() { int b; while((b = readByte()) != -1 && isSpaceChar(b)); return b; }
	
	private double nd() { return Double.parseDouble(ns()); }
	private char nc() { return (char)skip(); }
	
	private String ns()
	{
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while(!(isSpaceChar(b))){ // when nextLine, (isSpaceChar(b) && b != ' ')
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}
	
	private char[] ns(int n)
	{
		char[] buf = new char[n];
		int b = skip(), p = 0;
		while(p < n && !(isSpaceChar(b))){
			buf[p++] = (char)b;
			b = readByte();
		}
		return n == p ? buf : Arrays.copyOf(buf, p);
	}

	private int[] na(int n)
	{
		int[] a = new int[n];
		for(int i = 0;i < n;i++)a[i] = ni();
		return a;
	}

	private long[] nal(int n)
	{
		long[] a = new long[n];
		for(int i = 0;i < n;i++)a[i] = nl();
		return a;
	}

	private char[][] nm(int n, int m) {
		char[][] map = new char[n][];
		for(int i = 0;i < n;i++)map[i] = ns(m);
		return map;
	}

	private int[][] nmi(int n, int m) {
		int[][] map = new int[n][];
		for(int i = 0;i < n;i++)map[i] = na(m);
		return map;
	}

	private int ni() { return (int)nl(); }

	private long nl()
	{
		long num = 0;
		int b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}

		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}

	public static class FastWriter
	{
		private static final int BUF_SIZE = 1<<13;
		private final byte[] buf = new byte[BUF_SIZE];
		private final OutputStream out;
		private int ptr = 0;

		private FastWriter(){out = null;}

		public FastWriter(OutputStream os)
		{
			this.out = os;
		}

		public FastWriter(String path)
		{
			try {
				this.out = new FileOutputStream(path);
			} catch (FileNotFoundException e) {
				throw new RuntimeException("FastWriter");
			}
		}

		public FastWriter write(byte b)
		{
			buf[ptr++] = b;
			if(ptr == BUF_SIZE)innerflush();
			return this;
		}

		public FastWriter write(char c)
		{
			return write((byte)c);
		}

		public FastWriter write(char[] s)
		{
			for(char c : s){
				buf[ptr++] = (byte)c;
				if(ptr == BUF_SIZE)innerflush();
			}
			return this;
		}

		public FastWriter write(String s)
		{
			s.chars().forEach(c -> {
				buf[ptr++] = (byte)c;
				if(ptr == BUF_SIZE)innerflush();
			});
			return this;
		}

		private static int countDigits(int l) {
			if (l >= 1000000000) return 10;
			if (l >= 100000000) return 9;
			if (l >= 10000000) return 8;
			if (l >= 1000000) return 7;
			if (l >= 100000) return 6;
			if (l >= 10000) return 5;
			if (l >= 1000) return 4;
			if (l >= 100) return 3;
			if (l >= 10) return 2;
			return 1;
		}

		public FastWriter write(int x)
		{
			if(x == Integer.MIN_VALUE){
				return write((long)x);
			}
			if(ptr + 12 >= BUF_SIZE)innerflush();
			if(x < 0){
				write((byte)'-');
				x = -x;
			}
			int d = countDigits(x);
			for(int i = ptr + d - 1;i >= ptr;i--){
				buf[i] = (byte)('0'+x%10);
				x /= 10;
			}
			ptr += d;
			return this;
		}

		private static int countDigits(long l) {
			if (l >= 1000000000000000000L) return 19;
			if (l >= 100000000000000000L) return 18;
			if (l >= 10000000000000000L) return 17;
			if (l >= 1000000000000000L) return 16;
			if (l >= 100000000000000L) return 15;
			if (l >= 10000000000000L) return 14;
			if (l >= 1000000000000L) return 13;
			if (l >= 100000000000L) return 12;
			if (l >= 10000000000L) return 11;
			if (l >= 1000000000L) return 10;
			if (l >= 100000000L) return 9;
			if (l >= 10000000L) return 8;
			if (l >= 1000000L) return 7;
			if (l >= 100000L) return 6;
			if (l >= 10000L) return 5;
			if (l >= 1000L) return 4;
			if (l >= 100L) return 3;
			if (l >= 10L) return 2;
			return 1;
		}

		public FastWriter write(long x)
		{
			if(x == Long.MIN_VALUE){
				return write("" + x);
			}
			if(ptr + 21 >= BUF_SIZE)innerflush();
			if(x < 0){
				write((byte)'-');
				x = -x;
			}
			int d = countDigits(x);
			for(int i = ptr + d - 1;i >= ptr;i--){
				buf[i] = (byte)('0'+x%10);
				x /= 10;
			}
			ptr += d;
			return this;
		}

		public FastWriter write(double x, int precision)
		{
			if(x < 0){
				write('-');
				x = -x;
			}
			x += Math.pow(10, -precision)/2;
			//		if(x < 0){ x = 0; }
			write((long)x).write(".");
			x -= (long)x;
			for(int i = 0;i < precision;i++){
				x *= 10;
				write((char)('0'+(int)x));
				x -= (int)x;
			}
			return this;
		}

		public FastWriter writeln(char c){
			return write(c).writeln();
		}

		public FastWriter writeln(int x){
			return write(x).writeln();
		}

		public FastWriter writeln(long x){
			return write(x).writeln();
		}

		public FastWriter writeln(double x, int precision){
			return write(x, precision).writeln();
		}

		public FastWriter write(int... xs)
		{
			boolean first = true;
			for(int x : xs) {
				if (!first) write(' ');
				first = false;
				write(x);
			}
			return this;
		}

		public FastWriter write(long... xs)
		{
			boolean first = true;
			for(long x : xs) {
				if (!first) write(' ');
				first = false;
				write(x);
			}
			return this;
		}

		public FastWriter writeln()
		{
			return write((byte)'\n');
		}

		public FastWriter writeln(int... xs)
		{
			return write(xs).writeln();
		}

		public FastWriter writeln(long... xs)
		{
			return write(xs).writeln();
		}

		public FastWriter writeln(char[] line)
		{
			return write(line).writeln();
		}

		public FastWriter writeln(char[]... map)
		{
			for(char[] line : map)write(line).writeln();
			return this;
		}

		public FastWriter writeln(String s)
		{
			return write(s).writeln();
		}

		private void innerflush()
		{
			try {
				out.write(buf, 0, ptr);
				ptr = 0;
			} catch (IOException e) {
				throw new RuntimeException("innerflush");
			}
		}

		public void flush()
		{
			innerflush();
			try {
				out.flush();
			} catch (IOException e) {
				throw new RuntimeException("flush");
			}
		}

		public FastWriter print(byte b) { return write(b); }
		public FastWriter print(char c) { return write(c); }
		public FastWriter print(char[] s) { return write(s); }
		public FastWriter print(String s) { return write(s); }
		public FastWriter print(int x) { return write(x); }
		public FastWriter print(long x) { return write(x); }
		public FastWriter print(double x, int precision) { return write(x, precision); }
		public FastWriter println(char c){ return writeln(c); }
		public FastWriter println(int x){ return writeln(x); }
		public FastWriter println(long x){ return writeln(x); }
		public FastWriter println(double x, int precision){ return writeln(x, precision); }
		public FastWriter print(int... xs) { return write(xs); }
		public FastWriter print(long... xs) { return write(xs); }
		public FastWriter println(int... xs) { return writeln(xs); }
		public FastWriter println(long... xs) { return writeln(xs); }
		public FastWriter println(char[] line) { return writeln(line); }
		public FastWriter println(char[]... map) { return writeln(map); }
		public FastWriter println(String s) { return writeln(s); }
		public FastWriter println() { return writeln(); }
	}

	public void trnz(int... o)
	{
		for(int i = 0;i < o.length;i++)if(o[i] != 0)System.out.print(i+":"+o[i]+" ");
		System.out.println();
	}

	// print ids which are 1
	public void trt(long... o)
	{
		Queue<Integer> stands = new ArrayDeque<>();
		for(int i = 0;i < o.length;i++){
			for(long x = o[i];x != 0;x &= x-1)stands.add(i<<6|Long.numberOfTrailingZeros(x));
		}
		System.out.println(stands);
	}

	public void tf(boolean... r)
	{
		for(boolean x : r)System.out.print(x?'#':'.');
		System.out.println();
	}

	public void tf(boolean[]... b)
	{
		for(boolean[] r : b) {
			for(boolean x : r)System.out.print(x?'#':'.');
			System.out.println();
		}
		System.out.println();
	}

	public void tf(long[]... b)
	{
		if(INPUT.length() != 0) {
			for (long[] r : b) {
				for (long x : r) {
					for (int i = 0; i < 64; i++) {
						System.out.print(x << ~i < 0 ? '#' : '.');
					}
				}
				System.out.println();
			}
			System.out.println();
		}
	}

	public void tf(long... b)
	{
		if(INPUT.length() != 0) {
			for (long x : b) {
				for (int i = 0; i < 64; i++) {
					System.out.print(x << ~i < 0 ? '#' : '.');
				}
			}
			System.out.println();
		}
	}

	private boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	private void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}