//package round518;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class A2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] a = na(n);
		long[][] dp = new long[2][201];
		dp[0][0] = 1;
		int mod = 998244353;
		for(int i = 0;i < n;i++){
			long[][] ndp = new long[2][201];
			if(a[i] == -1){
				int s = 0;
				for(int k = 0;k <= 200;k++){
					s += dp[0][k];
					if(s >= mod)s -= mod;
					if(k > 0)ndp[0][k] += s;
				}
				for(int k = 1;k <= 200;k++){
					ndp[0][k] -= dp[0][k];
					if(ndp[0][k] < 0)ndp[0][k] += mod;
					ndp[1][k] += dp[0][k];
					if(ndp[1][k] >= mod)ndp[1][k] -= mod;
				}
				
				long z = 0, o = 0;
				for(int k = 0;k <= 200;k++){
					o += dp[1][k];
				}
				o -= dp[1][0]; z += dp[1][0];
				o %= mod;
				
				for(int k = 1;k <= 200;k++){
					ndp[0][k] += z;
					if(ndp[0][k] >= mod)ndp[0][k] -= mod;
					ndp[1][k] += o;
					if(ndp[1][k] >= mod)ndp[1][k] -= mod;
					
					z += dp[1][k]; o -= dp[1][k];
					if(o < 0)o += mod;
					if(z >= mod)z -= mod;
				}
			}else{
				for(int j = 0;j <= 200;j++){
					int k = a[i];
					if(j <= k){
						int nu = j==k?1:0;
						ndp[nu][k] += dp[0][j];
						if(ndp[nu][k] >= mod)ndp[nu][k] -= mod;
					}
					{
						int nu = j>=k?1:0;
						ndp[nu][k] += dp[1][j];
						if(ndp[nu][k] >= mod)ndp[nu][k] -= mod;
					}
				}
			}
			dp = ndp;
		}
		long ans = 0;
		for(int i = 1;i <= 200;i++){
			ans += dp[1][i];
		}
		out.println(ans%mod);
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
	
	public static void main(String[] args) throws Exception { new A2().run(); }
	
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