//package round87;
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
		char[][] b = new char[n][];
		for(int i = 0;i < n;i++){
			b[i] = in.next().toCharArray();
		}
		int ct = 0;
		int[] dr = {1, 0, -1, 0};
		int[] dc = {0, 1, 0, -1};
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(b[i][j] == 'W'){
					for(int k = 0;k < 4;k++){
						int nr = i + dr[k];
						int nc = j + dc[k];
						if(nr >= 0 && nr < n && nc >= 0 && nc < m && b[nr][nc] == 'P'){
							ct++;
							break;
						}
					}
				}
			}
		}
		out.println(ct);
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