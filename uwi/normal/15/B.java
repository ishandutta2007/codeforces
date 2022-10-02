//package round15;


import java.io.BufferedOutputStream;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.io.StringReader;
import java.util.Arrays;
import java.util.Scanner;

public class B {
	private Scanner in;
	private PrintWriter out;
	
	public void solve()
	{
		long n = in.nextLong();
		long m = in.nextLong();
		long x1 = in.nextLong();
		long y1 = in.nextLong();
		long x2 = in.nextLong();
		long y2 = in.nextLong();
		
		long dx = Math.abs(x1 - x2);
		long dy = Math.abs(y1 - y2);
		long mx = n - 2 * dx;
		long my = m - 2 * dy;
		
		long s = n * m - 2 * (n - dx) * (m - dy) + ((mx > 0 && my > 0) ? mx * my : 0);
		
		out.println(s);
	}
	
	public void run() throws Exception
	{
//		in = new Scanner(new StringReader("4 4 1 1 3 3"));
//		in = new Scanner(new StringReader("4 3 1 1 4 3"));
		in = new Scanner(System.in);
		System.setOut(new PrintStream(new BufferedOutputStream(System.out)));
		out = new PrintWriter(System.out);
		
		int n = in.nextInt();
//		int n = 1;
		for(int i = 1;i <= n;i++){
			long t = System.currentTimeMillis();
			solve();
			out.flush();
//			System.err.printf("%04d/%04d %7d%n", i, n, System.currentTimeMillis() - t);
		}
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new B().run();
	}
	
	private int ni() { return Integer.parseInt(in.next()); }
	private static void tr(Object... o) { System.out.println(o.length == 1 ? o[0] : Arrays.toString(o)); }
}