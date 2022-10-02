//package round9beta;


import java.io.BufferedOutputStream;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.io.StringReader;
import java.util.Arrays;
import java.util.Scanner;

public class A {
	private Scanner in;
	private PrintWriter out;
	
	public void solve()
	{
		int a = ni();
		int b = ni();
		int n = 6 - Math.max(a, b) + 1;
		int d = 6;
		int gcd;
		for(gcd = 6;gcd >= 1;gcd--){
			if(d % gcd == 0 && n % gcd == 0){
				break;
			}
		}
		n /= gcd;
		d /= gcd;
		
		out.println(n + "/" + d);
	}
	
	public void run() throws Exception
	{
//		in = new Scanner(new StringReader("6 6"));
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
		new A().run();
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