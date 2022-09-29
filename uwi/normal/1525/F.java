//package ecr109;
import java.io.*;
import java.util.*;

public class F {
	InputStream is;
	FastWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni(), K = ni();
		boolean[][] g = new boolean[n][n];
		long ina = 0;
		long outa = 0;
		for(int i = 0;i < m;i++){
			int a = ni()-1, b = ni()-1;
			g[a][b] = true;
			ina |= 1L<<a;
			outa |= 1L<<b;
		}

		int[] xs = new int[K];
		int[] ys = new int[K];
		for(int i = 0;i < K;i++){
			xs[i] = ni();
			ys[i] = ni();

		}

		int mat = doBipartiteMatchingHK(g);
		int[] need = new int[n+1];
		Deque<Integer> er = new ArrayDeque<>();
		outer:
		while(mat > 0) {
			for (int i = 0; i < n; i++) {
				if(ina<<~i>=0)continue;
				boolean[] temp = new boolean[n];
				for (int j = 0; j < n; j++) {
					temp[j] = g[i][j];
					g[i][j] = false;
				}
				int nmat = doBipartiteMatchingHK(g);
				if (nmat < mat) {
					need[nmat] = need[mat] + 1;
					mat = nmat;
					ina ^= 1L<<i;
					er.add((i+1));
					continue outer;
				}
				for (int j = 0; j < n; j++) {
					g[i][j] = temp[j];
				}
			}
			for (int i = 0; i < n; i++) {
				if(outa<<~i>=0)continue;
				boolean[] temp = new boolean[n];
				for (int j = 0; j < n; j++) {
					temp[j] = g[j][i];
					g[j][i] = false;
				}
				int nmat = doBipartiteMatchingHK(g);
				if (nmat < mat) {
					need[nmat] = need[mat] + 1;
					mat = nmat;
					outa ^= 1L<<i;
					er.add(-(i+1));
					continue outer;
				}
				for (int j = 0; j < n; j++) {
					g[j][i] = temp[j];
				}
			}

			for (int i = 0; i < n; i++) {
				if(ina<<~i>=0)continue;
				boolean[] temp1 = new boolean[n];
				for (int j = 0; j < n; j++) {
					temp1[j] = g[i][j];
					g[i][j] = false;
				}
				for(int k = 0;k < n;k++){
					if(outa<<~k>=0)continue;

					boolean[] temp2 = new boolean[n];
					for (int j = 0; j < n; j++) {
						temp2[j] = g[j][k];
						g[j][k] = false;
					}
					int nmat = doBipartiteMatchingHK(g);
					if (nmat < mat) {
						need[nmat] = need[mat] + 2;
						mat = nmat;
						ina ^= 1L<<i;
						outa ^= 1L<<k;
						er.add((i+1));
						er.add(-(k+1));
						continue outer;
					}
					for (int j = 0; j < n; j++) {
						g[j][k] = temp2[j];
					}
				}
				for (int j = 0; j < n; j++) {
					g[i][j] = temp1[j];
				}
			}
			assert false;
		}

		// n-2-i
		long[][] dp = new long[K+1][2*n+1];
		int[][] prev = new int[K+1][2*n+1];
		for(int i = 0;i <= K;i++){
			Arrays.fill(dp[i], Long.MIN_VALUE / 2);
		}
		dp[0][0] = 0;
		for(int i = 0;i < K;i++){
			for(int j = 0;j <= 2*n;j++){
				for(int k = Math.max(j, need[n-2-i]);k <= 2*n;k++){
					long nv = dp[i][j] +
							Math.max(0, xs[i] - (long)ys[i] * (k-j));
					if(nv > dp[i+1][k]){
						dp[i+1][k] = nv;
						prev[i+1][k] = j;
					}
				}
			}
		}
		long max = -1;
		int arg = -1;
		for(int j = 0;j <= 2*n;j++){
			if(dp[K][j] > max){
				max = dp[K][j];
				arg = j;
			}
		}
		Deque<Integer> route = new ArrayDeque<>();
		for(int i = K;i >= 1;i--){
			route.addFirst(0);
			int pre = prev[i][arg];
			int cha = arg - pre;
			for(int j = 0;j < cha;j++){
				route.addFirst(er.pollLast());
			}
			arg = pre;
		}

//		out.println(max);
		out.println(route.size());
		for(int u : route){
			out.print(u + " ");
		}
		out.println();
	}

	public static int doBipartiteMatchingHK(boolean[][] g)
	{
		int n = g.length;
		if(n == 0)return 0;
		int m = g[0].length;
		int[] from = new int[m];
		int[] to = new int[n];
		Arrays.fill(to, -1);
		Arrays.fill(from, n);

		int[] d = new int[n+1];
		int mat = 0;
		while(true){
			Arrays.fill(d, -1);
			int[] q = new int[n];
			int r = 0;
			for(int i = 0;i < n;i++){
				if(to[i] == -1){
					d[i] = 0;
					q[r++] = i;
				}
			}

			for(int p = 0;p < r;p++) {
				int cur = q[p];
				for(int adj = 0;adj < m;adj++){
					if(g[cur][adj]){
						int nex = from[adj];
						if(d[nex] == -1) {
							if(nex != n)q[r++] = nex;
							d[nex] = d[cur] + 1;
						}
					}
				}
			}
			if(d[n] == -1)break;

			for(int i = 0;i < n;i++){
				if(to[i] == -1){
					if(dfsHK(d, g, n, m, to, from, i))mat++;
				}
			}
		}

		return mat;
	}

	static boolean dfsHK(int[] d, boolean[][] g, int n, int m, int[] to, int[] from, int cur)
	{
		if(cur == n)return true;
		for(int adj = 0;adj < m;adj++){
			if(g[cur][adj]){
				int nex = from[adj];
				if(d[nex] == d[cur] + 1 && dfsHK(d, g, n, m, to, from, nex)){
					to[cur] = adj;
					from[adj] = cur;
					return true;
				}
			}
		}
		d[cur] = -1;
		return false;
	}



	void run() throws Exception
	{
//		int n = 50, m = n*(n-1)/2, K = n-1;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(m + " ");
//		sb.append(K + " ");
//		for (int i = 0; i < n; i++) {
//			for(int j = i+1;j < n;j++){
//				sb.append((i+1) + " " + (j+1) + "\n");
//			}
//		}
//		for(int i = 0;i < K;i++){
//			sb.append(gen.nextInt(1000000000)+1 + " " + (gen.nextInt(1000000000)+1) + "\n");
//		}
//		INPUT = sb.toString();

		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new FastWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new F().run(); }
	
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