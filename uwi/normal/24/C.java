//package round24;



import java.io.PrintWriter;
import java.io.StringReader;
import java.util.Arrays;
import java.util.Scanner;

public class C {
	private Scanner in;
	private PrintWriter out;
//	private String INPUT = "3 4 0 0 1 1 2 3 -5 3";
//	private String INPUT = "3 100000000000003 5 5 1000 1000 -1000 1000 3 100";
	private String INPUT = "";
	
	public void solve()
	{
		int n = ni();
		long j = in.nextLong();
		int jj = (int)(j % (2 * n));
		
		int mx = ni(), my = ni();
		int[] x = new int[n];
		int[] y = new int[n];
		for(int i = 0;i < n;i++){
			x[i] = ni();
			y[i] = ni();
		}
		
		for(int i = 0;i < jj;i++){
			mx = 2 * x[i%n] - mx;
			my = 2 * y[i%n] - my;
		}
		
		out.println(mx + " " + my);
	}
	
	public void run() throws Exception
	{
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(new StringReader(INPUT));
		out = new PrintWriter(System.out);
		
		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new C().run();
	}
	
	private int ni() { return Integer.parseInt(in.next()); }
	private static void tr(Object... o) { System.out.println(o.length == 1 ? o[0] : Arrays.toString(o)); }
}