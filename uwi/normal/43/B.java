//package round42;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		char[] a = in.nextLine().toCharArray();
		char[] b = in.nextLine().toCharArray();
		
		int[] ct = new int[256];
		for(char c : a){
			ct[c]++;
		}
		for(char d : b){
			if(d == ' ')continue;
			ct[d]--;
			if(ct[d] < 0){
				out.println("NO");
				return;
			}
		}
		out.println("YES");
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