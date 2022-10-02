//package round100;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni(), P = ni();
		int Q = 5000;
		int[] a = na(n);
		
		long[] U = new long[Q+1];
		U[0] = 1;
		for(int i = 1;i <= Q;i++){
			U[i] = U[i-1] * (m-i+1) % P;
		}
		long[] F = new long[Q+1];
		F[0] = 1;
		for(int i = 1;i <= Q;i++){
			F[i] = F[i-1] * i % P;
		}
		
		int[][] dp = new int[Q+1][Q+1];
		dp[0][0] = 1;
		for(int i = 1;i <= Q;i++){
			for(int j = 1;j <= i;j++){
//				dp[i][j] = (int)(((long)dp[i-1][j] * j + (long)dp[i-1][j-1] * (m-(j-1))) % P);
				dp[i][j] = (int)(((long)dp[i-1][j] * (j-1) + (long)dp[i-1][j-1]) % P);
			}
		}
		// mCk
		// q=d*mCk
		// d*d*mCk*k!*k!
		
		int prev = 0;
		long[] pre = new long[Q+1];
		long[] cur = new long[Q+1];
		pre[0] = 1;
		for(int i = 0;i < n;i++){
			long all = 0;
			for(int j = 0;j <= prev;j++){
				all += pre[j];
			}
			all %= P;
			
			for(int j = 0;j <= a[i];j++){
//				ng += (long)pre[j] * dp[a[i]][j] % P * F[j] % P * U[j] % P;
//				cur[j] = all * dp[a[i]][j] % P * U[j] % P;
//				if(j <= prev){
//					cur[j] = (cur[j] + P - pre[j] * dp[a[i]][j] % P * F[j] % P) % P;
//				}
				
				if(j <= prev){
					cur[j] = (all * dp[a[i]][j] % P * U[j] - pre[j] * dp[a[i]][j] % P * F[j]) % P;
					if(cur[j] < 0)cur[j] += P;
				}else{
					cur[j] = all * dp[a[i]][j] % P * U[j] % P;
				}
			}
			long[] dum = pre; pre = cur; cur = dum;
			prev = a[i];
		}
		long ret = 0;
		for(int j = 0;j <= prev;j++){
			ret += pre[j];
		}
		out.println(ret % P);
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
	
	public static void main(String[] args) throws Exception { new E().run(); }
	
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