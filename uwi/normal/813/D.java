//package educational.round22;
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
		int n = ni();
		int[] a = na(n);
		int[][] dp = new int[n+1][n+1];
		for(int[] row : dp)Arrays.fill(row, -999999);
		
		int[][] g = makeBuckets(a, 100005);
		int[] b = new int[n];
		for(int i = 0;i < n;i++)b[i] = a[i] % 7;
		int[][] g7 = makeBuckets(b, 7);
		
		dp[0][0] = 0;
		int max = 0;
		
		int[] pg = new int[100006];
		int[] pg7 = new int[7];
		for(int mx = 0;mx <= n;mx++){
			if(mx > 0){
				pg[a[mx-1]]++;
				pg7[b[mx-1]]++;
			}
			
			for(int i = 0;i <= mx;i++){
				int j = mx;
				int w = Math.max(dp[i][j], dp[j][i]);
				if(i > 0 && j > 0)max = Math.max(max, w);
				dp[j][i] = dp[i][j] = w;
				
				if(i == 0){
					for(int k = j;k < n;k++){
						dp[k+1][j] = Math.max(dp[k+1][j], dp[0][j] + 1);
					}
				}else{
					for(int k = -1;k <= 1;k+=2){
						int[] row = g[a[i-1]+k];
						if(pg[a[i-1]+k] < row.length){
							int ind = pg[a[i-1]+k];
							ind = row[ind];
//							tr(i, j, ind+1, j, dp[i][j]+1);
							dp[ind+1][j] = Math.max(dp[ind+1][j], dp[i][j] + 1);
						}
					}
					{
						int[] row = g7[b[i-1]];
						if(pg7[b[i-1]] < row.length){
							int ind = pg7[b[i-1]];
							ind = row[ind];
//							tr(i, j, ind+1, j, dp[i][j]+1);
							dp[ind+1][j] = Math.max(dp[ind+1][j], dp[i][j] + 1);
						}
					}
				}
				if(j == 0){
					for(int k = i;k < n;k++){
						dp[i][k+1] = Math.max(dp[i][k+1], dp[i][0] + 1);
					}
				}else{
					for(int k = -1;k <= 1;k+=2){
						int[] row = g[a[j-1]+k];
						if(pg[a[j-1]+k] < row.length){
							int ind = pg[a[j-1]+k];
							ind = row[ind];
//							tr(i, j, i, ind+1, dp[i][j]+1);
							dp[i][ind+1] = Math.max(dp[i][ind+1], dp[i][j] + 1);
						}
					}
					{
						int[] row = g7[b[j-1]];
						if(pg7[b[j-1]] < row.length){
							int ind = pg7[b[j-1]];
							ind = row[ind];
//							tr(i, j, i, ind+1, dp[i][j]+1);
							dp[i][ind+1] = Math.max(dp[i][ind+1], dp[i][j] + 1);
						}
					}
				}
			}
		}
		out.println(max);
	}
	
	public static int[][] makeBuckets(int[] a, int sup)
	{
		int n = a.length;
		int[][] bucket = new int[sup+1][];
		int[] bp = new int[sup+1];
		for(int i = 0;i < n;i++)bp[a[i]]++;
		for(int i = 0;i <= sup;i++)bucket[i] = new int[bp[i]];
		for(int i = n-1;i >= 0;i--)bucket[a[i]][--bp[a[i]]] = i;
		return bucket;
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