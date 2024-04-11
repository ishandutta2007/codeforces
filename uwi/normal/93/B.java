//package round76;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {
	Scanner in;
	PrintWriter out;
	String INPUT = "4 500 6";
	
	void solve()
	{
		int n = ni();
		double w = ni();
		int m = ni();
		for(int i = 0;i < n;i++){
			if((m*(i+1)-1)/n-m*i/n>=2){
				out.println("NO");
				return;
			}
		}
		
		out.println("YES");
		for(int i = 0;i < m;i++){
			int b = n*i;
			int a = n*(i+1);
			for(int j = b/m;j <= (a-1)/m;j++){
				out.printf("%d %.8f ", j+1, (Math.min(a, (j+1)*m)-Math.max(b, j*m)) * w / m);
			}
			out.println();
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