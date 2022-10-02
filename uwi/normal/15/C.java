//package round15;


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
		long[] m = new long[n];
		long[] x = new long[n];
		long ns = 0L;
		for(int i = 0;i < n;i++){
			x[i] = in.nextLong();
			m[i] = in.nextLong();
			ns ^= nimsum(x[i] - 1);
			ns ^= nimsum(x[i] + m[i] - 1);
		}
		
		out.println(ns > 0 ? "tolik" : "bolik");
	}
	
	public long nimsum(long n)
	{
		long ret = 0;
		if((n & 3) == 1 || (n & 3) == 2)ret ^= 1;
		if((n & 1) == 0){
			ret ^= n;
		}
		return ret;
	}
	
	public boolean rec(long[] x)
	{
		for(int i = 0;i < x.length;i++){
			for(int j = 1;j <= x[i];j++){
				x[i] -= j;
				if(!rec(x)){
					x[i] += j;
					return true;
				}
				x[i] += j;
			}
		}
		return false;
	}
	
	public void run() throws Exception
	{
//		in = new Scanner(new StringReader("2 2 1 3 2"));
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
//		System.out.println(new C().nimsum(14));
		new C().run();
	}
	
	private int ni() { return Integer.parseInt(in.next()); }
	private static void tr(Object... o) { System.out.println(o.length == 1 ? o[0] : Arrays.toString(o)); }
}