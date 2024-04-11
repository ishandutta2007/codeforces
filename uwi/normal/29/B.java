//package round29;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {
	private Scanner in;
	private PrintWriter out;
//	private String INPUT = "2 1 3 4 5";
//	private String INPUT = "5 3 3 1 1";
	private String INPUT = "";
	
	public void solve()
	{
		int l = ni();
		int d = ni();
		int v = ni();
		int g = ni();
		int r = ni();
		
		int grv = (g + r) * v;
		int t = 0;
		if(d % grv >= g * v){
			t += grv - (d % grv);
		}
		out.println((double)(t + l) / v);
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
		new B().run();
	}
	
	private int ni() { return Integer.parseInt(in.next()); }
	private void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}