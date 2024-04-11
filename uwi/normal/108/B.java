//package round83;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Div2B {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] a = new int[n];
		for(int i = 0;i < n;i++)a[i] = ni();
		Arrays.sort(a);
		for(int i = 0;i < n-1;i++){
			if(a[i] < a[i+1]){
				int lim = 0;
				if(a[i] == 1){
					lim = 1;
				}else{
					lim = a[i]*2;
				}
				if(a[i+1] < lim){
					out.println("YES");
					return;
				}
			}
		}
		out.println("NO");
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