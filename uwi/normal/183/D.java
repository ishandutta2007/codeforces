//package croc.Final;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;

public class D2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		double[][] P = new double[n][m];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				P[i][j] = (double)ni() / 1000;
			}
		}
		
		Queue<double[]> q = new PriorityQueue<double[]>(m+1, new Comparator<double[]>(){
			public int compare(double[] a, double[] b){
				return -(int)Math.signum(a[1]- b[1]);
			}
		});
		
		dps = new double[m][n+1];
		for(int i = 0;i < m;i++){
			Arrays.fill(dps[i], 1);
		}
		
		for(int i = 0;i < m;i++){
			q.add(new double[]{i, calc(P, i)});
		}
		
		int[] ct = new int[m];
		double E = 0;
		for(int i = 0;i < n;i++){
			double[] d = q.poll();
			int ind = (int)d[0];
			ct[ind]++;
			E += d[1];
			d[1] = calc(P, ind);
			q.add(d);
		}
		out.printf("%.9f\n", E);
	}
	
	double[][] dps;
	
	// kTs
	double calc(double[][] P, int k)
	{
		int n = P.length;
		double[] dp = new double[n+1];
		for(int i = 1;i <= n;i++){
			dp[i] = dps[k][i-1] * P[i-1][k] + dp[i-1];
			dps[k][i] -= dp[i];
		}
		dps[k] = dp;
//		tr(dp);
		return dp[n];
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
		new D2().run();
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