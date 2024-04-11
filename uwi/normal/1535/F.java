//package ecr110;
import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class F2 {
	InputStream is;
	FastWriter out;
	String INPUT = "";

	long M;
	
	void solve()
	{
		Random gen = new Random();
		M = BigInteger.probablePrime(60, gen).longValue();

		int n = ni();
		pows = RollingHash61.makePows(M, 200000/n+2);
		char[][] ss = new char[n][];
		for(int i = 0;i < n;i++){
			ss[i] = ns().toCharArray();
		}
		int[][] ff = new int[n][27];
		for(int i = 0;i < n;i++){
			for(char c : ss[i]){
				ff[i][c-'a']++;
			}
			ff[i][26] = i;
		}
		Comparator<int[]> comp = (x, y) -> {
			for(int j = 0;j < 26;j++){
				if(x[j] != y[j])return x[j] - y[j];
			}
			return 0;
		};
		Arrays.sort(ff, comp);

		long ans = 1337L*n*(n-1)/2;
		for(int i = 0;i < n;){
			int j = i;
			while(j < n && comp.compare(ff[i], ff[j]) == 0)j++;
//			tr(i, j);

			ans -= 1337L * (j-i)*(j-i-1)/2;
			char[][] lss = new char[j-i][];
			for(int k = i;k < j;k++){
				lss[k-i] = ss[ff[k][26]];
			}
			ans += go(lss);

			i = j;
		}
		out.println(ans);
	}

	long go(char[][] ss)
	{
		int n = ss.length;
		int L = ss[0].length;
		if(n == 1)return 0L;

		RollingHash61[] pre = new RollingHash61[n];
		for(int i = 0;i < n;i++){
			pre[i] = new RollingHash61(M, L);
			for(int j = 0;j < L;j++)pre[i].add(ss[i][j]);
		}

		Integer[][] indss = new Integer[L][];
		for (int i = 0; i < L; i++) {
			Integer[] inds = new Integer[n];
			for (int j = 0; j < n; j++) {
				inds[j] = j;
			}
			final int ii = i;
			Arrays.sort(inds, (x, y) -> {
				if(pre[x].h(L-ii, L) != pre[y].h(L-ii, L)){
					int low = L-ii, high = L;
					while(high - low > 1){
						int h = high+low>>1;
						if(pre[x].h(L-ii, h) != pre[y].h(L-ii, h)){
							high = h;
						}else{
							low = h;
						}
					}
					return ss[x][low] - ss[y][low];
				}else{
					int low = 0, high = L-ii;
					while(high - low > 1){
						int h = high+low>>1;
						if(pre[x].h(0, h) != pre[y].h(0, h)){
							high = h;
						}else{
							low = h;
						}
					}
					return ss[x][low] - ss[y][low];
				}
			});
			indss[i] = inds;
		}
		int[][] iinds = new int[L][n];
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < n; j++) {
				iinds[i][indss[i][j]] = j;
			}
		}

		// pairwise distinct
		long ans = 2L * n * (n - 1) / 2;
		for (int i = 0; i < n; i++) {
			int l = 0;
			for (int j = 0; j < L - 1; j++) {
				if (ss[i][j] > ss[i][j + 1]) {
					if(l < j) {
						// [l,j]
						//					tr(ss[i], l, j, count(indss, L - 1 - j, ss, iinds, i, l, pre));
						ans -= count(indss, L - 1 - j, ss, iinds, i, l, pre);
					}
					l = j + 1;
				}
			}
			// [l,L-1]
			ans -= count(indss, 0, ss, iinds, i, l, pre);
		}
		return ans;
	}

	int count(Integer[][] indss, int ind, char[][] ss, int[][] iinds, int who, int len, RollingHash61[] pre)
	{
		int tar = iinds[ind][who];
		int L = ss[0].length;
		int ll = -1;
		{
			int low = -1, high = tar;
			outer:
			while (high - low > 1) {
				int h = high + low >> 1;
				int op = indss[ind][h];
				if(pre[who].h(L-ind, L) == pre[op].h(L-ind, L) &&
					pre[who].h(0, len) == pre[op].h(0, len)
				){
					high = h;
				}else{
					low = h;
				}
			}
			ll = high;
		}
		int hh = -1;
		{
			int low = tar, high = ss.length;
			outer:
			while (high - low > 1) {
				int h = high + low >> 1;
				int op = indss[ind][h];
				if(pre[who].h(L-ind, L) == pre[op].h(L-ind, L) &&
						pre[who].h(0, len) == pre[op].h(0, len)
				){
					low = h;
				}else{
					high = h;
				}
			}
			hh = low;
		}
		return hh-ll;
	}

	public static long[] pows;

	public static class RollingHash61
	{
		static final long mod = (1L<<61)-1;
		public long M;
		public long[] hs;
		public int hp;

		public RollingHash61(long M, int n) {
			assert M > 0;
			assert n > 0;
			this.M = M;
//			this.pows = makePows(M, n);
			this.hs = new long[n+1];
			this.hp = 0;
		}

		public static long mul(long a, long b)
		{
			long al = a&(1L<<31)-1, ah = a>>>31;
			long bl = b&(1L<<31)-1, bh = b>>>31;
			long low = al * bl; // <2^62
			long mid = al * bh + bl * ah; // < 2^62
			long high = ah * bh + (mid>>>31); // < 2^60 + 2^31 < 2^61
			// high*2^62 = high*2 (mod 2^61-1)
			long ret = mod(mod(2*high + low) + ((mid&(1L<<31)-1)<<31));
			return ret;
		}

		public static long mod(long a)
		{
			while(a >= mod)a -= mod;
			while(a < 0)a += mod;
			return a;
		}

		private static long[] makePows(long M, int n)
		{
			long[] ret = new long[n+1];
			ret[0] = 1;
			for(int i = 1;i <= n;i++)ret[i] = mul(ret[i-1], M);
			return ret;
		}

		public void add(long x)
		{
			hs[hp+1] = mul(hs[hp], M) + x;
			if(hs[hp+1] >= mod)hs[hp+1] -= mod;
			hp++;
		}

		public long h(int l, int r)
		{
			assert l <= r;
			return mod(hs[r] - mul(hs[l], pows[r-l]));
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
	
	public static void main(String[] args) throws Exception { new F2().run(); }
	
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