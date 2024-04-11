//package round69;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class D2B {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		String line = in.next();
		double h = Integer.parseInt(line.substring(0, 2));
		double m = Integer.parseInt(line.substring(3));
		h %= 12;
		out.println((h/12*360+m/60/12*360) + " " + (m/60*360));
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
		new D2B().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}