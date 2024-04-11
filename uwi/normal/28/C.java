//package round28;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class C {
	private Scanner in;
	private PrintWriter out;
//	private String INPUT = "1 1 2";
//	private String INPUT = "2 2 11";
//	private String INPUT = "2 3 11 1";
//	private String INPUT = "7 5 1 1 2 3 1";
	private String INPUT = "";
	private double[] fact;
	
	public void solve()
	{
		int n = ni();
		int m = ni();
		int[] a = new int[m];
		for(int i = 0;i < m;i++){
			a[i] = ni();
		}
		
		fact = new double[51];
		double f = 1.0;
		fact[0] = 1.0;
		for(int i = 1;i <= 50;i++){
			f *= i;
			fact[i] = f;
		}
		
		double[] max = new double[n + 1];
		for(int k = 1;k <= n;k++){
			int[] sups = new int[m];
			for(int i = 0;i < m;i++){
				sups[i] = a[i] * k;
			}
			double[] sum = new double[n + 1];
			sum[0] = 1.0;
			
			for(int i = 0;i < m;i++){
				double[] nsum = new double[n + 1];
				for(int l = 0;l <= n;l++){
					for(int j = 0;j <= sups[i] && l + j <= n;j++){
						nsum[l + j] += sum[l] / fact[j];
					}
				}
				sum = nsum;
//				tr(i, Arrays.toString(sum));
			}
			max[k] = sum[n] * fact[n] / Math.pow(m, n);
		}
		tr(Arrays.toString(max));
		
		double e = 0.0;
		for(int k = 1;k <= n;k++){
			e += (max[k] - max[k-1]) * k;
		}
		out.println(e);
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
		new C().run();
	}
	
	private int ni() { return Integer.parseInt(in.next()); }
	private void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length == 1 ? o[0] : Arrays.toString(o)); }
}