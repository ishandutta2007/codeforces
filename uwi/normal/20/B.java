//package round20;


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
		double a = ni();
		int ai = (int)a;
		double b = ni();
		int bi = (int)b;
		double c = ni();
		int ci = (int)c;
		if(a != 0){
			double d = b * b - 4 * a * c;
			int di = bi * bi - 4 * ai * ci;
			if(di > 0){
				out.println(2);
				if(ai > 0){
					out.printf("%1.6f\n", (-b - Math.sqrt(d)) / (2 * a));
					out.printf("%1.6f\n", (-b + Math.sqrt(d)) / (2 * a));
				}else{
					out.printf("%1.6f\n", (-b + Math.sqrt(d)) / (2 * a));
					out.printf("%1.6f\n", (-b - Math.sqrt(d)) / (2 * a));
				}
			}else if(di == 0){
				out.println(1);
				out.printf("%1.6f\n", -b / (2 * a));
			}else{
				out.println(0);
			}
		}else if(b != 0){
			out.println(1);
			out.printf("%1.6f\n", -c / b);
		}else if(c != 0){
			out.println(0);
		}else{
			out.println(-1);
		}
	}
	
	public void run() throws Exception
	{
//		in = new Scanner(new StringReader("1 -5 6"));
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