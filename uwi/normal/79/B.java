//package round71;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		String[] ki = {"Carrots", "Kiwis", "Grapes"};
		int n = ni();
		int m = ni();
		int k = ni();
		int t = ni();
		int[] p = new int[k];
		for(int i = 0;i < k;i++){
			p[i] = (ni() - 1) * m + (ni() - 1);
		}
		Arrays.sort(p);
		for(int i = 0;i < t;i++){
			int u = ni() - 1;
			int v = ni() - 1;
			int co = u*m+v;
			int ind = Arrays.binarySearch(p, co);
			if(ind >= 0){
				out.println("Waste");
			}else{
				int was = -ind-1;
				out.println(ki[(co - was) % 3]);
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
		new B().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}