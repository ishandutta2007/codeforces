//package round40;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class D {
	Scanner in;
	PrintWriter out;
//	String INPUT = "3 3 1 123 456 789";
//	String INPUT = "3 3 0 123 456 789";
//	String INPUT = "3 3 0 321 456 789";
//	String INPUT = "2 2 10 98 75";
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int m = ni();
		int k = ni();
		char[][] b = new char[n][m];
		for(int i = 0;i < n;i++){
			b[i] = in.next().toCharArray();
		}
		
		int[][][] dp = new int[n][m][k+1];
		char[][][] prev = new char[n][m][k+1];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				Arrays.fill(dp[i][j], -1);
			}
		}
		for(int j = 0;j < m;j++){
			dp[n-1][j][(b[n-1][j] - '0') % (k+1)] = b[n-1][j] - '0';
		}
		
		for(int i = n - 1;i >= 1;i--){
			for(int j = 0;j < m;j++){
				for(int l = 0;l < k + 1;l++){
					if(dp[i][j][l] >= 0){
						if(j >= 1){
							if(dp[i-1][j-1][(l+b[i-1][j-1]-'0') % (k+1)] < dp[i][j][l] + b[i-1][j-1]-'0'){
								dp[i-1][j-1][(l+b[i-1][j-1]-'0') % (k+1)] = dp[i][j][l] + b[i-1][j-1]-'0';
								prev[i-1][j-1][(l+b[i-1][j-1]-'0') % (k+1)] = 'L';
							}
						}
						if(j < m - 1){
							if(dp[i-1][j+1][(l+b[i-1][j+1]-'0') % (k+1)] < dp[i][j][l] + b[i-1][j+1]-'0'){
								dp[i-1][j+1][(l+b[i-1][j+1]-'0') % (k+1)] = dp[i][j][l] + b[i-1][j+1]-'0';
								prev[i-1][j+1][(l+b[i-1][j+1]-'0') % (k+1)] = 'R';
							}
						}
					}
				}
			}
		}
		
		int max = -1;
		int maxj = -1;
		for(int j = 0;j < m;j++){
			if(dp[0][j][0] > max){
				max = dp[0][j][0];
				maxj = j;
			}
		}
		
		if(max == -1){
			out.println(-1);
			return;
		}else{
			out.println(max);
		}
		StringBuilder hist = new StringBuilder();
		int l = 0;
		int curj = maxj;
		for(int i = 0;i < n - 1;i++){
			hist.append(prev[i][curj][l]);
			int v = b[i][curj]-'0';
			if(prev[i][curj][l] == 'R'){
				curj--;
			}else{
				curj++;
			}
			l = ((k+1)*10 + l - v) % (k+1);
		}
		out.println(curj+1);
		out.println(hist.reverse());
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