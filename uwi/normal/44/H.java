//package school2;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class H {
	Scanner in;
	PrintWriter out;
//	String INPUT = "13579135791357913579135791357913579135791357913579";
//	String INPUT = "12345";
	String INPUT = "";
	
	void solve()
	{
		char[] phone = in.next().toCharArray();
		int n = phone.length;
		long[][] dp = new long[50][10];
		Arrays.fill(dp[0], 1);
		for(int i = 1;i < n;i++){
			for(int j = 0;j < 10;j++){
				int sum = (j+phone[i]-'0');
				if(sum % 2 == 0){
					dp[i][sum/2] += dp[i-1][j];
				}else{
					dp[i][sum/2] += dp[i-1][j];
					dp[i][sum/2+1] += dp[i-1][j];
				}
			}
		}
		
		long gsum = 0;
		int r;
		for(r = 1;r < n;r++){
			int n2 = (phone[r-1] - '0') + (phone[r] - '0');
			if(n2 % 2 == 0){
				if(n2 / 2 != phone[r] - '0'){
					break;
				}
			}else{
				if(n2 / 2 != phone[r] - '0' && n2 / 2 + 1 != phone[r] - '0'){
					break;
				}
			}
		}
		if(r == n){
			gsum = -1;
		}
		
		for(int i = 0;i < 10;i++){
			gsum += dp[n-1][i];
		}
		out.println(gsum);
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
		new H().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}