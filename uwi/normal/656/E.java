//package april2016;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class E {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[][] a = new int[n][n];
		read(0, 0, a);
	}
	
	void read(int r, int c, int[][] a)
	{
		try{
			int n = a.length;
			a[r][c] = ni();
			read(r+(c == n-1 ? 1 : 0), (c+1)%n, a);
		}catch(Exception e){
			dfs(0, 0, 0, a);
		}
	}
	
	void dfs(int k, int i, int j, int[][] a)
	{
		try{
			int n = a.length;
			a[i][j] = Math.min(a[i][j], a[i][k] + a[k][j]);
			dfs(k+(i == n-1 && j == n-1 ? 1 : 0), (i+(j == n-1 ? 1 : 0)) % n, (j+1)%n, a);
		}catch(Exception e){
			dfs2(0, 0, 0, a);
		}
	}
	
	void dfs2(int i, int j, int m, int[][] a)
	{
		try{
			int n = a.length;
			m = Math.max(m, a[i][j]);
			dfs2(i + (j == n-1 ? 1 : 0), (j+1)%n, m, a);
		}catch(Exception e){
			out.println(m);
		}
	}
	
	void run() throws Exception
	{
		in = oj ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		solve();
		out.flush();
	}
	
	public static void main(String[] args) throws Exception
	{
		new E().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { System.out.println(Arrays.deepToString(o)); }
}