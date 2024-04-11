//package round39;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

// ~24
public class B {
	Scanner in;
	PrintWriter out;
//	String INPUT = "3 3 1";
//	String INPUT = "3 3 2";
//	String INPUT = "1 1 1";
//	String INPUT = "3 4 1";
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int m = ni();
		int x = ni();
		if(n - 2 * (x - 1) <= 0 || m - 2 * (x - 1) <= 0){
			out.println(0);
			return;
		}
		if(n - 2 * (x - 1) == 1 && m - 2 * (x - 1) == 1){
			out.println(1);
			return;
		}
		
		if(n % 2 == 1 && m % 2 == 1){
			out.println(Math.max(0, (n - 2 * (x-1)) / 2 * 2 + (m - 2 * (x-1)) / 2 * 2));
		}else if(n % 2 == 0 && m % 2 == 0){
			out.println(Math.max(0, (n - 2 * (x-1)) / 2 * 2 + (m - 2 * (x-1)) / 2 * 2 - 2));
		}else{
			out.println(Math.max(0, (n - 2 * (x-1)) / 2 * 2 + (m - 2 * (x-1)) / 2 * 2 - 1));
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
		new B().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}