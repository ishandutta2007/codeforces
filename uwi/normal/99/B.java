//package round78;
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
		for(int i = 0;i < n;i++) a[i] = ni();
		
		int sum = 0;
		for(int i = 0;i < n;i++) {
			sum += a[i];
		}
		if(sum % n != 0) {
			out.println("Unrecoverable configuration.");
			return;
		}
		int ct = 0;
		int more = -1, less = -1;
		for(int i = 0;i < n;i++) {
			if(a[i] == sum / n) {
				ct++;
			}else if(a[i] > sum / n) {
				more = i;
			}else if(a[i] < sum / n) {
				less = i;
			}
		}
		if(ct == n) {
			out.println("Exemplary pages.");
			return;
		}
		if(ct == n - 2) {
			int d = a[more] - sum / n;
			out.printf("%d ml. from cup #%d to cup #%d.\n", d, less+1, more+1);
		}else {
			out.println("Unrecoverable configuration.");
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
		new Div2B().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}