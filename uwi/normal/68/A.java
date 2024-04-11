//package round62;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A2 {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int p1 = ni();
		int p2 = ni();
		int p3 = ni();
		int p4 = ni();
		int a = ni();
		int b = ni();
		int min = Math.min(Math.min(Math.min(p1, p2), p3), p4)-1;
		out.println(Math.max(Math.min(b, min)-a+1, 0));
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
		new A2().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}