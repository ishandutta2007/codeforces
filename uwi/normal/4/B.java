//package round4;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int d = ni();
		int s = ni();
		
		int[] min = new int[d];
		int[] max = new int[d];
		int smin = 0;
		int smax = 0;
		for(int i = 0;i < d;i++){
			min[i] = ni();
			max[i] = ni();
			smin += min[i];
			smax += max[i];
		}
		if(smin <= s && s <= smax){
			out.println("YES");
			int left = smax - s;
			for(int i = 0;i < d;i++){
				int u = Math.max(min[i], max[i] - left);
				left -= max[i] - u;
				out.print(u + " ");
			}
			out.println();
		}else{
			out.println("NO");
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