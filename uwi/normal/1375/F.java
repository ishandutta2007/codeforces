//package global9;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class F2 {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = 3;
		long[] a = new long[n];
		for(int i = 0;i < n;i++) {
			a[i] = ni();
		}
		out.println("First");
		out.flush();
		
		long m = 0;
		for(long v : a) {
			m = Math.max(m, v);
		}
		out.println(m);
		out.flush();
		int w = ni()-1;
		if(w == -1)return;
		a[w] += m;
		
		long max = a[w];
		// a b c
		// 2c-a-b
		out.println(2*max-(a[0]+a[1]+a[2]-a[w]));
		out.flush();
		
		int t = ni()-1;
		if(t == -1)return;
		a[t] += 2*max-(a[0]+a[1]+a[2]-a[w]);
		Arrays.sort(a);
		out.println(a[1] - a[0]);
		
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
		new F2().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}