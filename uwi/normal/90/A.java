//package round74;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Div2A {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int[] c = new int[3];
		for(int i = 0;i < 3;i++)c[i] = ni();
		int t = 30;
		int f = 0;
		for(int i = 0;i < 3;i++){
			if(c[i] <= 0){
				f |= 1<<i;
			}
		}
		
		outer:
		while(f < 7){
			for(int i = 0;i < 3;i++){
				if(c[i] > 0){
					c[i] -= 2;
					if(c[i] <= 0){
						f |= 1<<i;
						if(f == 7){
							break outer;
						}
					}
				}
				t++;
			}
		}
		out.println(t);
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
		new Div2A().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}