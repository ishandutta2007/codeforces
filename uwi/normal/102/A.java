//package round79;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Div2A {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int m = ni();
		int[] pr = new int[n];
		for(int i = 0;i < n;i++)pr[i] = ni();
		
		boolean[][] g = new boolean[n][n];
		for(int i = 0;i < m;i++){
			int f = ni()-1;
			int t = ni()-1;
			g[f][t] = g[t][f] = true;
		}
		
		int min = 99999999;
		for(int i = 0;i < n;i++){
			for(int j = i+1;j < n;j++){
				if(g[i][j]){
					for(int k = j+1;k < n;k++){
						if(g[i][k] && g[j][k]){
							min = Math.min(min, pr[i] + pr[j] + pr[k]);
						}
					}
				}
			}
		}
		if(min == 99999999) min = -1;
		out.println(min);
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
		new Div2A().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}