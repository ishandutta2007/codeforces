//package round32;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class C {
	private Scanner in;
	private PrintWriter out;
//	private String INPUT = "2 3 1000000";
//	private String INPUT = "3 3 2";
//	private String INPUT = "5 5 3";
	private String INPUT = "";
	
	public void solve()
	{
		long n = ni();
		long m = ni();
		long s = ni();
		
		long nn = n % s != 0 ? (n % s) * (n / s + 1) : n;
		long mm = m % s != 0 ? (m % s) * (m / s + 1) : m;
		
		out.println(nn * mm);
	}
	
	public void run() throws Exception
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
	
	private int ni() { return Integer.parseInt(in.next()); }
	private void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}