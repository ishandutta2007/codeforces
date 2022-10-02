//package round73;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A {
	Scanner in;
	PrintWriter out;
	String INPUT = "2 3";
	
	void solve()
	{
		int a = ni();
		int b = ni();
		int g = gcd(a, b);
		a /= g;
		b /= g;
		if(b-a==1 || a-b==1){
			out.println("Equal");
		}else if(a<b){
			out.println("Dasha");
		}else if(a>b){
			out.println("Masha");
		}
	}
	
	public static int gcd(int a, int b) {
		while (b > 0){
			int c = a;
			a = b;
			b = c % b;
		}
		return a;
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