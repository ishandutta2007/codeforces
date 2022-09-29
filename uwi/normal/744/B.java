//package round385;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	int[] get(int[] a, int n)
	{
		if(a.length == 0){
			int[] ret = new int[n];
			Arrays.fill(ret, Integer.MAX_VALUE);
			return ret;
		}
		out.println(a.length);
		for(int i = 0;i < a.length;i++){
			out.print((a[i]+1) + " ");
		}
		out.println();
		out.flush();
		
		int[] vals = new int[n];
		for(int i = 0;i < n;i++){
			vals[i] = ni();
		}
		return vals;
	}
	
	void solve()
	{
		int n = ni();
		int[] mins = new int[n];
		Arrays.fill(mins, Integer.MAX_VALUE);
		for(int mod = 1024;mod >= 2;mod /= 2){
			int[] as = new int[n];
			int[] bs = new int[n];
			int ap = 0, bp = 0;
			for(int i = 0;i < n;i++){
				if(i % mod < mod/2){
					as[ap++] = i;
				}else{
					bs[bp++] = i;
				}
			}
			int[] ares = get(Arrays.copyOf(as, ap), n);
			int[] bres = get(Arrays.copyOf(bs, bp), n);
			for(int i = 0;i < n;i++){
				if(i % mod < mod/2){
					mins[i] = Math.min(mins[i], bres[i]);
				}else{
					mins[i] = Math.min(mins[i], ares[i]);
				}
			}
		}
		out.println(-1);
		for(int i = 0;i < n;i++){
			out.print(mins[i] + " ");
		}
		out.flush();
	}
	
	void run() throws Exception
	{
		in = oj ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception
	{
		new B().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}