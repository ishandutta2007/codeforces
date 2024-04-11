//package round34;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class D {
	private Scanner in;
	private PrintWriter out;
//	private String INPUT = "3 2 3 2 2";
//	private String INPUT = "6 2 4 6 1 2 4 2";
//	private String INPUT = "5 5 1 2 3 4 5";
	private String INPUT = "";
	
	public void solve()
	{
		int n = ni();
		int r1 = ni() - 1;
		int r2 = ni() - 1;
		int[] p = new int[n];
		for(int i = 0;i < n-1;i++){
			p[i + (i >= r1 ? 1 : 0)] = ni() - 1;
		}
		p[r1] = -1;
		
		int[] h = new int[n + 1];
		int pp = 0;
		for(int i = r2;i != -1;i = p[i]){
			h[pp++] = i;
		}
		
		for(int i = pp-1;i >= 1;i--){
			p[h[i]] = h[i-1];
		}
		
		StringBuilder sb = new StringBuilder();
		for(int i = 0;i < n;i++){
			if(i != r2){
				sb.append((p[i]+1) + " ");
			}
		}
		out.println(sb.toString());
	}
	
	public void run() throws Exception
	{
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new D().run();
	}
	
	private int ni() { return Integer.parseInt(in.next()); }
	private void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}