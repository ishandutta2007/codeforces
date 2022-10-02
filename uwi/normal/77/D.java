//package round69;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class D {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int m = ni();
		char[][] carp = new char[4*n+1][4*m+1];
		for(int i = 0;i < 4*n+1;i++){
			carp[i] = in.next().toCharArray();
		}
		
		int[] lnum = new int[512];
		int[] lbh = new int[512];
		lnum[0] = 0; lbh[0] = 3;
		lnum[16] = 1; lbh[16] = 3;
		lnum[68] = 2; lbh[68] = 1;
		lnum[257] = 2; lbh[257] = 2;
		lnum[84] = 3; lbh[84] = 1;
		lnum[273] = 3; lbh[273] = 2;
		lnum[325] = 4; lbh[325] = 3;
		lnum[341] = 5; lbh[341] = 3;
		lnum[365] = 6; lbh[365] = 1;
		lnum[455] = 6; lbh[455] = 2;
		
		int[][] bh = new int[n][m];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				int code = 0;
				for(int k = 0;k < 3;k++){
					for(int l = 0;l < 3;l++){
						code = code * 2 + (carp[4*i+1+k][4*j+1+l] == 'O' ? 1 : 0);
					}
				}
				bh[i][j] = lbh[code];
			}
		}
		
		int MOD = 1000000007;
		long[] dp = new long[m+1];
		boolean[] okcol = new boolean[m];
		if(n % 2 == 0){
			for(int i = 0;i < m;i++){
				boolean f = true;
				for(int j = 0;j < n;j++){
					if((bh[j][i]&1) != 1){
						f = false;
						break;
					}
				}
				okcol[i] = f;
			}
		}
		
		if(m == 1){
			out.println(okcol[0] ? 1 : 0);
			return;
		}
		
		dp[0] = 1;
		for(int i = 0;i < m;i++){
			long v = 0;
			if(okcol[i])v = dp[i];
			
			if(i >= 1){
				long[] ldp = new long[n+1];
				ldp[0] = 1;
				for(int j = 0;j < n;j++){
					ldp[j+1] = (((bh[j][i-1]&2)==2 && (bh[j][i]&2)==2 ? ldp[j] : 0) +
					(j >= 1 && (bh[j][i-1]&1)==1 && (bh[j][i]&1)==1 && (bh[j-1][i-1]&1)==1 && (bh[j-1][i]&1)==1 ? ldp[j-1] : 0)) % MOD;
				}
				v += (dp[i-1] * (ldp[n] - (okcol[i] && okcol[i-1] ? 1 : 0))) % MOD;
			}
			dp[i+1] = v % MOD;
		}
		out.println(dp[m]);
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
	double nd() { return Double.parseDouble(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}