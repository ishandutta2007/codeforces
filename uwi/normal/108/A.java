//package round83;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Div2A {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		String line = in.next();
		int h = Integer.parseInt(line.substring(0,2));
		int m = Integer.parseInt(line.substring(3,5));
		int c = h*60+m;
		int[] ya = new int[24];
		for(int i = 0;i < 24;i++){
			String x = String.format("%02d", i);
			int r = Integer.parseInt((new StringBuilder(x)).reverse().toString());
			ya[i] = r;
		}
		
		for(int i = c+1;i <= 99999;i++){
			int hh = i/60%24;
			int mm = i%60;
			if(ya[hh] == mm){
				out.printf("%02d:%02d\n", hh, mm);
				return;
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
		new Div2A().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}