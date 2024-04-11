//package round60;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int a = ni();
		int b = ni();
		int c = ni();
		int d = ni();
		int e = ni();
		int f = ni();
		if((long)f*b*d > (long)e*a*c || (c == 0 && d > 0) || (a == 0 && b > 0 && d > 0)){
			out.println("Ron");
		}else{
			out.println("Hermione");
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