//package round35;

import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A {
	Scanner in;
	PrintWriter out;
//	String INPUT = "1 1 2 2 1 2 1";
//	String INPUT = "1 2 1 3 1 1 3";
	String INPUT = "";
	
	void solve()
	{
		int f = ni();
		for(int i = 0;i < 3;i++){
			int a = ni();
			int b = ni();
			if(f == a){
				f = b;
			}else if(f == b){
				f = a;
			}
		}
		out.println(f);
	}
	
	void run() throws Exception
	{
		in = INPUT.isEmpty() ? new Scanner(new File("input.txt")) : new Scanner(INPUT);
		out = INPUT.isEmpty() ? new PrintWriter("output.txt") : new PrintWriter(System.out);

		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new A().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
	static String join(int[] a, int d){StringBuilder sb = new StringBuilder();for(int v : a){sb.append(v + d + " ");}return sb.toString();}
}