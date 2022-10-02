//package round6;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Scanner;

public class B {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int m = ni();
		char p = in.next().charAt(0);
		char[][] b = new char[n][m];
		for(int i = 0;i < n;i++)b[i] = in.next().toCharArray();
		BitSet bs = new BitSet();
		int[] dr = {-1,1,0,0};
		int[] dc = {0,0,1,-1};
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(b[i][j] == p){
					for(int k = 0;k < 4;k++){
						int nr = i+dr[k];
						int nc = j+dc[k];
						if(nr >= 0 && nr < n && nc >= 0 && nc < m){
							bs.set(b[nr][nc]);
						}
					}
				}
			}
		}
		bs.clear('.');
		bs.clear(p);
		out.println(bs.cardinality());
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
		new B().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}