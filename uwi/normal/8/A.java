//package round8;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		String x = in.next();
		String rx = new StringBuilder(x).reverse().toString();
		String a = in.next();
		String b = in.next();
		int d = -1;
		boolean fo = (d = x.indexOf(a)) != -1 && x.indexOf(b, d+a.length()) != -1;
		boolean ba = (d = rx.indexOf(a)) != -1 && rx.indexOf(b, d+a.length()) != -1;
		if(fo){
			if(ba){
				out.println("both");
			}else{
				out.println("forward");
			}
		}else{
			if(ba){
				out.println("backward");
			}else{
				out.println("fantasy");
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
		new A().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}