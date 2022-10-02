//package round38;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A {
	Scanner in;
	PrintWriter out;
//	String INPUT = "3 5 6 1 3";
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] d = new int[n];
		for(int i = 0;i < n - 1;i++){
			d[i] = ni();
		}
		int a = ni();
		int b = ni();
		
		int sum = 0;
		for(int i = a - 1;i < b - 1;i++){
			sum += d[i];
		}
		out.println(sum);
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