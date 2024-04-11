//package round72;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] a = new int[n];
		for(int i = 0;i < n;i++){
			a[i] = ni();
		}
		int[] pre = new int[n];
		int v = 0;
		for(int i = 0;i < n;i++){
			if(i == 0 || a[i-1] != a[i]){
				pre[i] = i;
				v = i;
			}else{
				pre[i] = v;
			}
		}
		
		long ct = 0;
		for(int i = 0;i < n;i++){
			ct += (i - pre[i] + 1);
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
		new A().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}