//package round10;


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
		int n = ni();
		long r = 0;
		for(int i = 1;i <= n;i++){
			r += n / i;
		}
		
		
		long[] ct = new long[10];
		for(int i = 1;i <= 9;i++){
			ct[i] = n/9 + (i <= n % 9 ? 1 : 0);
		}
		
		long all = 0;
		for(int a = 1;a <= 9;a++){
			for(int b = 1;b <= 9;b++){
				all += ct[a] * ct[b] * ct[d(a*b)];
//				tr(a, b, d(a*b), all);
			}
		}
		out.println(all - r);
	}
	
	private int d(int a)
	{
		int m = a%9;
		return m == 0 ? 9 : m;
	}
	
	public void run() throws Exception
	{
//		in = new Scanner(new StringReader("9"));
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