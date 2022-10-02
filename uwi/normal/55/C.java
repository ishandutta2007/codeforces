//package round51;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class C {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int m = ni();
		int k = ni();
		if(k == 0){
			out.println("NO");
			return;
		}
		
		int mind = 99999999;
		for(int i = 0;i < k;i++){
			int r = ni() - 1;
			int c = ni() - 1;
			
			mind = Math.min(mind, Math.min(Math.min(r, n - 1 - r), Math.min(c, m - 1 - c)));
		}
		if(mind <= 4){
			out.println("YES");
		}else{
			out.println("NO");
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
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}