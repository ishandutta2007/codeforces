//package round63;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {
	Scanner in;
	PrintWriter out;
//	String INPUT = "4 4 1 4 20 5 1 3 21 10 3 3 4 30 3 4 4 20";
//	String INPUT = "8 4 1 5 24 10 2 4 6 15 4 6 30 50 6 7 4 20";
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int m = ni();
		int[] l = new int[m];
		int[] r = new int[m];
		int[] t = new int[m];
		int[] c = new int[m];
		for(int i = 0;i < m;i++){
			l[i] = ni();
			r[i] = ni();
			t[i] = ni();
			c[i] = ni();
		}
		
		long ret = 0;
		for(int i = 1;i <= n;i++){
			int mint = 99999999;
			int minj = -1;
			for(int j = 0;j < m;j++){
				if(l[j] <= i && i <= r[j] && t[j] < mint){
					mint = t[j];
					minj = j;
				}
			}
			if(minj != -1){
				ret += c[minj];
			}
		}
		
		out.println(ret);
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