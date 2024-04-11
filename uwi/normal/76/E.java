//package ausoi;
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
		int[] x = new int[n];
		int[] y = new int[n];
		long sx = 0;
		long sy = 0;
		long sx2 = 0;
		long sy2 = 0;
		for(int i = 0;i < n;i++){
			x[i] = ni();
			y[i] = ni();
			sx += x[i];
			sy += y[i];
			sx2 += x[i]*x[i];
			sy2 += y[i]*y[i];
		}
		out.println(sx2*n-sx*sx+sy2*n-sy*sy);
		
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
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}