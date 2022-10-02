//package round74;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Div2B {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int m = ni();
		char[][] b = new char[n][m];
		for(int i = 0;i < n;i++){
			b[i] = in.next().toCharArray();
		}
		
		boolean[][] dead = new boolean[n][m];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				for(int k = 0;k < n;k++){
					if(i != k && b[i][j] == b[k][j]){
						dead[i][j] = dead[k][j] = true;
					}
				}
				for(int k = 0;k < m;k++){
					if(j != k && b[i][j] == b[i][k]){
						dead[i][j] = dead[i][k] = true;
					}
				}
			}
		}
		
		StringBuilder sb = new StringBuilder();
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(!dead[i][j]){
					sb.append(b[i][j]);
				}
			}
		}
		out.println(sb);
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