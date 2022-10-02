//package round88;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A {
	Scanner in;
	PrintWriter out;
	String INPUT = ""; 
	
	void solve()
	{
		int n = ni();
		int m = ni();
		int c = (m-1)*2;
		for(int i = 0;i < n;i++){
			int s = ni();
			int f = ni();
			int t = ni();
			
			if(s == f){
				out.println(t);
			}else if(s < f){
				//(s-1)+ck
				int k = (t-(s-1)+c-1)/c;
				out.println(f-1+c*k);
			}else{
				//(c-s+1)+ck
				int k = (t-(c-s+1)+c-1)/c;
				out.println((c-f+1)+c*k);
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
		new A().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}