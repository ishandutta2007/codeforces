//package round52;

import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class D {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		char[] a = in.next().toCharArray();
		char[] b = in.next().toCharArray();
		int an = a.length;
		int bn = b.length;
		int[][] dp = new int[an+1][bn+1];
		char[][] hist = new char[an+1][bn+1];
		for(int i = 0;i <= an;i++){
			for(int j = 0;j <= bn;j++){
				if(i == 0){
					if(j == 0){
					}else{
						dp[i][j] = dp[i][j-1] + 1;
						hist[i][j] = 'B';
					}
				}else{
					if(j == 0){
						dp[i][j] = dp[i-1][j] + 1;
						hist[i][j] = 'A';
					}else{
						dp[i][j] = Math.min(Math.min(dp[i-1][j]+1, dp[i][j-1]+1), dp[i-1][j-1] + (a[i-1] == b[j-1] ? 0 : 1));
						hist[i][j] = ' ';
						if(dp[i][j] == dp[i-1][j-1]+1)hist[i][j] = 'R';
						if(dp[i][j] == dp[i-1][j]+1)hist[i][j] = 'A';
						if(dp[i][j] == dp[i][j-1]+1)hist[i][j] = 'B';
					}
				}
			}
		}
		
		int ii = an;
		int jj = bn;
		List<String> opes = new ArrayList<String>();
		while(!(ii == 0 && jj == 0)){
			if(hist[ii][jj] == 'R'){
				opes.add("REPLACE " + jj + " " + b[jj-1]);
				ii--; jj--;
			}else if(hist[ii][jj] == 'A'){
				opes.add("DELETE " + (jj+1));
				ii--;
			}else if(hist[ii][jj] == 'B'){
				opes.add("INSERT " + jj + " " + b[jj-1]);
				jj--;
			}else{
				ii--; jj--;
			}
		}
		out.println(opes.size());
		for(int i = opes.size() - 1;i >= 0;i--){
			out.println(opes.get(i));
		}
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
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}