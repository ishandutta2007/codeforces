//package round85;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class C3 {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int m = ni();
		if(n < m){
			int d = n;n = m;m = d;
		}
		// n>=m
		if(m == 1){
			out.println(n-(n+2)/3);
			return;
		}
		
		int[][] dp = new int[n+1][1<<2*m];
		int[] fill = new int[1<<m];
		int mask = (1<<m)-1;
		for(int i = 0;i < 1<<m;i++){
			fill[i] = (i<<1|i|i>>1)&mask;
		}
		for(int i = 0;i < 1<<2*m;i++){
			int lower = i&mask;
			int upper = i>>m;
			dp[0][i] = (fill[lower]|upper) == mask ? Integer.bitCount(i) : 99999;
		}
		
		for(int i = 1;i <= n-2;i++){
			for(int j = 0;j < 1<<2*m;j++){
				int lower = j&mask;
				int upper = j>>m;
				
				int min = 99999;
				for(int k = 0;k < 1<<m;k++){
					if((upper|fill[lower]|k) == mask){
						min = Math.min(min, dp[i-1][lower<<m|k]);
					}
				}
				dp[i][j] = min + Integer.bitCount(upper);
			}
		}
		
		int gmin = 99999;
		for(int i = 0;i < 1<<2*m;i++){
			int lower = i&mask;
			int upper = i>>m;
			if((fill[upper]|lower) == mask){
				gmin = Math.min(gmin, dp[n-2][i]);
			}
		}
		out.println(n*m-gmin);
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
		new C3().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}