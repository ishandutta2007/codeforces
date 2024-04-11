//package round79;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Div2B {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		char[] u = in.next().toCharArray();
		if(u.length == 1){
			out.println(0);
			return;
		}
		int sum = 0;
		for(int i = 0;i < u.length;i++){
			sum += u[i]-'0';
		}
		
		int t = 1;
		for(int n = sum;n >= 10;t++){
			int nn = 0;
			for(;n > 0;n /= 10)nn += n % 10;
			n = nn;
		}
		out.println(t);
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
		new Div2B().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}