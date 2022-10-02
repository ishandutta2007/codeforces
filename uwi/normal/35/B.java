//package round35;

import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {
	Scanner in;
	PrintWriter out;
//	String INPUT = "2 2 9 +1 1 1 c +1 1 1 f +1 1 1 s +1 1 1 w -1 c -1 f -1 s -1 w -1 c";
//	String INPUT = "2 2 8 +1 1 1 c -1 c +1 1 1 f -1 f +1 1 1 s -1 s +1 1 1 w -1 w";
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int m = ni();
		int k = ni();
		String[][] sh = new String[n][m];
		outer:
		for(int i = 0;i < k;i++){
			String com = in.next();
			if(com.equals("+1")){
				int x = ni() - 1;
				int y = ni() - 1;
				String name = in.next();
				int xx = x;
				int yy = y;
				for(;xx < n;xx++){
					for(;yy < m;yy++){
						if(sh[xx][yy] == null){
							sh[xx][yy] = name;
							continue outer;
						}
					}
					yy = 0;
				}
			}else{
				String q = in.next();
				for(int x = 0;x < n;x++){
					for(int y = 0;y < m;y++){
						if(sh[x][y] != null && q.equals(sh[x][y])){
							sh[x][y] = null;
							out.println((x+1) + " " + (y+1));
							continue outer;
						}
					}
				}
				out.println("-1 -1");
			}
		}
	}
	
	void run() throws Exception
	{
		in = INPUT.isEmpty() ? new Scanner(new File("input.txt")) : new Scanner(INPUT);
		out = INPUT.isEmpty() ? new PrintWriter("output.txt") : new PrintWriter(System.out);

		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new B().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
	static String join(int[] a, int d){StringBuilder sb = new StringBuilder();for(int v : a){sb.append(v + d + " ");}return sb.toString();}
}