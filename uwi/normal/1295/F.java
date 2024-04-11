//package educational.round81;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class F {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	// 1/2 1/2
	//     1/2 1/2
	//      1
	
	void solve()
	{
		int n = ni();
		int[] A = new int[n];
		int[] B = new int[n];
		int mod = 998244353;
		for(int i = 0;i < n;i++){
			A[n-1-i] = ni();
			B[n-1-i] = ni();
		}
		int[] xs = new int[2*n+1];
		int min = Integer.MAX_VALUE;
		for(int i = 0;i < n;i++){
			xs[i] = A[i];
			min = Math.min(min, A[i]);
			xs[i+n] = B[i]+1;
		}
		xs[2*n] = min-1;
		Arrays.sort(xs);
		xs = uniq(xs);
		int m = xs.length;
		
		long[][] dp = new long[m-1][n+1];
		dp[0][0] = 1;
		
		long[][] ss = powerSumPolynomial(n+1, mod);
		long den = 1;
		
		for(int i = 0;i < n;i++){
			int a = A[i];
			int b = B[i];
			den = den * (b-a+1) % mod;
			long[][] ndp = new long[m-1][n+1];
			long P = 0;
			for(int j = 0;j < m-1;j++){
				long[] po = new long[n+1];
				for(int k = 0;k <= n;k++){
					if(dp[j][k] == 0)continue;
					for(int l = 0;l <= k+1;l++){
						po[l] += dp[j][k] * ss[k][l];
						po[l] %= mod;
					}
				}
				po[0] += P;
				po[0] %= mod;
				if(a <= xs[j] && xs[j] <= b){
					System.arraycopy(po, 0, ndp[j], 0, n+1);
				}
				
				P = f(po, xs[j+1] - xs[j], mod);
			}
			dp = ndp;
		}
		long P = 0;
		for(int j = 0;j < m-1;j++){
			long[] po = new long[n+1];
			for(int k = 0;k <= n;k++){
				if(dp[j][k] == 0)continue;
				for(int l = 0;l <= k+1;l++){
					po[l] += dp[j][k] * ss[k][l];
					po[l] %= mod;
				}
			}
			po[0] += P;
			po[0] %= mod;
			
			P = f(po, xs[j+1] - xs[j], mod);
		}
		out.println(P%mod*invl(den, mod)%mod);
	}
	
	long f(long[] po, int x, int mod)
	{
		long v = 0;
		for(int i = po.length-1;i >= 0;i--){
			v = v * x + po[i];
			v %= mod;
		}
		return v;
	}
	
	public static long[][] powerSumPolynomial(int K, long mod)
	{
		final long BIG = 8L*mod*mod;
		int[][] C = new int[K+3][K+3];
		for(int i = 0;i <= K+2;i++){
			C[i][0] = mod == 1 ? 0 : 1;
			for(int j = 1;j <= i;j++){
				C[i][j] = C[i-1][j]+C[i-1][j-1];
				if(C[i][j] >= mod)C[i][j] -= mod;
			}
		}
		
		long[][] dp = new long[K+1][K+2];
		dp[0][1] = 1;
		for(int i = 1;i <= K;i++){
			for(int j = i+1;j >= 1;j--){
				dp[i][j] = C[i+1][j];
			}
			for(int j = 0;j <= i-1;j++){
				for(int l = 0;l <= j+1;l++){
					dp[i][l] -= dp[j][l]*C[i+1][j];
					if(dp[i][l] < -BIG)dp[i][i] += BIG;
				}
			}
			long iv = invl(i+1, mod);
			for(int j = 0;j <= i+1;j++){
				dp[i][j] = dp[i][j] % mod * iv % mod;
				if(dp[i][j] < 0)dp[i][j] += mod;
			}
		}
		return dp;
	}
	
	public static int[] uniq(int[] a)
	{
		int n = a.length;
		int p = 0;
		for(int i = 0;i < n;i++) {
			if(i == 0 || a[i] != a[i-1])a[p++] = a[i];
		}
		return Arrays.copyOf(a, p);
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
	
	public static long invl(long a, long mod) {
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