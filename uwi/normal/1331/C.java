//package afc2020;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class C {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	// 000010
	// 000010
	
	// 000101
	// 011000
	
	// 1000x1
	// 1100x0

	
	void solve()
	{
		int n = ni();
		int m = 0;
		if(n<<~0<0) m |= 1<<4;
		if(n<<~1<0) m |= 1<<1;
		if(n<<~2<0) m |= 1<<3;
		if(n<<~3<0) m |= 1<<2;
		if(n<<~4<0) m |= 1<<0;
		if(n<<~5<0) m |= 1<<5;
		out.println(m);
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