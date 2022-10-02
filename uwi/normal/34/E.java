//package round34;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class E2 {
	private Scanner in;
	private PrintWriter out;
//	private String INPUT = "2 9 3 4 5 0 7 8";
//	private String INPUT = "10 100 1 1 1 2 1 1 3 1 1 4 1 1 5 1 1 6 -1 1 7 -1 1 8 -1 1 9 -1 1 10 -1 1";
//	private String INPUT = "3 10 1 2 3 4 -5 6 7 -8 9";
//	private String INPUT = "4 0 0 5 1 1 -5 1 9 5 1 10 -5 1";
//	private String INPUT = "1 10 0 1 2";
	private String INPUT = "";
	
	public void solve()
	{
		int n = ni();
		double t = ni();
		final double[] x = new double[n];
		double[] v = new double[n];
		double[] m = new double[n];
		for(int i = 0;i < n;i++){
			x[i] = ni();
			v[i] = ni();
			m[i] = ni();
		}
		
		Integer[] ind = new Integer[n];
		for(int i = 0;i < n;i++){
			ind[i] = i;
		}
		Arrays.sort(ind, new Comparator<Integer>(){
			public int compare(Integer a, Integer b)
			{
				return (int)Math.signum(x[a] - x[b]);
			}
		});
		while(true){
			double mint = t;
			for(int i = 0;i < n-1;i++){
				if(v[ind[i]] - v[ind[i+1]] > 1E-8){
					double ct = (x[ind[i+1]]-x[ind[i]])/(v[ind[i]]-v[ind[i+1]]);
					mint = Math.min(mint, ct);
				}
			}
			for(int i = 0;i < n;i++){
				x[i] += v[i] * mint;
			}
			t -= mint;
			if(t == 0)break;
			
			for(int i = 0;i < n - 1;i++){
				if(Math.abs(x[ind[i]] - x[ind[i+1]]) < 1E-8){
					// collide
					double m1 = m[ind[i]];
					double m2 = m[ind[i+1]];
					double v1 = v[ind[i]];
					double v2 = v[ind[i+1]];
					v[ind[i]] = ((m1-m2)*v1+2*m2*v2)/(m1+m2);
					v[ind[i+1]] = ((m2-m1)*v2+2*m1*v1)/(m1+m2);
				}
			}
		}
		
		for(int i = 0;i < n;i++){
			out.println(x[i]);
		}
	}
	
	public void run() throws Exception
	{
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new E2().run();
	}
	
	private int ni() { return Integer.parseInt(in.next()); }
	private void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}