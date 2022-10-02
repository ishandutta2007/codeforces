//package round30;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class D {
	private Scanner in;
	private PrintWriter out;
//	private String INPUT = "4 5 0 5 -1 -5 2 3";
//	private String INPUT = "3 1 0 1 2 1 1";
//	private String INPUT = "3 1 1 0 2 1 1";
	private String INPUT = "";
	
	public void solve()
	{
		int n = ni();
		int k = ni() - 1;
		int[] x = new int[n];
		for(int i = 0;i < n;i++){
			x[i] = ni();
		}
		int ux = ni();
		int uy = ni();
		int xk = 0;
		if(k < n){
			xk = x[k];
		}
		
		Arrays.sort(x);
		if(k == n){
			out.println(fall(x[0], x[n-1], ux, uy));
		}else{
			double maxv = Math.min(
					2 * (x[n-1] - xk) + xk - x[0] + Math.sqrt(d2(x[0], 0, ux, uy)),
					2 * (xk - x[0]) + x[n-1] - xk + Math.sqrt(d2(x[n-1], 0, ux, uy))
					);
			tr(maxv);
			// erase 0-k-i
			for(int i = 0;i < n - 1;i++){
				if(x[i] >= xk){
					double v = Math.min(
							2 * (x[i] - xk) + xk - x[0] + Math.sqrt(d2(x[0], 0, ux, uy)),
							2 * (xk - x[0]) + x[i] - xk + Math.sqrt(d2(x[i], 0, ux, uy))
							) + fall(x[i+1], x[n-1], ux, uy);
					maxv = Math.min(maxv, v);
				}
			}
			tr(maxv);
			// erase i-k-(n-1)
			for(int i = n - 1;i >= 1;i--){
				if(x[i] <= xk){
					double v = Math.min(
							2 * (x[n-1] - xk) + xk - x[i] + Math.sqrt(d2(x[i], 0, ux, uy)),
							2 * (xk - x[i]) + x[n-1] - xk + Math.sqrt(d2(x[n-1], 0, ux, uy))
							) + fall(x[0], x[i-1], ux, uy);
					maxv = Math.min(maxv, v);
				}
			}
			out.println(maxv);
		}
	}
	
	public double fall(int f, int t, int ux, int uy)
	{
		return Math.sqrt(Math.min(d2(f, 0, ux, uy), d2(t, 0, ux, uy))) + t - f;
	}
	
	public long d2(long ax, long ay, long bx, long by)
	{
		return (ax - bx) * (ax - bx) + (ay - by) * (ay - by);
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
		new D().run();
	}
	
	private int ni() { return Integer.parseInt(in.next()); }
	private void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}