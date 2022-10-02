//package manthan;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


public class C {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		long ins = ni();
		long del = ni();
		long rep = ni();
		long exc = ni();
		char[] a = in.next().toCharArray();
		char[] b = in.next().toCharArray();
		int n = a.length;
		int m = b.length;
		long[][] dp = new long[n+1][m+1];
		for(int j = 1;j <= m;j++){
			dp[0][j] = dp[0][j-1] + ins;
		}
		for(int i = 1;i <= n;i++){
			dp[i][0] = dp[i-1][0] + del;
		}
		int[] prea = new int[256];
		Arrays.fill(prea, -1);
		
		for(int i = 1;i <= n;i++){
			int[] preb = new int[256];
			Arrays.fill(preb, -1);
			for(int j = 1;j <= m;j++){
				long min = Long.MAX_VALUE;
				min = Math.min(min, dp[i-1][j-1] + (a[i-1] == b[j-1] ? 0 : rep));
				min = Math.min(min, dp[i][j-1] + ins);
				min = Math.min(min, dp[i-1][j] + del);
				
				if(prea[b[j-1]] != -1 && preb[a[i-1]] != -1){
					min = Math.min(min, dp[prea[b[j-1]]][preb[a[i-1]]] + (i-2-prea[b[j-1]])*del+(j-2-preb[a[i-1]])*ins+exc);
				}
				dp[i][j] = min;
				preb[b[j-1]] = j-1;
			}
			prea[a[i-1]] = i-1;
		}
		
		out.println(dp[n][m]);
	}
	
	void run() throws Exception
	{
//		int n = 4000;
//		StringBuilder sb = new StringBuilder("4000 97 99 100 98 ");
//		Random r = new Random();
//		for(int i = 0;i < n;i++){
//			sb.append((char)(r.nextInt('z'-'a')+'a'));
//		}
//		sb.append('\n');
//		for(int i = 0;i < n;i++){
//			sb.append((char)(r.nextInt('z'-'a')+'a'));
//		}
//		sb.append('\n');
//		INPUT = sb.toString();
		
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