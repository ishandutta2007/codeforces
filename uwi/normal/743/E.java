//package round384;
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
		int n = ni();
		int[] a = na(n);
		for(int i = 0;i < n;i++){
			a[i]--;
		}
		int K = 8;
		
		int[][] reach = new int[n][n+1];
		for(int i = 0;i < n;i++)Arrays.fill(reach[i], n);
		for(int i = n-1;i >= 0;i--){
			for(int j = i+1;j < n;j++){
				if(a[j] == a[i]){
					for(int k = 1;k < n;k++){
						reach[i][k+1] = reach[j][k];
					}
					break;
				}
			}
			reach[i][1] = i;
		}
		
		int max = 0;
		for(int base = 1;base*K <= n;base++){
			int[][] dp = new int[n+1][1<<K];
			for(int i = 1;i < 1<<K;i++){
				for(int j = 0;j <= n;j++)dp[j][i] = Integer.MIN_VALUE / 10;
			}
			for(int i = n-1;i >= 0;i--){
				for(int j = 0;j < 1<<K;j++){
					dp[i][j] = dp[i+1][j];
				}
				{
					int r = reach[i][base];
					if(r < n){
						for(int j = 0;j < 1<<K;j++){
							if(j<<~a[i]>=0){
								dp[i][j|1<<a[i]] = Math.max(dp[i][j|1<<a[i]], dp[r+1][j] + base);
							}
						}
					}
				}
				{
					int r = reach[i][base+1];
					if(r < n){
						for(int j = 0;j < 1<<K;j++){
							if(j<<~a[i]>=0){
								dp[i][j|1<<a[i]] = Math.max(dp[i][j|1<<a[i]], dp[r+1][j] + base+1);
							}
						}
					}
				}
			}
			max = Math.max(max, dp[0][(1<<K)-1]);
		}
		
		max = Math.max(max, (int)Arrays.stream(a).distinct().count());
		
		out.println(max);
	}
	
	void run() throws Exception
	{
//		int n = 1000, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		for (int i = 0; i < n; i++) {
//			sb.append(gen.nextInt(8)+1 + " ");
//		}
//		INPUT = sb.toString();

		
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