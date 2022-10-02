//package round67;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		long a = ni();
		long b = ni();
		long c = a + b;
		out.println(sp(a)+sp(b) == sp(c) ? "YES" : "NO");
	}
	
	long sp(long n)
	{
		long ret = 0;
		long mul = 1;
		for(;n > 0;n /= 10){
			if(n % 10 > 0){
				ret += mul * (n%10);
				mul *= 10;
			}
		}
		return ret;
	}
	
	void run() throws Exception
	{
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new A().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}