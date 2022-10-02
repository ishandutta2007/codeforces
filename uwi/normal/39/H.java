//package school1;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class H {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		for(int i = 0;i < n - 1;i++){
			for(int j = 0;j < n - 1;j++){
				int v = (i+1)*(j+1);
				out.print(Integer.toString(v, n) + " ");
			}
			out.println();
		}
	}
	
	void run() throws Exception
	{
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new H().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}