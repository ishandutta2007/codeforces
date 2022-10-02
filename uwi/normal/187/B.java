//package round119;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class B2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni(), r = ni();
		int[][][] g = new int[m][n][n];
		for(int i = 0;i < m;i++){
			for(int j = 0;j < n;j++){
				for(int k = 0;k < n;k++){
					g[i][j][k] = ni();
				}
			}
		}
		
		for(int u = 0;u < m;u++){
			for(int k = 0;k < n;k++){
				for(int i = 0;i < n;i++){
					for(int j = 0;j < n;j++){
						if(g[u][i][j] > g[u][i][k] + g[u][k][j]){
							g[u][i][j] = g[u][i][k] + g[u][k][j];
						}
					}
				}
			}
		}
		
		int[][] G = new int[n][n];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				G[i][j] = Integer.MAX_VALUE;
				for(int v = 0;v < m;v++){
					G[i][j] = Math.min(G[i][j], g[v][i][j]);
				}
			}
		}
		
		int[][][] dp = new int[n+1][n][n]; // [stroke][city][start]
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				dp[0][i][j] = Integer.MAX_VALUE / 2;
			}
			dp[0][i][i] = 0;
		}
		for(int i = 1;i <= n;i++){
			for(int j = 0;j < n;j++){
				for(int f = 0;f < n;f++){
					int min = Integer.MAX_VALUE;
					for(int l = 0;l < n;l++){
						min = Math.min(min, dp[i-1][l][f] + G[l][j]);
					}
					dp[i][j][f] = min;
				}
			}
		}
		
		for(int i = 0;i < r;i++){
			int s = ni()-1, t = ni()-1, k = ni();
			out.println(dp[Math.min(k+1, n)][t][s]);
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
	
	public static void main(String[] args) throws Exception
	{
		new B2().run();
	}
	
	public int ni()
	{
		try {
			int num = 0;
			boolean minus = false;
			while((num = is.read()) != -1 && !((num >= '0' && num <= '9') || num == '-'));
			if(num == '-'){
				num = 0;
				minus = true;
			}else{
				num -= '0';
			}
			
			while(true){
				int b = is.read();
				if(b >= '0' && b <= '9'){
					num = num * 10 + (b - '0');
				}else{
					return minus ? -num : num;
				}
			}
		} catch (IOException e) {
		}
		return -1;
	}
	
	public long nl()
	{
		try {
			long num = 0;
			boolean minus = false;
			while((num = is.read()) != -1 && !((num >= '0' && num <= '9') || num == '-'));
			if(num == '-'){
				num = 0;
				minus = true;
			}else{
				num -= '0';
			}
			
			while(true){
				int b = is.read();
				if(b >= '0' && b <= '9'){
					num = num * 10 + (b - '0');
				}else{
					return minus ? -num : num;
				}
			}
		} catch (IOException e) {
		}
		return -1;
	}
	
	public String ns()
	{
		try{
			int b = 0;
			StringBuilder sb = new StringBuilder();
			while((b = is.read()) != -1 && (b == '\r' || b == '\n' || b == ' '));
			if(b == -1)return "";
			sb.append((char)b);
			while(true){
				b = is.read();
				if(b == -1)return sb.toString();
				if(b == '\r' || b == '\n' || b == ' ')return sb.toString();
				sb.append((char)b);
			}
		} catch (IOException e) {
		}
		return "";
	}
	
	public char[] ns(int n)
	{
		char[] buf = new char[n];
		try{
			int b = 0, p = 0;
			while((b = is.read()) != -1 && (b == ' ' || b == '\r' || b == '\n'));
			if(b == -1)return null;
			buf[p++] = (char)b;
			while(p < n){
				b = is.read();
				if(b == -1 || b == ' ' || b == '\r' || b == '\n')break;
				buf[p++] = (char)b;
			}
			return Arrays.copyOf(buf, p);
		} catch (IOException e) {
		}
		return null;
	}
	
	
	double nd() { return Double.parseDouble(ns()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}