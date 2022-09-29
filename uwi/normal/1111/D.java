//package round537;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class D3 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		char[] s = ns().toCharArray();
		int n = s.length;
		int[] f = new int[128];
		for(char c : s)f[c]++;
		
		int mod = 1000000007;
		int[][] fif = enumFIF(100005, mod);
		
		long[] dp = new long[n+1];
		dp[0] = 1;
		long all = 1;
		for(int i = 0;i < 128;i++){
			if(f[i] > 0){
				all = all * fif[1][f[i]] % mod;
				if(f[i] > n/2){
					all = 0;
				}
				for(int j = n;j >= f[i];j--){
					dp[j] += dp[j-f[i]];
					if(dp[j] >= mod)dp[j] -= mod;
				}
			}
		}
		long base = dp[n/2] * all % mod * fif[0][n/2] % mod * fif[0][n/2] % mod;
		
		long[][] anss = new long[128][128];
		
		for(int i = 0;i < 128;i++){
			if(f[i] > 0){
				for(int k = f[i];k <= n;k++){
					dp[k] -= dp[k-f[i]];
					if(dp[k] < 0)dp[k] += mod;
				}
				for(int j = i+1;j < 128;j++){
					if(f[j] > 0){
						if(f[i]+f[j] > n/2){
							continue;
						}
						for(int k = f[j];k <= n;k++){
							dp[k] -= dp[k-f[j]];
							if(dp[k] < 0)dp[k] += mod;
						}
						
//						anss[i][j] = anss[j][i] = 
//								dp[n/2] * 2 * all % mod * fif[0][n/2] % mod * fif[0][n/2-f[i]-f[j]] % mod
//								* fif[0][f[i]+f[j]] % mod;
								
						anss[i][j] = anss[j][i] = 
								dp[n/2] * 2 * all % mod * fif[0][n/2] % mod * fif[0][n/2] % mod;
								
						for(int k = n;k >= f[j];k--){
							dp[k] += dp[k-f[j]];
							if(dp[k] >= mod)dp[k] -= mod;
						}
					}
				}
				for(int k = n;k >= f[i];k--){
					dp[k] += dp[k-f[i]];
					if(dp[k] >= mod)dp[k] -= mod;
				}
			}
		}
		
		for(int Q = ni();Q > 0;Q--){
			int x = ni()-1, y = ni()-1;
			if(s[x] == s[y]){
				out.println(base);
			}else{
				int t0 = s[x], t1 = s[y];
				out.println(anss[t0][t1]);
			}
		}
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

	
	void run() throws Exception
	{
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new D3().run(); }
	
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