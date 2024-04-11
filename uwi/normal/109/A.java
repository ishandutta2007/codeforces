//package round84;
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
		// 4a+7b=n
		for(int b = n/7;b >= 0;b--){
			if((n-7*b)%4==0){
				int a = (n-7*b)/4;
				StringBuilder sb = new StringBuilder();
				for(int i = 0;i < a;i++){
					sb.append(4);
				}
				for(int i = 0;i < b;i++){
					sb.append(7);
				}
				out.println(sb);
				return;
			}
		}
		out.println(-1);
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