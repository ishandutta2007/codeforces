//package round15;


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
		int n = ni();
		int t = ni();
		Pair[] p = new Pair[n];
		for(int i = 0;i < n;i++){
			p[i] = new Pair();
			p[i].x = ni();
			p[i].a = ni();
		}
		Arrays.sort(p);
		
		int ct = 2;
		for(int i = 0;i < n - 1;i++){
			float d = p[i + 1].x - (float)p[i + 1].a / 2 - p[i].x - (float)p[i].a / 2;
			if(Math.abs(d - t) < EPS){
				ct++;
			}else if(d > t){
				ct += 2;
			}
		}
		
		out.println(ct);
	}

	double EPS = 0.0001;
	
	private static class Pair implements Comparable<Pair>
	{
		public int x;
		public int a;
		
		@Override
		public int compareTo(Pair o) {
			return x - o.x;
		}
	}	
	public void run() throws Exception
	{
//		in = new Scanner(new StringReader("2 3 0 4 5 2"));
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
}