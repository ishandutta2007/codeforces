//package round89;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class D3 {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n1 = ni(), n2 = ni(), k1 = ni(), k2 = ni();
		int mod = 100000000;
		int[][][] dp = new int[n1+1][n2+1][2];
		dp[0][1][1] = 1;
		dp[1][0][0] = 1;
		int[][] rowsum = new int[n1+1][n2+1];
		int[][] colsum = new int[n1+1][n2+1];
		for(int i = 1;i <= n2;i++){
			colsum[0][i] = 1;
		}
		for(int i = 1;i <= n1;i++){
			rowsum[i][0] = 1;
		}
		for(int i = 1;i <= n1;i++){
			for(int j = 1;j <= n2;j++){
				dp[i][j][0] = (colsum[i-1][j]-colsum[i-1][Math.max(j-k2,0)]+mod)%mod;
//				for(int k = 1;k <= k2;k++){
//					if(j-(k-1) >= 0)dp[i][j][0] += dp[i-1][j-(k-1)][1];
//				}
//				dp[i][j][0] %= mod;
				
				dp[i][j][1] = (rowsum[i][j-1]-rowsum[Math.max(i-k1,0)][j-1]+mod)%mod;
//				for(int k = 1;k <= k1;k++){
//					if(i-(k-1) >= 0)dp[i][j][1] += dp[i-(k-1)][j-1][0];
//				}
//				dp[i][j][1] %= mod;
				
				colsum[i][j] = (colsum[i][j-1] + dp[i][j][1]) % mod;
				rowsum[i][j] = (rowsum[i-1][j] + dp[i][j][0]) % mod;
			}
		}
		
		long sum = 0;
		for(int i = 1;i <= k1 && n1-(i-1) >= 0;i++){
			sum += dp[n1-(i-1)][n2][0];
		}
		for(int i = 1;i <= k2 && n2-(i-1) >= 0;i++){
			sum += dp[n1][n2-(i-1)][1];
		}
		out.println(sum % mod);
	}
	
	void run() throws Exception
	{
		in = oj ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception
	{
		new D3().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}