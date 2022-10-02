//package school2;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {
	Scanner in;
	PrintWriter out;
//	String INPUT = "10000 5000 5000 5000";
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int a = ni();
		int b = ni();
		int c = ni();
		
		int[] dp = new int[2*n+1];
		dp[0] = 1;
		int[] dpa = new int[2*n+1];
		for(int i = 0;i <= 2 * n;i++){
			for(int j = 0;j <= a && i + j <= 2 * n;j++){
				dpa[i + j] += dp[i];
			}
		}
		int[] dpb = new int[2*n+1];
		for(int i = 0;i <= 2 * n;i++){
			for(int j = 0;j <= b && i + 2 * j <= 2 * n;j++){
				dpb[i + 2 * j] += dpa[i];
			}
		}
		int[] dpc = new int[2*n+1];
		for(int i = 0;i <= 2 * n;i++){
			for(int j = 0;j <= c && i + 4 * j <= 2 * n;j++){
				dpc[i + 4 * j] += dpb[i];
			}
		}
		
		out.println(dpc[2*n]);
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
		new B().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}