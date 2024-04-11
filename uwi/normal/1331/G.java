//package afc2020;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class G {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		List<Integer> ins = new ArrayList<>();
		for(int i = 0;i < 11;i++) {
			ins.add(ni());
		}
		for(int i = ins.size()-1;i >= 0;i--) {
			double x = ins.get(i);
			double ans = x*x*x*5.0 + Math.sqrt(Math.abs(x));
			if(ans > 400) {
				out.printf("f(%d) = MAGNA NIMIS!\n", ins.get(i), ans);
			}else {
				out.printf("f(%d) = %.2f\n", ins.get(i), ans);
			}
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
		new G().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}