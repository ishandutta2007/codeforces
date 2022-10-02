//package round61;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class D2 {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		if(n == 2){
			out.println(-1);
			return;
		}
		out.println(6);
		out.println(10);
		for(int i = 0;i < n-2;i++){
			out.println(15*(i+1));
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
		new D2().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}