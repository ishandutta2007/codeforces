//package round243;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E4F2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), K = ni();
		int mod = 1000000007;
		
		final int Bh = 60;
		final long BM = 1152921496L;
		final long mask = (1L<<31)-1;
		
		int[][] dp = new int[K+1][n+1];
		long[] twos = new long[n+1];
		twos[0] = 1;
		for(int i = 1;i <= n;i++){
			twos[i] = twos[i-1] * 2;
			if(twos[i] >= mod)twos[i] -= mod;
		}
		
		dp[0][0] = 1;
		long BIG = (long)mod<<32;
		for(int end = 1;end <= n;end++){
			for(int k = Math.min(K, end-1);k >= 0;k--){
				long lsum = 0;
				for(int l = 0;l <= end-1;l++){
					if(dp[k][l] != 0){
						lsum += dp[k][l] * (twos[end]-twos[l]+mod);
						if(lsum >= BIG)lsum -= BIG;
//						dp[k][l] = (int)(dp[k][l] * twos[l] % mod);
						long a = dp[k][l] * twos[l];
						long r = a-((BM*(a&mask)>>>31)+BM*(a>>>31)>>>Bh-31)*mod;
						dp[k][l] = (int)(r < mod ? r : r-mod);
					}
				}
				if(k+1 <= K)dp[k+1][end] = (int)(lsum % mod);
			}
		}
//		for(int i = 0;i <= K;i++){
//			tr(dp[i]);
//		}
		long ret = 0;
		for(int j = 0;j <= n;j++){
			ret += dp[K][j];
		}
		out.println(ret%mod);
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
	
	public static void main(String[] args) throws Exception { new E4F2().run(); }
	
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