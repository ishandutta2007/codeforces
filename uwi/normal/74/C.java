//package round68;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class C2 {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int m = ni();
		out.println(gcd(n-1, m-1)+1);
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
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new C2().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}