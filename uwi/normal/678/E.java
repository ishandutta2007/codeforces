//package educational.round13;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E3 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		n = ni();
		ps = new double[n][n];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				ps[i][j] = nd();
			}
		}
		if(n == 1){
			out.println("1.0000");
			return;
		}
		dp = new double[1<<n-1][n-1];
		for(int i = 0;i < 1<<n-1;i++){
			Arrays.fill(dp[i], Double.NaN);
		}
		double ret = 0;
		for(int k = 0;k < n-1;k++){
			dfs(1<<k, k);
			ret = Math.max(ret, dp[1<<k][k]);
		}
		out.printf("%.14f\n", ret);
	}
	
	int n;
	double[][] dp;
	double[][] ps;
	
	void dfs(int ptn, int k)
	{
		if(!Double.isNaN(dp[ptn][k]))return;
		if(ptn + 1 == 1<<n-1){
			dp[ptn][k] = ps[0][k+1];
			return;
		}
		double max = 0;
		for(int i = 0;i < n-1;i++){
			if(ptn<<~i>=0){
				dfs(ptn|1<<i, k);
				dfs(ptn|1<<i, i);
				double p = dp[ptn|1<<i][k] * ps[k+1][i+1] + dp[ptn|1<<i][i] * ps[i+1][k+1];
				max = Math.max(max, p);
			}
		}
		dp[ptn][k] = max;
	}
	
	void run() throws Exception
	{
//		int n = 18, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		double[][] a = new double[n][n];
//		for(int i =0;i < n;i++){
//			for(int j = i+1;j < n;j++){
//				a[i][j] = gen.nextDouble();
//				a[j][i] = 1-a[i][j];
//			}
//		}
//		for (int i = 0; i < n; i++) {
//			for(int j = 0;j < n;j++){
//				sb.append(a[i][j] + " ");
//			}
//		}
//		INPUT = sb.toString();

		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new E3().run(); }
	
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