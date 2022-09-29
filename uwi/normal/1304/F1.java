//package round620;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;
import java.util.InputMismatchException;

public class F2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni(), K = ni();
		int[][] a = new int[n][];
		for(int i = 0;i < n;i++){
			a[i] = na(m);
		}
		
		long[][] cum = new long[n][m+1];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				cum[i][j+1] = cum[i][j] + a[i][j];
			}
		}
		
		long[][] rcum = new long[n][m+1];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				rcum[i][j+1] = rcum[i][j] + a[i][m-1-j];
			}
		}
		
		long[] dp = new long[m-K+1];
		for(int i = 0;i < m-K+1;i++){
			dp[i] = cum[0][i+K] - cum[0][i];
		}
		for(int i = 1;i < n;i++){
			dp = trans(dp, cum[i], rcum[i] ,K);
		}
		long ans = 0;
		for(long v : dp){
			ans = Math.max(ans, v);
		}
		out.println(ans);
	}
	
	long[] trans(long[] dp, long[] cum, long[] rcum, int K)
	{
		int n = cum.length-1;
		for(int i = 0;i < n-K+1;i++){
			dp[i] += cum[i+K] - cum[i];
		}
//		tr(dp, cum, rcum);
		
		long[] ndp = new long[n-K+1];
		Arrays.fill(ndp, Long.MIN_VALUE / 2);
		
		// 2321
		// 000346
		
		go(ndp, dp, cum, K);
		
		rev_(ndp);
		rev_(dp);
		go(ndp, dp, rcum, K);
		
		rev_(ndp);
//		tr(ndp);
		return ndp;
	}
	
	public static long[] rev_(long[] a)
	{
		for(int i = 0, j = a.length-1;i < j;i++,j--){
			long c = a[i]; a[i] = a[j]; a[j] = c;
		}
		return a;
	}
	

	
	void go(long[] ndp, long[] dp, long[] cum, int K)
	{
		int n = cum.length-1;
		long flatmax = Long.MIN_VALUE / 2;
		Deque<long[]> nonflat = new ArrayDeque<>();
		for(int i = 0;i < n-K+1;i++){
			while(!nonflat.isEmpty() && nonflat.peekLast()[1] < dp[i]-cum[i+K]){
				nonflat.pollLast();
			}
			nonflat.add(new long[]{i, dp[i]-cum[i+K]});
			while(!nonflat.isEmpty() && nonflat.peekFirst()[0] < i-K){
				nonflat.pollFirst();
			}
			
			if(i-K >= 0){
				flatmax = Math.max(flatmax, dp[i-K]);
			}
//			tr(flatmax, nonflat.peekFirst());
			
			ndp[i] = Math.max(ndp[i], flatmax + cum[i+K] - cum[i]);
			if(!nonflat.isEmpty()){
				ndp[i] = Math.max(ndp[i], nonflat.peekFirst()[1] + cum[i] + cum[i+K] - cum[i]);
			}
		}
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