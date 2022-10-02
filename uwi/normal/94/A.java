//package round76;
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
		String[] x = new String[10];
		for(int i = 0;i < 10;i++){
			x[i] = in.next();
		}
		for(int i = 0;i < 80;i+=10){
			for(int j = 0;j < 10;j++){
				if(line.substring(i, i+10).equals(x[j])){
					out.print(j);
					break;
				}
			}
		}
		out.println();
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