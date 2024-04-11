//package round77;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Div2B {
	Scanner in;
	PrintWriter out;
	String INPUT = "0";
	
	void solve()
	{
		int[] x = new int[1024];
		x[0] = 0;
		int p = 1;
		int prev = 0;
		for(int i = 1;i <= 9;i++) {
			int op = prev;
			prev = p;
			for(int j = p-1;j >= op;j--) {
				for(int k = 4;k <= 7;k+=3) {
					x[p++] = x[j] * 10 + k;
				}
			}
		}
		
		int[] sl = new int[1000];
		int slp = 0;
		for(int i = 1;i < p;i++) {
			char[] u = Integer.toString(x[i]).toCharArray();
			if(u.length % 2 == 0) {
				int f = 0;
				int s = 0;
				for(int j = 0;j < u.length;j++) {
					if(u[j] == '4') {
						f++;
					}else {
						s++;
					}
				}
				if(f == s) {
					sl[slp++] = x[i];
				}
			}
		}
		
		int n = ni();
		long min = 4444477777L;
		for(int i = 0;i < slp;i++) {
			if(sl[i] >= n) {
				min = Math.min(min, sl[i]);
			}
		}
		out.println(min);
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