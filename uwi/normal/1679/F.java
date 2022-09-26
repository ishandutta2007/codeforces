//package round791;
import java.io.*;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Queue;

public class F2 {
	InputStream is;
	FastWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		boolean[][] g = new boolean[10][10];
		for(int m = ni();m > 0;m--){
			int x = ni(), y = ni();
			g[x][y] = g[y][x] = true;
		}
		for(int i = 0;i < 10;i++)g[i][i] = true;

		int[][] njs = new int[1<<9][10];
		for(int j = 0;j < 1<<9;j++) {
			for (int k = 0; k < 10; k++) {
				if (j << ~k >= 0) {
					int nj = j;
					for (int l = 0; l < 10; l++) {
						if (g[k][l]) {
							if (k > l) {
								nj |= 1 << l;
							}
						} else {
							nj &= ~(1 << l);
						}
					}
					njs[j][k] = nj;
				}
			}
		}


		long[] dp = new long[1<<9];
		dp[0] = 1;
		for(int i = 1;i <= n;i++){
			long[] ndp = new long[1<<9];
			for(int j = 0;j < 1<<9;j++){
				for(int k = 0;k < 10;k++){
					if (j << ~k >= 0) {
						int nj = njs[j][k];
						ndp[nj] += dp[j];
						if(ndp[nj] >= mod)ndp[nj] -= mod;
					}
				}
			}
			dp = ndp;
		}
		long ans = sum(dp) % mod;
		out.println(ans);
	}

	public static long sum(long... a){long ret = 0; for(long v : a)ret += v; return ret;}


	public static final int mod = 998244353;
	public static final int G = 3;

	// only 998244353
	public static long[] mul(long[] a, long[] b)
	{
		if(a.length == 0 && b.length == 0)return new long[0];
		if(a.length + b.length >= 300) {
			return Arrays.copyOf(NTTStockham998244353.convolve(a, b), a.length + b.length - 1);
		}else{
			return mulnaive(a, b);
		}
	}

	public static long[] mul(long[] a, long[] b, int lim)
	{
		if(a.length + b.length >= 300) {
			return Arrays.copyOf(NTTStockham998244353.convolve(a, b), lim);
		}else{
			return mulnaive(a, b, lim);
		}
	}

	//	public static final int mod = 1000000007;
	//	public static long[] mul(long[] a, long[] b)
	//	{
	//		if(Math.max(a.length, b.length) >= 3000){
	//			return Arrays.copyOf(NTTCRT.convolve(a, b, 3, mod), a.length+b.length-1);
	//		}else{
	//			return mulnaive(a, b);
	//		}
	//	}

	//	public static long[] mul(long[] a, long[] b, int lim)
	//	{
	//		if(Math.max(a.length, b.length) >= 3000){
	//			return Arrays.copyOf(NTTCRT.convolve(a, b, 3, mod), lim);
	//		}else{
	//			return mulnaive(a, b, lim);
	//		}
	//	}

	public static final long big = (Long.MAX_VALUE/mod/mod-1)*mod*mod;

	public static long[] mulnaive(long[] a, long[] b)
	{
		long[] c = new long[a.length+b.length-1];
		for(int i = 0;i < a.length;i++){
			for(int j = 0;j < b.length;j++){
				c[i+j] += a[i]*b[j];
				if(c[i+j] >= big)c[i+j] -= big;
			}
		}
		for(int i = 0;i < c.length;i++)c[i] %= mod;
		return c;
	}

	public static long[] mulnaive(long[] a, long[] b, int lim)
	{
		long[] c = new long[lim];
		for(int i = 0;i < a.length;i++){
			for(int j = 0;j < b.length && i+j < lim;j++){
				c[i+j] += a[i]*b[j];
				if(c[i+j] >= big)c[i+j] -= big;
			}
		}
		for(int i = 0;i < c.length;i++)c[i] %= mod;
		return c;
	}


	public static class NTTStockham998244353 {
		private static final int P = 998244353, mod = P, G = 3;
		private static long[] wps;

		public static long[] convolve(long[] a, long[] b)
		{
			int m = Math.max(2, Integer.highestOneBit(Math.max(a.length, b.length)-1)<<2);

			wps = new long[m];
			long unit = pow(G, (P-1)/m);
			wps[0] = 1;
			for(int p = 1;p < m;p++) {
				wps[p] = wps[p-1] * unit % mod;
			}

			long[] fa = go(a, m, false);
			long[] fb = a == b ? fa : go(b, m, false);
			for(int i = 0;i < m;i++){
				fa[i] = fa[i]*fb[i] % mod;
			}
			fa = go(fa, m, true);
			for(int i = 1, j = m-1;i < j;i++,j--) {
				long d = fa[i]; fa[i] = fa[j]; fa[j] = d;
			}
			return fa;
		}

		private static void fft(long[] X, long[] Y)
		{
			int s = 1;
			boolean eo = false;
			for(int n = X.length;n >= 4;n /= 2) {
				int m = n/2;
				for(int p = 0;p < m;p++) {
					long wp = wps[s*p];
					long wk = (wp<<32)/P;
					for(int q = 0;q < s;q++) {
						long a = X[q + s*(p+0)];
						long b = X[q + s*(p+m)];
						long ndsts = a + b;
						if(ndsts >= 2*P)ndsts -= 2*P;
						long T = a - b + 2*P;
						long Q = wk*T>>>32;
						Y[q + s*(2*p+0)] = ndsts;
						Y[q + s*(2*p+1)] = wp*T-Q*P&(1L<<32)-1;
					}
				}
				s *= 2;
				eo = !eo;
				long[] D = X; X = Y; Y = D;
			}
			long[] z = eo ? Y : X;
			for(int q = 0;q < s;q++) {
				long a = X[q + 0];
				long b = X[q + s];
				z[q+0] = (a+b) % P;
				z[q+s] = (a-b+2*P) % P;
			}
		}

		//	private static void fft(long[] X, long[] Y)
		//	{
		//		int s = 1;
		//		boolean eo = false;
		//		for(int n = X.length;n >= 4;n /= 2) {
		//			int m = n/2;
		//			for(int p = 0;p < m;p++) {
		//				long wp = wps[s*p];
		//				for(int q = 0;q < s;q++) {
		//					long a = X[q + s*(p+0)];
		//					long b = X[q + s*(p+m)];
		//					Y[q + s*(2*p+0)] = (a+b) % P;
		//					Y[q + s*(2*p+1)] = (a-b+P) * wp % P;
		//				}
		//			}
		//			s *= 2;
		//			eo = !eo;
		//			long[] D = X; X = Y; Y = D;
		//		}
		//		long[] z = eo ? Y : X;
		//		for(int q = 0;q < s;q++) {
		//			long a = X[q + 0];
		//			long b = X[q + s];
		//			z[q+0] = (a+b) % P;
		//			z[q+s] = (a-b+P) % P;
		//		}
		//	}

		private static long[] go(long[] src, int n, boolean inverse)
		{
			long[] dst = Arrays.copyOf(src, n);
			fft(dst, new long[n]);
			if(inverse){
				long in = invl(n);
				for(int i = 0;i < n;i++){
					dst[i] = dst[i] * in % mod;
				}
			}

			return dst;
		}

		private static long pow(long a, long n) {
			//		a %= mod;
			long ret = 1;
			int x = 63 - Long.numberOfLeadingZeros(n);
			for (; x >= 0; x--) {
				ret = ret*ret % mod;
				if (n<<~x<0)ret = ret*a%mod;
			}
			return ret;
		}

		private static long invl(long a) {
			long b = mod;
			long p = 1, q = 0;
			while (b > 0) {
				long c = a / b;
				long d;
				d = a;
				a = b;
				b = d % b;
				d = p;
				p = q;
				q = d - c * q;
			}
			return p < 0 ? p + mod : p;
		}
	}


	public static long C(int n, int r, int mod, int[][] fif) {
		if (n < 0 || r < 0 || r > n) return 0;
		return (long) fif[0][n] * fif[1][r] % mod * fif[1][n - r] % mod;
	}

	public static int[][] enumFIF(int n, int mod) {
		int[] f = new int[n + 1];
		int[] invf = new int[n + 1];
		f[0] = 1;
		for (int i = 1; i <= n; i++) {
			f[i] = (int) ((long) f[i - 1] * i % mod);
		}
		long a = f[n];
		long b = mod;
		long p = 1, q = 0;
		while (b > 0) {
			long c = a / b;
			long d;
			d = a;
			a = b;
			b = d % b;
			d = p;
			p = q;
			q = d - c * q;
		}
		invf[n] = (int) (p < 0 ? p + mod : p);
		for (int i = n - 1; i >= 0; i--) {
			invf[i] = (int) ((long) invf[i + 1] * (i + 1) % mod);
		}
		return new int[][]{f, invf};
	}


	public static class DJSet {
		public int[] upper;

		public DJSet(int n) {
			upper = new int[n];
			Arrays.fill(upper, -1);
		}

		public int root(int x) {
			return upper[x] < 0 ? x : (upper[x] = root(upper[x]));
		}

		public boolean equiv(int x, int y) {
			return root(x) == root(y);
		}

		public boolean unite(int x, int y) {
			x = root(x);
			y = root(y);
			if (x != y) {
				if (upper[y] < upper[x]) {
					int d = x;
					x = y;
					y = d;
				}
				upper[x] += upper[y];
				upper[y] = x;
			}
			return x == y;
		}

		public int count() {
			int ct = 0;
			for (int u : upper) if (u < 0) ct++;
			return ct;
		}

		public int[][] toBucket() {
			int n = upper.length;
			int[][] ret = new int[n][];
			int[] rp = new int[n];
			for (int i = 0; i < n; i++) if (upper[i] < 0) ret[i] = new int[-upper[i]];
			for (int i = 0; i < n; i++) {
				int r = root(i);
				ret[r][rp[r]++] = i;
			}
			return ret;
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