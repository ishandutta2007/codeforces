//package global10;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class E {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				out.print(((long)(i%2L)<<i+j) + " ");
			}
			out.println();
		}
		out.flush();
		
		for(int Q = ni();Q > 0;Q--){
			long V = nl();
			int r = 0, c = 0;
			out.println((r+1) + " " + (c+1));
			for(int i = 1;i < 2*n-1;i++){
				int val = (int)(V>>>i&1);
				if(r % 2 != val){
					r++;
				}else{
					c++;
				}
				out.println((r+1) + " " + (c+1));
			}
			out.flush();
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
		new E().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}