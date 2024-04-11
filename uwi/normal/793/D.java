//package tinkoff2017.e;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), K = ni();
		int m = ni();
		int[][] es = new int[m][];
		for(int i = 0;i < m;i++){
			es[i] = new int[]{ni()-1, ni()-1,  ni()};
		}
		int[][] g = new int[n][n];
		int I = 999999999;
		for(int i = 0;i < n;i++){
			Arrays.fill(g[i], I);
		}
		for(int[] e : es){
			g[e[0]][e[1]] = Math.min(g[e[0]][e[1]], e[2]);
		}
		
		// [l,r,side,k]
		int[][][][] dp = new int[n][n][2][K+1];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				for(int k = 0;k < 2;k++){
					Arrays.fill(dp[i][j][k], I);
				}
			}
		}
		int mincost = I;
		for(int len = 1;len <= n;len++){
			for(int i = 0;i+len-1 < n;i++){
				int j = i+len-1;
				if(len == 1){
					dp[i][j][0][1] = 0;
					dp[i][j][1][1] = 0;
				}else{
					for(int u = 2;u <= K;u++){
						int min = I;
						min = Math.min(min, dp[i][j-1][0][u]);
						for(int k = i+1;k <= j;k++){
							min = Math.min(min, dp[i+1][k][1][u-1] + g[i][k]);
							min = Math.min(min, dp[k][j][0][u-1] + g[i][k]);
						}
						dp[i][j][0][u] = min;
					}
					for(int u = 2;u <= K;u++){
						int min = I;
						min = Math.min(min, dp[i+1][j][1][u]);
						for(int k = i;k <= j-1;k++){
							min = Math.min(min, dp[i][k][1][u-1] + g[j][k]);
							min = Math.min(min, dp[k][j-1][0][u-1] + g[j][k]);
						}
						dp[i][j][1][u] = min;
					}
				}
				mincost = Math.min(mincost, dp[i][j][0][K]);
				mincost = Math.min(mincost, dp[i][j][1][K]);
			}
		}
		if(mincost >= I){
			out.println(-1);
		}else{
			out.println(mincost);
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
	
	public static void main(String[] args) throws Exception { new D().run(); }
	
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