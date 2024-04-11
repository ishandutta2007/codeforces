//package round698;
import java.io.*;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Queue;

public class B {
	InputStream is;
	FastWriter out;
	String INPUT = "";
	
	void solve()
	{
		for(int T = ni();T > 0;T--)go();
	}

	void go()
	{
		int n = ni(), Q = ni();
		char[] s = ns(n);
		char[] t = ns(n);
		long[] tt = new long[n];
		int[][] qs = new int[Q][];
		for(int i = 0;i < Q;i++){
			qs[i] = new int[]{ni()-1, ni()-1};
		}

		for(int i = 0;i < n;i++)tt[i] = t[i] == '1' ? 1 : 0;
		SegmentTreeRUpdateRSQ st = new SegmentTreeRUpdateRSQ(tt);
		for(int i = Q-1;i >= 0;i--){
			int l = qs[i][0], r = qs[i][1];
			long sum = st.sum(l, r+1);
			if(sum*2 == r-l+1){
				out.println("NO");
				return;
			}
			if(sum*2 < r-l+1){
				st.update(l, r+1, 0);
			}else{
				st.update(l, r+1, 1);
			}
		}
		for(int i = 0;i < n;i++){
			if(st.sum(i, i+1) != s[i]-'0'){
				out.println("NO");
				return;
			}
		}
		out.println("YES");
	}

	public static class SegmentTreeRUpdateRSQ {
		public int M, H, N, LH;
		public long[] sums;
		public long[] cover;
		private final long I = Long.MAX_VALUE;

		public SegmentTreeRUpdateRSQ(int n)
		{
			N = n;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			LH = Integer.numberOfTrailingZeros(H);

			cover = new long[H];
			Arrays.fill(cover, I);
			sums = new long[M];
			Arrays.fill(sums, 0);
			for(int i = H-1;i >= 1;i--)propagate(i);
		}

		public SegmentTreeRUpdateRSQ(long[] a)
		{
			this(a.length);
			for(int i = 0;i < N;i++){
				sums[H+i] = a[i];
			}
			for(int i = H-1;i >= 1;i--){
				propagate(i);
			}
		}

		private void push1(int cur)
		{
			if(cover[cur] == I)return;
			int len = H/Integer.highestOneBit(cur);
			int L = cur*2, R = L + 1;
			sums[L] = sums[R] = cover[cur] * (len/2);
			if(L < H){
				cover[L] = cover[R] = cover[cur];
			}
			cover[cur] = I;
		}

		private void propagate(int i)
		{
			sums[i] = sums[2*i] + sums[2*i+1];
		}

		private void update1(int cur, long v)
		{
			int len = H/Integer.highestOneBit(cur);
			sums[cur] = v*len;
			if(cur < H){
				cover[cur] = v;
			}
		}

		private void push(int l, int r)
		{
			for(int i = LH;i >= 1;i--) {
				if (l >>> i << i != l) push1(l >>> i);
				if (r >>> i << i != r) push1(r >>> i);
			}
		}

		public void update(int l, int r, long v)
		{
			if(l >= r)return;
			l += H; r += H;
			push(l, r);
			for(int ll = l, rr = r;ll < rr;ll>>>=1,rr>>>=1){
				if((ll&1) == 1) update1(ll++, v);
				if((rr&1) == 1) update1(--rr, v);
			}
			for(int i = 1;i <= LH;i++){
				if(l>>>i<<i != l)propagate(l>>>i);
				if(r>>>i<<i != r)propagate(r>>>i);
			}
		}

		public long sum(int l, int r)
		{
			if(l >= r)return 0;
			l += H; r += H;
			push(l, r);
			long ret = 0;
			for(int ll = l, rr = r;ll < rr;ll>>>=1,rr>>>=1){
				if((ll&1) == 1)ret += sums[ll++];
				if((rr&1) == 1)ret += sums[--rr];
			}
			return ret;
		}

		// CF684D1Croot
		// sumsls, rs

		public int reach(long v)
		{
			int cur = 1;
			push1(cur);
			if(v >= sums[cur])return -1;

			while(cur < H){
				push1(2*cur);
				if(sums[2*cur] > v){
					cur = 2*cur;
				}else{
					v -= sums[2*cur];
					cur = 2*cur+1;
					push1(cur);
				}
			}
			return cur - H;
		}

		//	public int lastge(long v)
		//	{
		//		int cur = 1;
		//		push1(cur);
		//		if(v > ls[cur])return -1;
		//
		//		while(cur < H){
		//			push1(2*cur+1);
		//			if(ls[2*cur+1] >= v){
		//				cur = 2*cur+1;
		//			}else{
		//				cur = 2*cur;
		//				push1(cur);
		//			}
		//		}
		//		return cur - H;
		//	}
		//
		//	public int firstle(long v)
		//	{
		//		int cur = 1;
		//		push1(cur);
		//		if(v < rs[cur])return -1;
		//
		//		while(cur < H){
		//			push1(2*cur);
		//			if(rs[2*cur] <= v){
		//				cur = 2*cur;
		//			}else{
		//				cur = 2*cur+1;
		//				push1(cur);
		//			}
		//		}
		//		return cur - H;
		//	}


		private String tos(long[] a, int ind){ return ind < a.length ? "" + a[ind] : "_";}
		private static String j(Object... o){ return Arrays.deepToString(o);}

		public String nodeToString(int cur)
		{
			return j(cur, sums[cur], tos(cover, cur));
		}

		public String toString() {  return toString(1, ""); }

		private String toString(int cur, String indent)
		{
			return cur >= M ? "" :
					toString(2*cur, indent + "  ")
							+ indent + nodeToString(cur) + "\n"
							+ toString(2*cur+1, indent + "  ");
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
	
	public static void main(String[] args) throws Exception { new B().run(); }
	
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