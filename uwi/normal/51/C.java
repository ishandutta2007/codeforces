//package round48;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class C {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] x = new int[n];
		for(int i = 0;i < n;i++){
			x[i] = ni();
		}
		Arrays.sort(x);
		
		if(n == 1){
			out.println(0);
			out.printf("%1.6f %1.6f %1.6f\n", (double)x[0], (double)x[0], (double)x[0]);
			return;
		}else if(n == 2){
			out.println(0);
			out.printf("%1.6f %1.6f %1.6f\n", (double)x[0], (double)x[0], (double)x[1]);
			return;
		}
		
		int dmin = x[n-1] - x[0] + 1;
		int oa = -1, ob = -1;
		for(int a = 0;a < n - 2;a++){
			int inf = a + 1;
			int sup = n - 1;
			while(sup - inf > 1){
				int cur = (inf + sup) / 2;
				if(x[cur] - x[a + 1] < x[n - 1] - x[cur + 1]){
					inf = cur;
				}else{
					sup = cur;
				}
			}
			int dmin1 = Math.max(x[n - 1] - x[inf + 1], x[a] - x[0]);
			if(dmin1 < dmin){
				dmin = dmin1;
				oa = a;
				ob = inf;
			}
			
			int dmin2 = Math.max(x[sup] - x[a + 1], x[a] - x[0]);
			if(dmin2 < dmin){
				dmin = dmin2;
				oa = a;
				ob = sup;
			}
		}
		
		out.printf("%1.6f\n", (double)dmin / 2);
		out.printf("%1.6f %1.6f %1.6f\n", (double)(x[0] + x[oa]) / 2, (double)(x[oa+1] + x[ob]) / 2, (double)(x[ob+1] + x[n-1]) / 2);
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
		new C().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}