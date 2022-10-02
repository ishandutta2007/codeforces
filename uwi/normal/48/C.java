//package round45;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class C {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	double EPS = 1E-9;
	
	void solve()
	{
		int n = ni();
		double min = 10;
		double max = Integer.MAX_VALUE;
		for(int i = 0;i < n;i++){
			int l = ni();
			min = Math.max(min, (double)(10 * l) / (i + 1));
			max = Math.min(max, (double)(10 * l + 10) / (i + 1));
		}
		if(min >= max){
			out.println("not unique");
			return;
		}
		
		double sup = (n + 1) * max / 10 - EPS;
		double inf = (n + 1) * min / 10 - 1 + EPS;
		if(inf > sup){
			out.println("not unique");
			return;
		}
		
		if(Math.ceil(inf) == Math.floor(sup)){
			out.println("unique");
			out.println((int)Math.floor(sup));
		}else{
			out.println("not unique");
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
		new C().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}