//package round773;
import java.io.*;
import java.util.*;

public class C {
	InputStream is;
	FastWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), Q = ni();
		LST alive = new LST(n+1);
		alive.setRange(n+1);

		int[] re = new int[n];
		Arrays.fill(re, n+5);
		int[][] qs = new int[Q][];
		int[] anss = new int[Q];
		int[][] co = new int[Q][];
		int p = 0;
		for(int z = 0;z < Q;z++){
			int t = ni();
			if(t == 0){
				int l = ni()-1, r = ni()-1;
				int x = ni();
				qs[z] = new int[]{t, l, r, x};
				if(x == 0) {
					for (int i = alive.next(l); i != -1 && i <= r; i = alive.next(i)) {
						alive.unset(i);
					}
				}else{
					co[p++] = new int[]{l, r};
				}
			}else{
				int x = ni()-1;
				if(!alive.get(x)){
					anss[z] = -1;
				}else{
					int l = alive.prev(x-1) + 1;
					int r = alive.next(x+1) - 1;
					// [l,x], [x,r]
					qs[z] = new int[]{t, l, x, r};
				}
			}
		}

		StaticRangeTreeRSQ st = new StaticRangeTreeRSQ(Arrays.copyOf(co, p), n);

		for(int z = 0;z < Q;z++){
			int[] q = qs[z];
			if(q == null){
				out.println("NO");
				continue;
			}
			int t = q[0];
			if(t == 0){
				int x = q[3];
				if(x == 0) {
				}else{
					st.add(q[1], q[2], 1);
				}
			}else{
				if(anss[z] == -1){
					out.println("NO");
				}else {
					if (st.sum(q[1], q[2] + 1, q[2], q[3] + 1) > 0) {
						out.println("YES");
					}else{
						out.println("N/A");
					}
				}
			}
		}
	}

	public static class StaticRangeTreeRSQ {
		public int M, H, N;
		public int[][] fts;
		public int[][] maps;
		public int[] count;
		public int I = Integer.MAX_VALUE;

		/**
		 * @param co DESTRUCTIVE
		 * @param n limit of coordinate
		 */
		public StaticRangeTreeRSQ(int[][] co, int n)
		{
			N = n;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;

			Arrays.sort(co, new Comparator<int[]>() { // x asc
				public int compare(int[] a, int[] b) {
					if(a[0] != b[0])return a[0] - b[0];
					return a[1] - b[1];
				}
			});
			maps = new int[M][];
			fts = new int[M][];
			count = new int[M];
			for(int i = 0;i < co.length;i++){
				count[H+co[i][0]]++;
			}
			int off = 0;
			for(int i = 0;i < n;i++){
				maps[H+i] = new int[count[H+i]];
				for(int j = 0;j < count[H+i];j++,off++){
					maps[H+i][j] = co[off][1];
				}
				fts[H+i] = new int[count[H+i]+1];
			}

			for(int i = H-1;i >= 1;i--){
				if(maps[2*i+1] == null){
					maps[i] = maps[2*i];
					count[i] = count[2*i];
				}else{
					count[i] = count[2*i] + count[2*i+1];
					maps[i] = new int[count[i]];
					int l = 0;
					int j = 0, k = 0;
					while(j < count[2*i] && k < count[2*i+1]){
						if(maps[2*i][j] < maps[2*i+1][k]){
							maps[i][l++] = maps[2*i][j++];
						}else if(maps[2*i][j] > maps[2*i+1][k]){
							maps[i][l++] = maps[2*i+1][k++];
						}else{
							maps[i][l++] = maps[2*i][j++];
							k++;
						}
					}
					while(j < count[2*i])maps[i][l++] = maps[2*i][j++];
					while(k < count[2*i+1])maps[i][l++] = maps[2*i+1][k++];
					if(l != count[i]){ // uniq
						count[i] = l;
						maps[i] = Arrays.copyOf(maps[i], l);
					}
				}
				fts[i] = new int[count[i]+1];
			}
		}

		public void add(int x, int y, int v)
		{
			for(int pos = H+x;pos >= 1;pos>>>=1){
				int ind = Arrays.binarySearch(maps[pos], y);
				if(ind >= 0){
					addFenwick(fts[pos], ind, v);
				}else{
					throw new RuntimeException(String.format("access to non-existing point : (%d,%d):%d", x, y, v));
				}
			}
		}

		public long gsum;

		// [xl,xr)*[yl,yr)
		public long sum(int xl, int xr, int yl, int yr) {
			gsum = 0;
			sum(xl, xr, yl, yr, 0, H, 1);
			return gsum;
		}

		public void sum(int xl, int xr, int yl, int yr, int cl, int cr, int cur)
		{
			if(xl <= cl && cr <= xr){
				int indl = Arrays.binarySearch(maps[cur], yl-1);
				int indr = Arrays.binarySearch(maps[cur], yr-1);
				if(indl < 0)indl = -indl - 2;
				if(indr < 0)indr = -indr - 2;
				gsum += sumFenwick(fts[cur], indr) - sumFenwick(fts[cur], indl);
			}else{
				int mid = cl+cr>>>1;
				if(cl < xr && xl < mid)sum(xl, xr, yl, yr, cl, mid, 2*cur);
				if(mid < xr && xl < cr)sum(xl, xr, yl, yr, mid, cr, 2*cur+1);
			}
		}

		public static int sumFenwick(int[] ft, int i)
		{
			int sum = 0;
			for(i++;i > 0;i -= i&-i)sum += ft[i];
			return sum;
		}

		public static void addFenwick(int[] ft, int i, int v)
		{
			if(v == 0 || i < 0)return;
			int n = ft.length;
			for(i++;i < n;i += i&-i)ft[i] += v;
		}
	}


	public static class SegmentTreeRMQ {
		public final int M, H, N;
		public int[] vals;
		public static final int I = Integer.MAX_VALUE;

		public SegmentTreeRMQ(int n)
		{
			N = n;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			vals = new int[M];
			Arrays.fill(vals, 0, M, I);
		}

		public SegmentTreeRMQ(int[] a)
		{
			this(a.length);
			for(int i = 0;i < N;i++){
				vals[H+i] = a[i];
			}
			//		Arrays.fill(vals, H+N, M, I);
			for(int i = H-1;i >= 1;i--)propagate(i);
		}

		public void update(int pos, int x)
		{
			vals[H+pos] = x;
			for(int i = (H+pos)>>>1;i >= 1;i >>>= 1)propagate(i);
		}

		private void propagate(int i)
		{
			vals[i] = Math.min(vals[2*i], vals[2*i+1]);
		}

		public int min(int l, int r){
			int min = I;
			if(l >= r)return min;
			l += H; r += H;
			for(;l < r;l>>>=1,r>>>=1){
				if((l&1) == 1)min = Math.min(min, vals[l++]);
				if((r&1) == 1)min = Math.min(min, vals[--r]);
			}
			return min;
		}

		public int firstle(int l, int v) {
			if(l >= H)return -1;
			int cur = H+l;
			while(true){
				if(vals[cur] <= v){
					if(cur >= H)return cur-H;
					cur = 2*cur;
				}else{
					cur++;
					if((cur&cur-1) == 0)return -1;
					if((cur&1)==0)cur>>>=1;
				}
			}
		}

		public int lastle(int l, int v) {
			if(l < 0)return -1;
			int cur = H+l;
			while(true){
				if(vals[cur] <= v){
					if(cur >= H)return cur-H;
					cur = 2*cur + 1;
				}else{
					if((cur&cur-1) == 0)return -1;
					cur--;
					if((cur&1)==1)cur>>>=1;
				}
			}
		}
	}


	public static class LST {
		public long[][] set;
		public int n;
		//	public int size;

		public LST(int n) {
			this.n = n;
			int d = 1;
			for(int m = n;m > 1;m>>>=6, d++);

			set = new long[d][];
			for(int i = 0, m = n>>>6;i < d;i++, m>>>=6){
				set[i] = new long[m+1];
			}
			//		size = 0;
		}

		// [0,r)
		public LST setRange(int r)
		{
			for(int i = 0;i < set.length;i++, r=r+63>>>6){
				for(int j = 0;j < r>>>6;j++){
					set[i][j] = -1L;
				}
				if((r&63) != 0)set[i][r>>>6] |= (1L<<r)-1;
			}
			return this;
		}

		// [0,r)
		public LST unsetRange(int r)
		{
			if(r >= 0){
				for(int i = 0;i < set.length;i++, r=r+63>>>6){
					for(int j = 0;j < r+63>>>6;j++){
						set[i][j] = 0;
					}
					if((r&63) != 0)set[i][r>>>6] &= -(1L << r);
				}
			}
			return this;
		}

		public LST set(int pos)
		{
			if(pos >= 0 && pos < n){
				//			if(!get(pos))size++;
				for(int i = 0;i < set.length;i++, pos>>>=6){
					set[i][pos>>>6] |= 1L<<pos;
				}
			}
			return this;
		}

		public LST unset(int pos)
		{
			if(pos >= 0 && pos < n){
				//			if(get(pos))size--;
				for(int i = 0;i < set.length && (i == 0 || set[i-1][pos] == 0L);i++, pos>>>=6){
					set[i][pos>>>6] &= ~(1L<<pos);
				}
			}
			return this;
		}

		public boolean get(int pos)
		{
			return pos >= 0 && pos < n && set[0][pos>>>6]<<~pos<0;
		}

		public LST toggle(int pos)
		{
			return get(pos) ? unset(pos) : set(pos);
		}

		public int prev(int pos)
		{
			for(int i = 0;i < set.length && pos >= 0;i++, pos>>>=6, pos--){
				int pre = prev(set[i][pos>>>6], pos&63);
				if(pre != -1){
					pos = pos>>>6<<6|pre;
					while(i > 0)pos = pos<<6|63-Long.numberOfLeadingZeros(set[--i][pos]);
					return pos;
				}
			}
			return -1;
		}

		public int next(int pos)
		{
			for(int i = 0;i < set.length && pos>>>6 < set[i].length;i++, pos>>>=6, pos++){
				int nex = next(set[i][pos>>>6], pos&63);
				if(nex != -1){
					pos = pos>>>6<<6|nex;
					while(i > 0)pos = pos<<6|Long.numberOfTrailingZeros(set[--i][pos]);
					return pos;
				}
			}
			return -1;
		}

		private static int prev(long set, int n)
		{
			long h = set<<~n;
			if(h == 0L)return -1;
			return -Long.numberOfLeadingZeros(h)+n;
		}

		private static int next(long set, int n)
		{
			long h = set>>>n;
			if(h == 0L)return -1;
			return Long.numberOfTrailingZeros(h)+n;
		}

		@Override
		public String toString()
		{
			List<Integer> list = new ArrayList<>();
			for(int pos = next(0);pos != -1;pos = next(pos+1)){
				list.add(pos);
			}
			return list.toString();
		}
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
	
	public static void main(String[] args) throws Exception { new C().run(); }
	
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