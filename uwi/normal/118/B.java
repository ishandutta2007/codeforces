//package round89;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class E {
	Scanner in;
	PrintWriter out;
	String INPUT = "3";
	
	void solve()
	{
		int n = ni();
		for(int i = -n;i <= n;i++){
			StringBuilder sb = new StringBuilder();
			for(int j = -n;j <= n;j++){
				if(n-Math.abs(i)-Math.abs(j) >= 0){
					sb.append((n-Math.abs(i)-Math.abs(j)));
				}else{
					sb.append(' ');
				}
				sb.append(' ');
			}
			String ss = ("x" + sb.toString()).trim().substring(1);
			out.println(ss);
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