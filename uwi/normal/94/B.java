//package round76;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Div2B {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		boolean[][] g = new boolean[5][5];
		int n = ni();
		for(int i = 0;i < n;i++){
			int a = ni() - 1;
			int b = ni() - 1;
			g[a][b] = g[b][a] = true;
		}
		for(int i = 0;i < 5;i++){
			for(int j = i+1;j < 5;j++){
				for(int k = j+1;k < 5;k++){
					if(g[i][j] && g[j][k] && g[k][i]){
						out.println("WIN");
						return;
					}
					if(!g[i][j] && !g[j][k] && !g[k][i]){
						out.println("WIN");
						return;
					}
				}
			}
		}
		out.println("FAIL");
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
		new Div2B().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}