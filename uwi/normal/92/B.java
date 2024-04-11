//package round75;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Div2B {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		char[] str = in.next().toCharArray();
		int n = str.length;
		int p = n-1;
		int t = 0;
		for(t = 0;;t++) {
			if(p == 0 && str[p] == '0') {
				out.println(t+1);
				return;
			}
			if(p == 0 && str[p] == '1') {
				out.println(t);
				return;
			}
			
			if(str[p] == '1') {
				for(int i = p;i >= 0;i--) {
					if(str[i] == '1') {
						str[i] = '0';
					}else {
						str[i] = '1';
						break;
					}
				}
			}else {
				p--;
			}
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