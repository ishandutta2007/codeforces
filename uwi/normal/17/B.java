//package round17;


import java.io.BufferedOutputStream;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.io.StringReader;
import java.util.Arrays;
import java.util.Scanner;

public class B {
	private Scanner in;
	private PrintWriter out;
	
	int[][] r;
	int n;
	
	public void solve()
	{
		n = ni();
		int[] q = new int[n];
		for(int i = 0;i < n;i++)q[i] = ni();
		Pair[] ps = new Pair[n];
		for(int i = 0;i < n;i++){
			ps[i] = new Pair();
			ps[i].a = q[i];
			ps[i].b = i;
		}
		Arrays.sort(ps);
		
		int m = ni();
		int[] a = new int[m];
		int[] b = new int[m];
		int[] c = new int[m];
		r = new int[n][n];
		for(int i = 0;i < m;i++){
			a[i] = ni();
			b[i] = ni();
			c[i] = ni();
			if(r[a[i] - 1][b[i] - 1] > 0){
				r[a[i] - 1][b[i] - 1] = Math.min(r[a[i] - 1][b[i] - 1], c[i] + 1);
			}else{
				r[a[i] - 1][b[i] - 1] = c[i] + 1;
			}
		}
		
		int cost = 0;
		for(int i = 1;i < n;i++){
			// oyasagasi
			int min = Integer.MAX_VALUE;
			for(int j = 0;j < i;j++){
				if(r[ps[j].b][ps[i].b] > 0 && r[ps[j].b][ps[i].b] < min){
					min = r[ps[j].b][ps[i].b];
				}
			}
			if(min == Integer.MAX_VALUE){
				out.println(-1);
				return;
			}
			cost += min - 1;
		}
		out.println(cost);
	}
	
	private static class Pair implements Comparable<Pair>
	{
		public int a;
		public int b;
		
		@Override
		public int compareTo(Pair o) {
			return o.a - a;
		}
	}
	
	public void run() throws Exception
	{
//		in = new Scanner(new StringReader("4 7 2 3 1 4 1 2 5 2 4 1 3 4 1 1 3 5"));
//		in = new Scanner(new StringReader("4 7 2 3 1 4 1 2 5 2 4 1 3 4 1 1 3 0"));
//		in = new Scanner(new StringReader("3 1 2 3 2 3 1 2 3 1 3"));
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
		new B().run();
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