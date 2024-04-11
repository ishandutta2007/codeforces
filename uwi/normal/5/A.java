//package round5;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		long p = 0;
		long ret = 0;
		while(in.hasNext()) {
			String line = in.nextLine();
			if(line.charAt(0) == '+') {
				p++;
			}else if(line.charAt(0) == '-') {
				p--;
			}else {
				int ind = line.indexOf(':');
				long len = line.length() - ind - 1;
				ret += len * p;
			}
		}
		out.println(ret);
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
	double nd() { return Double.parseDouble(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}