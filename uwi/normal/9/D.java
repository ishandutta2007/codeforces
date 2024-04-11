//package round9beta;


import java.io.BufferedOutputStream;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.io.StringReader;
import java.util.Arrays;
import java.util.Scanner;

public class D {
	private Scanner in;
	private PrintWriter out;
	
	public void solve()
	{
		int n = ni();
		int h = ni();
		
		cache = new long[n+1][n+1];
		
		long r = rec(n, n);
		r -= rec(n, h - 1);
		out.println(r);
	}
	
	private long[][] cache;
	
	private long rec(int n, int h)
	{
		if(n == 0)return 1;
		if(h == 0)return 0;
		if(cache[n][h] != 0)return cache[n][h];
		
		long ret = 0;
		for(int i = 0;i <= n - 1;i++){
			ret += rec(i, h - 1) * rec(n - 1 - i, h - 1);
		}
		
		cache[n][h] = ret;
//		tr(n, h, ret);
		return ret;
	}
	
	public void run() throws Exception
	{
//		in = new Scanner(new StringReader("3 3"));
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
		new D().run();
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