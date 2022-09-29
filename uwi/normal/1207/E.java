//package educational.round71;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class E {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		out.println("? ");
		for(int i = 0;i < 100;i++){
			out.print(i + " ");
		}
		out.println();
		out.flush();
		
		int y = ni();
		
		out.println("? ");
		for(int i = 1;i <= 100;i++){
			out.print((i<<7) + " ");
		}
		out.println();
		out.flush();
		
		int z = ni();
		out.println("! " + ((z&127)|(y&(127<<7))));
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
		new E().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}