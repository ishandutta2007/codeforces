//package round6;
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
		int[] t = new int[n];
		for(int i = 0;i < n;i++)t[i] = ni();
		int a = 0, b = n-1;
		int ta = 0, tb = 0;
		while(a <= b){
			if(ta <= tb){
				ta += t[a];
				a++;
			}else{
				tb += t[b];
				b--;
			}
		}
		out.println(a + " " + (n-a));
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
		new C().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}