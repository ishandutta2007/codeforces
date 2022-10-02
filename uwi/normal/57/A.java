//package round53;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int x1 = ni();
		int y1 = ni();
		int x2 = ni();
		int y2 = ni();
		if(y1 == y2 && (y2 == 0 || y2 == n)){
			out.println(Math.abs(x2-x1));
		}else if(x1 == x2 && (x2 == 0 || x2 == n)){
			out.println(Math.abs(y2-y1));
		}else if((y1 == 0 && y2 == n) || (y1 == n && y2 == 0)){
			out.println(Math.min(x1 + n + x2, (n-x1)+n+(n-x2)));
		}else if((x1 == 0 && x2 == n) || (x1 == n && x2 == 0)){
			out.println(Math.min(y1 + n + y2, (n-y1)+n+(n-y2)));
		}else{
			out.println(Math.abs(x1-x2)+Math.abs(y1-y2));
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
		new A().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}