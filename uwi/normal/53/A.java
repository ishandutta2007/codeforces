//package round49;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		String s = in.next();
		int n = ni();
		String x = null;
		for(int i = 0;i < n;i++){
			String w = in.next();
			if(w.startsWith(s)){
				if(x == null || x.compareTo(w) > 0){
					x = w;
				}
			}
		}
		if(x == null){
			out.println(s);
		}else{
			out.println(x);
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
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}