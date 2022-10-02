//package round40;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class E3 {
	Scanner in;
	PrintWriter out;
//	String INPUT = "1";
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		out.println((n/2) * (n-n/2));
		for(int i = 0;i < n / 2;i++){
			for(int j = n / 2;j < n;j++){
				out.println((i+1) + " " + (j+1));
			}
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
		new E3().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}