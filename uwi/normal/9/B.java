//package round9beta;


import java.io.BufferedOutputStream;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.io.StringReader;
import java.util.Arrays;
import java.util.Scanner;

public class B {
	private Scanner in;
	private PrintWriter out;
	double eps = 0.00001;
	
	public void solve()
	{
		int n = ni();
		int vb = ni();
		int vs = ni();
		
		int[] x = new int[n];
		for(int i = 0;i < n;i++){
			x[i] = ni();
		}
		int xu = ni();
		int yu = ni();
		
		double mint = Double.MAX_VALUE;
		int mini = 0;
		for(int i = 1;i < n;i++){
			double t = Math.sqrt((double)(xu - x[i]) * (xu - x[i]) + (double)yu * yu) / vs + (double)x[i] / vb;
			if(t < mint - eps){
				mint = t;
				mini = i;
			}else if(Math.abs(t - mint) <= eps){
				if(Math.abs(x[i] - xu) < Math.abs(x[mini] - xu)){
					mint = t;
					mini = i;
				}
			}
		}
		
		out.println(mini + 1);
	}
	
	public void run() throws Exception
	{
//		in = new Scanner(new StringReader("2 1 1 0 100000 100000 100000"));
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