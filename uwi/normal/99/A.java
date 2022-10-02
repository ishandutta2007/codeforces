//package round78;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;

public class Div2A {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		String num = in.next();
		int ind = num.indexOf('.');
		if(num.charAt(ind-1) == '9') {
			out.println("GOTO Vasilisa.");
			return;
		}
		if(num.charAt(ind+1) <= '4') {
			out.println(num.substring(0, ind));
		}else {
			out.println(new BigInteger(num.substring(0, ind)).add(BigInteger.ONE));
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
		new Div2A().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}