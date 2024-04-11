//package round69;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B2 {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int t = ni();
		for(int i = 0;i < t;i++){
			int a = ni();
			int b = ni();
			if(a == 0 && b == 0){
				out.println(1);
			}else{
				double w = 0.5;
				if(4 * b >= a){
					w += (double)a/8/b/2;
				}else{
					w += (double)(a-2*b)/a/2;
				}
				out.println(w);
			}
		}
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
		new B2().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}