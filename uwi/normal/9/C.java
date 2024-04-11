//package round9beta;


import java.io.BufferedOutputStream;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.io.StringReader;
import java.util.Arrays;
import java.util.Scanner;

public class C {
	private Scanner in;
	private PrintWriter out;
	
	public void solve()
	{
		long n = ni();
		long x;
		int d;
		for(x = 1, d = 1;x < n;x *= 10, d++);
		int r = 0;
		for(long u = x;n > 0;u /= 10, d--){
			if(u > n)continue;
			if(u * 2 <= n){
				r += (1 << d) - 1;
				break;
			}
			r += 1 << (d - 1);
			n -= u;
		}
		out.println(r);
	}
	
	public void run() throws Exception
	{
//		in = new Scanner(new StringReader("1000000000"));
		in = new Scanner(System.in);
		System.setOut(new PrintStream(new BufferedOutputStream(System.out)));
		out = new PrintWriter(System.out);
		
//		int n = in.nextInt();
		int n = 1;
		for(int i = 1;i <= n;i++){
			long t = System.currentTimeMillis();
			solve();
			out.flush();
//			System.err.printf("%04d/%04d %7d%n", i, n, System.currentTimeMillis() - t);
		}
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new C().run();
	}
	
	private int ni() { return Integer.parseInt(in.next()); }
	private static void tr(Object... o) { System.out.println(o.length == 1 ? o[0] : Arrays.toString(o)); }
	private void tra(int[] a) {System.out.println(Arrays.toString(a));}
	private void tra(int[][] a)
	{
		for(int[] e : a){
			System.out.println(Arrays.toString(e));
		}
	}
	
}