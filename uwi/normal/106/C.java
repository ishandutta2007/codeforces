//package round82;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class C2 {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int m = ni();
		int c0 = ni();
		int d0 = ni();
		int[][] data = new int[m][4];
		for(int i = 0;i < m;i++){
			for(int j = 0;j < 4;j++){
				data[i][j] = ni();
			}
		}
		
		int[] dp = new int[n+1];
		Arrays.fill(dp, -9999999);
		dp[0] = 0;
		for(int i = c0;i <= n;i+=c0){
			dp[i] = dp[i-c0] + d0;
		}
		for(int i = 1;i <= m;i++){
			int f = data[i-1][0] / data[i-1][1];
			int c = data[i-1][2];
			int d = data[i-1][3];
			for(int k = 1;f > 0;k *= 2){
				int l = Math.min(k, f);
				for(int j = n;j-l*c >= 0;j--){
					dp[j] = Math.max(dp[j], dp[j-l*c]+l*d);
				}
				f -= l;
			}
		}
		
		int max = 0;
		for(int i = 0;i <= n;i++){
			max = Math.max(max, dp[i]);
		}
		out.println(max);
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
		new C2().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}