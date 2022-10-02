//package round53;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int m = ni();
		int k = ni();
		int[] a = new int[m];
		int[] b = new int[m];
		int[] c = new int[m];
		for(int i = 0;i < m;i++){
			a[i] = ni();
			b[i] = ni();
			c[i] = ni();
		}
		long sum = 0;
		for(int i = 0;i < k;i++){
			int u = ni();
			for(int j = 0;j < m;j++){
				if(a[j] <= u && u <= b[j]){
					sum += c[j] + (u-a[j]);
				}
			}
		}
		out.println(sum);
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
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}