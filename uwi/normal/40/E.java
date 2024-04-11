//package round39;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

// 1000x1000
// -1,1-1
public class E3 {
	Scanner in;
	PrintWriter out;
//	String INPUT = "2 2 0 100";
//	String INPUT = "2 2 2 1 1 -1 2 2 1 100";
//	String INPUT = "3 3 0 100";
//	String INPUT = "3 7 0 10000";
//	String INPUT = "2 4 3 1 1 1 2 2 1 1 2 -1 10000";
	String INPUT = "";
	
	long rec(int[][] v, int r, int c)
	{
		int n = v.length;
		int m = v[0].length;
		if(r == n){
			for(int i = 0;i < n;i++){
				int mul = 1;
				for(int j = 0;j < m;j++){
					mul *= v[i][j];
				}
				if(mul == 1)return 0;
			}
			for(int i = 0;i < m;i++){
				int mul = 1;
				for(int j = 0;j < n;j++){
					mul *= v[j][i];
				}
				if(mul == 1)return 0;
			}
			return 1;
		}else if(c == m){
			return rec(v, r+1, 0);
		}
		
		if(v[r][c] == 0){
			long sum = 0;
			for(int i = -1;i <= 1;i+=2){
				v[r][c] = i;
				sum += rec(v, r, c+1);
				v[r][c] = 0;
			}
			return sum;
		}else{
			return rec(v, r, c+1);
		}
	}
	
	void solve()
	{
		int n = ni();
		int m = ni();
		if((n ^ m) % 2 == 1){
			out.println(0);
			return;
		}
		
		boolean ch = false;
		if(n > m){
			ch = true;
			int d = n;n = m;m = d;
		}
		// n <= m
		
		int kk = ni();
		int[][] v = new int[n][m];
		for(int i = 0;i < kk;i++){
			int a = ni();
			int b = ni();
			if(ch){
				v[b-1][a-1] = ni();
			}else{
				v[a-1][b-1] = ni();
			}
		}
		for(int i = 0;i < m;i++){
			int mul = 1;
			for(int j = 0;j < n;j++){
				mul *= v[j][i];
			}
			if(mul == 1){
				out.println(0);
				return;
			}
		}
		
		int p = ni();
		
		if(n == 2){
			long[][] dp = new long[2][2];
			dp[0][0] = 1;
			long q;
			for(int i = 0;i < m;i++){
				if(v[0][i] == 1 || v[1][i] == -1){
					q = dp[0][0]; dp[0][0] = dp[0][1]; dp[0][1] = q;
					q = dp[1][0]; dp[1][0] = dp[1][1]; dp[1][1] = q;
					continue;
				}
				if(v[0][i] == -1 || v[1][i] == 1){
					q = dp[0][0]; dp[0][0] = dp[1][0]; dp[1][0] = q;
					q = dp[0][1]; dp[0][1] = dp[1][1]; dp[1][1] = q;
					continue;
				}
				long[][] ndp = new long[2][2];
				for(int j = 0;j < 2;j++){
					for(int k = 0;k < 2;k++){
						ndp[1-j][k] += dp[j][k];
						ndp[j][1-k] += dp[j][k];
					}
				}
				for(int j = 0;j < 2;j++){
					for(int k = 0;k < 2;k++){
						dp[j][k] = ndp[j][k] % p;
					}
				}
			}
			out.println(dp[1][1]);
			return;
		}
		
		if(n == 2 && m == 2){
			out.println(rec(v, 0, 0) % p);
			return;
		}
		
//		int e = (m - n) * (n - 1) + (n - 1) * (n - 1);
		int e = (m - 1) * (n - 1);
		long x = 1L;
		for(int i = 0;i < e - kk;i++){
			x = (x * 2) % p;
		}
		out.println(x);
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
		new E3().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}