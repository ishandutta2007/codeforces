//package yandex2011.finals;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class C2 {
	Scanner in;
	PrintWriter out;
	String INPUT = "3\r\n" +
			"0.115590 0.384031 0.443128 0.562356";
	
	void solve()
	{
		int n = ni();
		double[] p = new double[n+1];
		for(int i = 0;i <= n;i++){
			p[i] = in.nextDouble();
		}
		
		double max = 0;
		for(int i = 0;i <= n;i++){
			for(int j = i+1;j <= n;j++){
				double qj = ((double)n/2-i)/(j-i);
				double qi = ((double)n/2-j)/(i-j);
				if(qi >= 0 && qj >= 0){
					max = Math.max(max, qi*p[i]+qj*p[j]);
				}
			}
		}
		
		out.printf("%.9f\n", max);
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
		new C2().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}