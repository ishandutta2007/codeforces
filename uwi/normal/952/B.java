//package aprilfool2018;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		for(int i = 0;i < 4;i++){
			out.println((i+7)%10);
			out.flush();
			
			String res = in.nextLine().trim().toLowerCase();
			if(res.equals("great!") || res.equals("great")){
				out.println("normal"); return;
			}
			if(res.equals("don't think so")){
				out.println("normal"); return;
			}
			if(res.equals("not bad")){
				out.println("normal"); return;
			}
			if(res.equals("don't touch me!") || res.equals("don't touch me")){
				out.println("normal"); return;
			}
			if(res.equals("cool")){
				out.println("normal"); return;
			}
			if(res.equals("no"))continue;
			out.println("grumpy");
			return;
		}
		out.println("normal");
//		throw new RuntimeException();
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
		new B().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = true; //System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}