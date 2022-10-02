//package round70;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class D {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		long rr = (long)n * n;
		long ct = 0;
		for(long d = 0;3*d+2 <= 2*n;d++){
			long s2 = (4*rr-(3*d+2)*(3*d+2))/3;
			long s = (long)Math.sqrt(s2);
			s = Math.min(s, d);
			if(s == d){
				ct += d == 0 ? 1 : 6*d;
			}else{
				if(d % 2 == 0){
					if(s % 2 == 1){
						s--;
					}
				}else{
					if(s % 2 == 0){
						s--;
					}
				}
				ct += 6 * (s+1);
			}
		}
		out.println(ct);
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
		new D().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}