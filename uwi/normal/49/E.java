//package round46;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class E {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	void solve()
	{
		String a = in.next();
		String b = in.next();
		int n = ni();
		String[] to = new String[n];
		char[] from = new char[n];
		int[] im = new int[26*26];
		for(int i = 0;i < n;i++){
			String line = in.next();
			from[i] = line.charAt(0);
			to[i] = line.substring(3);
			int tc = (to[i].charAt(0) - 'a') * 26 + (to[i].charAt(1) - 'a');
			im[tc] |= 1<<(from[i]-'a');
		}
		int[][] fa = compact(a, im);
		int[][] fb = compact(b, im);
		
		int[][] dp = new int[a.length() + 1][b.length() + 1];
		for(int i = 1;i <= a.length();i++){
			dp[i][0] = 999999;
		}
		for(int j = 1;j <= b.length();j++){
			dp[0][j] = 999999;
		}
		for(int i = 1;i <= a.length();i++){
			for(int j = 1;j <= b.length();j++){
				int min = 999999;
				for(int k = 0;k < i;k++){
					for(int l = 0;l < j;l++){
						if((fa[i-k][k] & fb[j-l][l]) != 0){
							min = Math.min(min, dp[k][l] + 1);
						}
					}
				}
				dp[i][j] = min;
			}
		}
		if(dp[a.length()][b.length()] >= 999999){
			out.println(-1);
		}else{
			out.println(dp[a.length()][b.length()]);
		}
	}
	
	int[][] compact(String a, int[] im)
	{
		int al = a.length();
		int[][] ff = new int[al+1][al+1];
		for(int i = 0;i < a.length();i++){
			ff[1][i] = 1 << (a.charAt(i) - 'a');
		}
		for(int i = 2;i <= a.length();i++){
			for(int j = 0;j + i <= a.length();j++){
				// j ~ j + i - 1
				int code = 0;
				for(int k = j;k < j + i - 1;k++){
					for(int l = 0;l < 26;l++){
						if((ff[k-j+1][j] >> l) % 2 == 1){
							for(int m = 0;m < 26;m++){
								if((ff[(j+i-1)-(k+1)+1][k+1] >> m) % 2 == 1){
									code |= im[l * 26 + m];
								}
							}
						}
					}
				}
				ff[i][j] = code;
			}
		}
		return ff;
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
		new E().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}