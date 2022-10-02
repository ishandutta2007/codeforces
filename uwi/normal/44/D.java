//package school2;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class D {
	Scanner in;
	PrintWriter out;
//	String INPUT = "4 0 0 0 0 0 1 0 1 0 1 0 0";
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] x = new int[n];
		int[] y = new int[n];
		int[] z = new int[n];
		double[] u = new double[n];
		for(int i = 0;i < n;i++){
			x[i] = ni();
			y[i] = ni();
			z[i] = ni();
			u[i] = dd(x[0]-x[i], y[0]-y[i], z[0]-z[i]);
		}
		double min = 999999999;
		for(int i = 1;i < n;i++){
			for(int j = 1;j < i;j++){
				min = Math.min(min, (u[i] + u[j] + dd(x[i]-x[j], y[i]-y[j],z[i]-z[j])) / 2);
			}
		}
		out.println(min);
	}
	
	double dd(double x, double y, double z)
	{
		return Math.sqrt(x * x + y * y + z * z);
	}
	
	void run() throws Exception
	{
//		int n = 5000;
//		StringBuilder sb = new StringBuilder(n + " ");
//		Random r = new Random();
//		for(int i = 0;i < n;i++){
//			sb.append(r.nextInt(10000) + " ");
//			sb.append(r.nextInt(10000) + " ");
//			sb.append(r.nextInt(10000) + " ");
//		}
//		INPUT = sb.toString();
		
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new D().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}