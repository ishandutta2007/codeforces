//package round130;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[][] g = new int[n][n];
		for(int i = 0;i < n;i++){
			Arrays.fill(g[i], 999);
			g[i][i] = 0;
		}
		for(int i = 0;i < m;i++){
			int f = ni()-1, t = ni()-1;
			g[f][t] = g[t][f] = 1;
		}
		
		for(int k = 0;k < n;k++){
			for(int i = 0;i < n;i++){
				for(int j = 0;j < n;j++){
					if(g[i][j] > g[i][k] + g[k][j]){
						g[i][j] = g[i][k] + g[k][j];
					}
				}
			}
		}
		
		double[] dp = new double[n];
		{
			dp[n-1] = 1;
			Queue<Integer> q = new ArrayDeque<Integer>();
			q.add(n-1);
			boolean[] ved = new boolean[n];
			ved[n-1] = true;
			while(!q.isEmpty()){
				int cur = q.poll();
				for(int i = 0;i < n;i++){
					if(g[cur][i] == 1 && g[cur][n-1] + 1 == g[i][n-1]){
						dp[i] += dp[cur];
						if(!ved[i]){
							ved[i] = true;
							q.add(i);
						}
					}
				}
			}
		}
		double[] dp2 = new double[n];
		{
			dp2[0] = 1;
			Queue<Integer> q = new ArrayDeque<Integer>();
			q.add(0);
			boolean[] ved = new boolean[n];
			ved[0] = true;
			while(!q.isEmpty()){
				int cur = q.poll();
				for(int i = 0;i < n;i++){
					if(g[cur][i] == 1 && g[cur][0] + 1 == g[i][0]){
						dp2[i] += dp2[cur];
						if(!ved[i]){
							ved[i] = true;
							q.add(i);
						}
					}
				}
			}
		}
		
		double all = dp2[n-1];
		
		double max = 1.;
		for(int i = 1;i < n-1;i++){
			if(g[0][i] + g[i][n-1] == g[0][n-1]){
				max = Math.max(max, dp[i]*dp2[i]*2 / all);
			}
		}
		out.printf("%.9f\n", max);
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
		new C().run();
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