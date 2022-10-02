//package round39;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int x = ni();
		int y = ni();
		int sq = (int)Math.sqrt(x * x + y * y);
		if(sq * sq == x * x + y * y){
			out.println("black");
			return;
		}
		if(x * y > 0){
			out.println(sq % 2 == 0 ? "black" : "white");
		}else{
			out.println(sq % 2 == 0 ? "white" : "black");
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
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}