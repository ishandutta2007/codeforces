//package school2;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class C {
	Scanner in;
	PrintWriter out;
//	String INPUT = "10 5 1 2 2 3 4 5 7 8 9 10";
//	String INPUT = "10 5 1 2 3 3 4 6 7 7 8 10";
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int m = ni();
		int[] h = new int[n];
		for(int i = 0;i < m;i++){
			int a = ni() - 1;
			int b = ni() - 1;
			for(int j = a;j <= b;j++){
				h[j]++;
			}
		}
		for(int i = 0;i < n;i++){
			if(h[i] != 1){
				out.println((i+1) + " " + h[i]);
				return;
			}
		}
		out.println("OK");
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