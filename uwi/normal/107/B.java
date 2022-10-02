//package round83;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int m = ni();
		int h = ni();
		int[] a = new int[m];
		int s = 0;
		for(int i = 0;i < m;i++){
			a[i] = ni();
			s += a[i];
		}
		
		int me = a[h-1]-1;
		int ot = s - me-1;
		if(n > s){
			out.println(-1.0);
		}else if(me == 0){
			out.println(0.0);
		}else if(n-1 > ot){
			out.println(1.0);
		}else{
			double p = 1;
			for(int i = 0;i < n-1;i++){
				p *= ot-i;
				p /= me+ot-i;
			}
			out.printf("%.9f\n", 1-p);
		}
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