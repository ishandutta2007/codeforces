//package round22;


import java.io.PrintWriter;
import java.io.StringReader;
import java.util.Arrays;
import java.util.Scanner;

public class B {
	private Scanner in;
	private PrintWriter out;
//	private String INPUT = "3 3 000 010 000";
//	private String INPUT = "3 3 000 000 000";
//	private String INPUT = "5 4 1100 0000 0000 0000 0000";
	private String INPUT = "";
	
	public void solve()
	{
		int n = ni();
		int m = ni();
		char[][] map = new char[n][m];
		for(int i = 0;i < n;i++){
			map[i] = in.next().toCharArray();
		}
		
		int max = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(map[i][j] == '0'){
					int lmax = Integer.MAX_VALUE;
					for(int k = 1;i + k - 1 < n && map[i+k-1][j] == '0';k++){
						int l;
						for(l = 1;j + l - 1 < m && map[i+k-1][j+l-1] == '0' && l <= lmax;l++);
						l--;
						int v = 2 * (k + l);
						if(v > max)max = v;
						lmax = l;
					}
				}
			}
		}
		
		out.println(max);
	}
	
	public void run() throws Exception
	{
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(new StringReader(INPUT));
		out = new PrintWriter(System.out);
		
		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new B().run();
	}
	
	private int ni() { return Integer.parseInt(in.next()); }
	private static void tr(Object... o) { System.out.println(o.length == 1 ? o[0] : Arrays.toString(o)); }
}