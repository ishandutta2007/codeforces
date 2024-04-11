//package round564;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class C3 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		// m*f/(n+m)
		int n = ni(), m = ni();
		int[] a = na(n);
		int[] w = na(n);
		int mod = 998244353;
		int one = 0;
		for(int i = 0;i < n;i++)one += a[i] * w[i];
		int zero = 0;
		for(int i = 0;i < n;i++) {
			if(a[i] == 0)zero += w[i];
		}
		if(one == 0 && zero <= m) {
			for(int i = 0;i < n;i++) {
				out.println(0);
			}
			return;
		}
		
		long[] dp = new long[m+1];
		dp[0] = 1;
		for(int j = 0;j < m;j++) {
			long[] ndp = new long[m+1];
			for(int k = 0;k <= m;k++) {
				if(dp[k] == 0)continue;
				// up: k, down: j-k, 
				// one+k, zero-(j-k)
				long im = invl(one+k+zero-(j-k), mod);
				ndp[k+1] += dp[k] * (one+k) % mod * im;
				ndp[k+1] %= mod;
				ndp[k] += dp[k] * (zero-(j-k)) % mod * im;
				ndp[k] %= mod;
			}
			dp = ndp;
		}
		
		long base1 = 0;
		for(int f = 0;f <= m;f++) {
			base1 += f*dp[f];
			base1 %= mod;
		}
		base1 = base1 * invl(one, mod) % mod;
		long base0 = 0;
		for(int f = 0;f <= m;f++) {
			base0 += f*dp[m-f];
			base0 %= mod;
		}
		base0 = base0 * invl(zero, mod) % mod;
		
		
		for(int i = 0;i < n;i++) {
			if(a[i] == 1) {
				long ans = (w[i] + w[i] * base1) % mod;
				out.println(ans);
			}else {
				long ans = (w[i] - w[i] * base0 + (long)mod*mod) % mod;
				out.println(ans);
			}
		}
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
	
	public static void main(String[] args) throws Exception { new C3().run(); }
	
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