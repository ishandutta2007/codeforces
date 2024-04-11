//package round35;

import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class D {
	Scanner in;
	PrintWriter out;
//	String INPUT = "3 4 1 1 1";
//	String INPUT = "3 6 1 1 1";
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int x = ni();
		int[] c = new int[n];
		for(int i = 0;i < n;i++){
			c[i] = ni() * (n - i);
		}
		Arrays.sort(c);
		int p = 0;
		for(int i = 0;i < n;i++){
			if(x >= c[i]){
				x -= c[i];
				p++;
			}else{
				break;
			}
		}
		out.println(p);
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
		new D().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
	static String join(int[] a, int d){StringBuilder sb = new StringBuilder();for(int v : a){sb.append(v + d + " ");}return sb.toString();}
}