//package round66;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class C {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		String s = in.next();
		int k = ni();
		int n = ni();
		
		int[][] c = new int[26][26];
		for(int i = 0;i < n;i++){
			char x = in.next().charAt(0);
			char y = in.next().charAt(0);
			int cc = ni();
			c[x-'a'][y-'a'] = cc;
		}
		
		int q = s.length();
		int[][][] dp = new int[q][26][k+1]; // [pos][prev][change]
		for(int j = 0;j < 26;j++){
			Arrays.fill(dp[0][j], -99999999);
			if(('a'+j) == s.charAt(0)){
				dp[0][j][0] = 0;
			}else{
				if(k > 0){
					dp[0][j][1] = 0;
				}
			}
		}
		for(int i = 1;i < q;i++){
			for(int j = 0;j < 26;j++){
				for(int l = 0;l <= k;l++){
					int max = -99999999;
					int ch = l - (('a'+j) == s.charAt(i) ? 0 : 1);
					for(int u = 0;u < 26;u++){
						if(ch >= 0){
							max = Math.max(max, dp[i-1][u][ch] + c[u][j]);
						}
					}
					dp[i][j][l] = max;
				}
			}
		}
		
		int max = Integer.MIN_VALUE;
		for(int j = 0;j < 26;j++){
			for(int l = 0;l <= k;l++){
				max = Math.max(max, dp[q-1][j][l]);
			}
		}
		out.println(max);
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