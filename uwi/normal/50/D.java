//package round47;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class D {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int k = ni();
		double eps = (double)ni() / 1000;
		int x0 = ni();
		int y0 = ni();
		double[] d = new double[n];
		for(int i = 0;i < n;i++){
			int x = ni() - x0;
			int y = ni() - y0;
			d[i] = x * x + y * y;
		}
		
		double inf = 0;
		double sup = 3000;
		double[] p = new double[n];
		while(sup - inf > 1E-8){
			double r = (inf + sup) / 2;
			
			for(int i = 0;i < n;i++){
				p[i] = d[i] <= r * r ? 1.0 : Math.exp(1.0 - d[i] / (r * r));
			}
			
			double[][] dp = new double[n+1][k];
			dp[0][0] = 1.0;
			for(int i = 1;i <= n;i++){
				dp[i][0] = dp[i-1][0] * (1.0 - p[i-1]);
				for(int j = 1;j < k;j++){
					dp[i][j] = dp[i-1][j] * (1.0 - p[i-1]) + dp[i-1][j-1] * p[i-1];
				}
			}
			
			double fp = 0;
			for(int i = 0;i < k;i++){
				fp += dp[n][i];
			}
			if(fp > eps){
				inf = r;
			}else{
				sup = r;
			}
		}
		out.println(inf);
	}
	
	void run() throws Exception
	{
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new D().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}