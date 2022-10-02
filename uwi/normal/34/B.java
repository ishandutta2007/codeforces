//package round34;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {
	private Scanner in;
	private PrintWriter out;
//	private String INPUT = "5 3 -6 0 35 -2 4";
//	private String INPUT = "4 2 7 0 0 -7";
	private String INPUT = "";
	
	public void solve()
	{
		int n = ni();
		int m = ni();
		int[] p = new int[n];
		for(int i = 0;i < n;i++)p[i] = ni();
		Arrays.sort(p);
		int sum = 0;
		for(int i = 0;i < n && i < m && p[i] < 0;i++){
			sum -= p[i];
		}
		out.println(sum);
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
		new B().run();
	}
	
	private int ni() { return Integer.parseInt(in.next()); }
	private void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}