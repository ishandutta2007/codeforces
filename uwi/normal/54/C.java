//package round50;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class C {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	long count(long x)
	{
		if(x == 1000000000000000000L)return count(200000000000000000L)+1;
		
		long M = 100000000000000000L;
		long ct = 0;
		for(;M > 0;M/=10){
			if(M <= x && x < M * 10){
				ct += Math.min(M, x - M + 1);
			}else if(M <= x){
				ct += M;
			}
		}
		return ct;
	}
	
	void solve()
	{
		int n = ni();
		double[] p = new double[n];
		for(int i = 0;i < n;i++){
			long l = in.nextLong();
			long r = in.nextLong();
			long ct = count(r) - count(l - 1);
			p[i] = (double)ct / (r - l + 1);
		}
		int K = ni();
		int inf = n * K / 100;
		if((n * K) % 100 != 0)inf++;
		
		double[][] dp = new double[n+1][n+1];
		dp[0][0] = 1;
		for(int i = 1;i <= n;i++){
			for(int j = 0;j <= n;j++){
				dp[i][j] = dp[i-1][j] * (1.0 - p[i-1]) + (j >= 1 ? dp[i-1][j-1] * p[i-1] : 0);
			}
		}
		
		double sum = 0;
		for(int i = inf;i <= n;i++){
			sum += dp[n][i];
		}
		out.println(sum);
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
		new C().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}