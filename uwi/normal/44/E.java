//package school2;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class E {
	Scanner in;
	PrintWriter out;
//	String INPUT = "3 2 5 abrakadabra";
//	String INPUT = "5 2 3 abrakadabra";
//	String INPUT = "5 2 3 abrakadabr";
	String INPUT = "";
	
	void solve()
	{
		int k = ni();
		int a = ni();
		int b = ni();
		String s = in.next();
		
		if(s.length() > k * b || s.length() < k * a){
			out.println("No solution");
			return;
		}
		
		int len = s.length() / k;
		int mod = s.length() % k;
		int cur = 0;
		for(int i = 0;i < k;i++){
			int nex = cur + len + (i < mod ? 1 : 0);
			out.println(s.substring(cur, nex));
			cur = nex;
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
		new E().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}