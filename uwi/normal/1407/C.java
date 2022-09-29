//package round669;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class C {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int x = 1;
		int[] ret = new int[n];
		long s = 0;
		for(int y = 2;y <= n;y++) {
			out.println("? " + x + " " + y);
			out.flush();
			int xy = ni();
			out.println("? " + y + " " + x);
			out.flush();
			int yx = ni();
			if(xy > yx) {
				ret[x-1] = xy;
				s += xy;
				x = y;
			}else {
				ret[y-1] = yx;
				s += yx;
			}
		}
		ret[x-1] = (int)(n*(n+1)/2 - s);
		out.print("!");
		for(int v : ret) {
			out.print(" " + v);
		}
		out.println();
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
		new C().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}