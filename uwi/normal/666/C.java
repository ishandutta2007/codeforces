//package prac;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class C666 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int Z = 100005;
		int mod = 1000000007;
		
//		long[][] dp = new long[15][15];
//		dp[0][0] = 1;
//		for(int i = 1;i < 15;i++){
//			for(int j = 0;j <= i;j++){
//				dp[i][j] += dp[i-1][j] * 25;
//				if(j-1 >= 0)dp[i][j] += dp[i-1][j-1];
//			}
//			for(int j = 0;j <= i;j++)dp[i][j] %= mod;
////			tr(dp[i]);
//		}
		
		int[][] fif = enumFIF(Z, mod);
		int Q = ni();
		int n = ns().length()-1;
		int S = (int)Math.sqrt(Z);
		long[][] cs = new long[Z/S+1][];
		long[] px = new long[Z+1];
		px[0] = 1;
		for(int i = 1;i <= Z;i++){
			px[i] = px[i-1] * 25 % mod;
		}
		long[] py = new long[Z+1];
		py[0] = 1;
		for(int i = 1;i <= Z;i++){
			py[i] = py[i-1] * 26 % mod;
		}
		for(int i = 0, j = 0;i < Z/S+1 && j < Z;i++,j+=S){
			cs[i] = new long[j+1];
			for(int k = 0;k <= j;k++){
				cs[i][k] = px[j-k] * C(j, k, mod, fif) % mod;
			}
			for(int k = 1;k <= j;k++){
				cs[i][k] += cs[i][k-1];
				if(cs[i][k] >= mod)cs[i][k] -= mod;
			}
		}
		
		
		long[][] f = new long[S][S+5];
		Arrays.fill(f[0], 1);
		for(int i = 1;i < S;i++){
			for(int j = 0;j < S+5;j++){
				if(j-1 >= 0)f[i][j] += f[i-1][j-1] * 1;
				f[i][j] += f[i-1][j] * 25;
			}
			for(int j = 0;j < S+5;j++){
				f[i][j] %= mod;
			}
//			tr(f[i]);
		}
		
		for(int z = 0;z < Q;z++){
			int t = ni();
			if(t == 1){
				n = ns().length()-1;
			}else{
				int x = ni();
				if(x < n){
					out.println(0);
					continue;
				}
//				tr("go", x, n);
				// (x,n)
				int u = x/S;
				long base = n-(x-u*S) >= 0 ? cs[u][n-(x-u*S)] * py[x-u*S] % mod : 0;
//				tr("base", base);
//				tr(f[x-u*S]);
				for(int i = 0;i < x-u*S;i++){
					// (u*S,n-i) = (u*S
					if(n-i <= u*S && n-i >= 0){
//						tr("e", i, u*S-(n-i), u*S, n-i, f[x-u*S][i], px[u*S-(n-i)] * C(u*S, n-i, mod, fif));
						base += px[u*S-(n-i)] * C(u*S, n-i, mod, fif) % mod * f[x-u*S][i];
						base %= mod;
					}
				}
//				tr("BA", base, pow(26, x, mod));
				base = py[x] - base;
				if(base < 0)base += mod;
				out.println(base);
			}
		}
	}
	
	public static long pow(long a, long n, long mod) {
		//		a %= mod;
		long ret = 1;
		int x = 63 - Long.numberOfLeadingZeros(n);
		for (; x >= 0; x--) {
			ret = ret * ret % mod;
			if (n << 63 - x < 0)
				ret = ret * a % mod;
		}
		return ret;
	}

	
	public static long C(int n, int r, int mod, int[][] fif) {
		if (n < 0 || r < 0 || r > n)
			return 0;
		return (long) fif[0][n] * fif[1][r] % mod * fif[1][n - r] % mod;
	}

	
	long[] bin(int n, int a, int b, int[][] fif, int mod)
	{
		long[] ret = new long[n+1];
		for(int i = 0;i <= n;i++){
			ret[i] = (long)fif[0][n]*fif[1][i]%mod*fif[1][n-i]%mod;
		}
		long bb = 1;
		for(int i = 0;i < n;i++){
			ret[i] = ret[i] * bb % mod;
			bb = bb * b % mod;
		}
		long aa = 1;
		for(int i = n-1;i >= 0;i--){
			ret[i] = ret[i] * aa % mod;
			aa = aa * a % mod;
		}
		return ret;
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
		return new int[][] { f, invf };
	}

	
	public static boolean inc(int[] a, int base) {
		int n = a.length;
		int i;
		for (i = n - 1; i >= 0 && a[i] == base - 1; i--)
			;
		if (i == -1)
			return false;

		a[i]++;
		Arrays.fill(a, i + 1, n, 0);
		return true;
	}

	
	void run() throws Exception
	{
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new C666().run(); }
	
	private byte[] inbuf = new byte[1024];
	private int lenbuf = 0, ptrbuf = 0;
	
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
	
	private char[][] nm(int n, int m)
	{
		char[][] map = new char[n][];
		for(int i = 0;i < n;i++)map[i] = ns(m);
		return map;
	}
	
	private int[] na(int n)
	{
		int[] a = new int[n];
		for(int i = 0;i < n;i++)a[i] = ni();
		return a;
	}
	
	private int ni()
	{
		int num = 0, b;
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
	
	private boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	private void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}