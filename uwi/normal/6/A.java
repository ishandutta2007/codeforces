//package round6;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int a = ni();
		int b = ni();
		int c = ni();
		int d = ni();
		if(
				!ch(a,b,c) &&
				!ch(b,c,d) &&
				!ch(c,d,a) &&
				!ch(d,a,b)
				){
			if(
					!ch2(a,b,c) &&
					!ch2(b,c,d) &&
					!ch2(c,d,a) &&
					!ch2(d,a,b)
					){
				out.println("IMPOSSIBLE");
			}
		}
	}
	
	boolean ch(int a, int b, int c)
	{
		if(a+b>c && b+c>a && c+a>b){
			out.println("TRIANGLE");
			return true;
		}
		return false;
	}
	
	boolean ch2(int a, int b, int c)
	{
		if(a+b>=c && b+c>=a && c+a>=b){
			out.println("SEGMENT");
			return true;
		}
		return false;
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