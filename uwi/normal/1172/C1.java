//package round564;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class C1 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[] a = na(n);
		int[] w = na(n);
		int mod = 998244353;
		int[] invs = enumInvs(10000, mod);
		int one = 0;
		for(int i = 0;i < n;i++)one += a[i] * w[i];
		int zero = 0;
		for(int i = 0;i < n;i++) {
			if(a[i] == 0)zero += w[i];
		}
		for(int i = 0;i < n;i++) {
			if(a[i] == 1) {
				long[][] dp = new long[m+5][105];
				int other = one - w[i];
				dp[0][w[i]] = 1;
				for(int j = 0;j < m;j++) {
					long[][] ndp = new long[m+5][105];
					for(int k = 0;k <= m+4;k++) {
						for(int l = 0;l < 105;l++) {
							if(dp[k][l] == 0)continue;
							int all = other + zero + k + l - (j-k-(l-w[i]));
							long base = dp[k][l] * invs[all] % mod;
							ndp[k][l+1] += base * l;
							ndp[k][l+1] %= mod;
							ndp[k+1][l] += base * (other + k);
							ndp[k+1][l] %= mod;
							ndp[k][l] += base * (zero-(j-k-(l-w[i])));
							ndp[k][l] %= mod;
						}
					}
					dp = ndp;
				}
				long E = 0;
				for(int k = 0;k <= m+4;k++) {
					for(int l = 0;l < 105;l++) {
						if(dp[k][l] == 0)continue;
						E += dp[k][l] * l;
						E %= mod;
					}
				}
				out.println(E);
			}else {
				long[][] dp = new long[m+5][105]; // down
				int other = zero - w[i];
				dp[0][w[i]] = 1;
				for(int j = 0;j < m;j++) {
					long[][] ndp = new long[m+5][105];
					for(int k = 0;k <= m+4;k++) {
						for(int l = 0;l < 105;l++) {
							if(dp[k][l] == 0)continue;
							int all = other + one - k + l + (j-k-(w[i]-l));
							long base = dp[k][l] * invs[all] % mod;
							if(l > 0) {
								ndp[k][l-1] += base * l;
								ndp[k][l-1] %= mod;
							}
							ndp[k+1][l] += base * (other - k);
							ndp[k+1][l] %= mod;
							ndp[k][l] += base * (one+(j-k-(w[i]-l)));
							ndp[k][l] %= mod;
						}
					}
					dp = ndp;
				}
				long E = 0;
				for(int k = 0;k <= m+4;k++) {
					for(int l = 0;l < 105;l++) {
						if(dp[k][l] == 0)continue;
						E += dp[k][l] * l;
						E %= mod;
					}
				}
				out.println(E);
			}
		}
	}
	
	public static int[] enumInvs(int n, int mod)
	{
		int[] inv = new int[n+1];
		inv[1] = 1;
		for(int i = 2;i <= n;i++){
			inv[i] = (int)(inv[mod%i]*(long)(mod-mod/i)%mod);
		}
		return inv;
	}

	
	void run() throws Exception
	{
//		int n = 50, m = 50;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(m + " ");
//		for (int i = 0; i < n; i++) {
//			sb.append(0 + " ");
//		}
//		for (int i = 0; i < n; i++) {
//			sb.append(50 + " ");
//		}
//		INPUT = sb.toString();

		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new C1().run(); }
	
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