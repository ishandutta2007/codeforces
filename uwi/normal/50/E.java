//package round47;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class E {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int m = ni();
		long all = 0;
		for(long b = 1;b <= n;b++){
			all += Math.min(2L * b * b - 1, 2L * m);
		}
		for(int t = 1;t <= 2*n+1;t++){
			int max = Math.min((int)(((double)m / t + t) / 2), n);
			int min = (int)(Math.ceil((1.0 / t + t) / 2));
			int ct = max - min + 1;
			if(ct >= 2){
				all -= ct - 1;
			}
		}
		out.println(all);
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