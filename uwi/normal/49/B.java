//package round46;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int a = ni();
		int b = ni();
		int max = 0;
		for(int i = a;i > 0;i /= 10){
			max = Math.max(max, i % 10);
		}
		for(int i = b;i > 0;i /= 10){
			max = Math.max(max, i % 10);
		}
		max++;
		
		int d = 0;
		int l = 0;
		for(int i = a, j = b;i > 0 || j > 0 || d > 0;i /= 10, j /= 10, l++){
			d = d / max + (i % 10) + (j % 10);
		}
		out.println(l - 1);
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