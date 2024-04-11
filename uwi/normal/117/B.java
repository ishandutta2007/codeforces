//package round88;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int a = Math.min(ni(), 999999999);
		int b = Math.min(ni(), 999999999);
		int mod = ni();
		int M = 1000000000%mod;
		if(b >= mod){
			out.println(2);
		}else{
			long x = 0;
			for(int i = 0;i < mod && i <= a;i++, x+=M, x%=mod){
				if(x == 0)continue;
				if(x + b >= mod)continue;
				out.printf("%d %09d\n", 1, i);
				return;
			}
			out.println(2);
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
		new B().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}