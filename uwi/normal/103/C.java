//package round80;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class C2 {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		long n = nl();
		long k = nl();
		int p = ni();
		StringBuilder sb = new StringBuilder();
		for(int i = 0;i < p;i++){
			long x = nl();
			if(n % 2 == 0){
				if(x % 2 == 0){
					sb.append(k >= (n-x)/2+1 ? 'X' : '.');
				}else{
					sb.append(k >= n/2+(n-x+1)/2 ? 'X' : '.');
				}
			}else{
				if(x == n){
					sb.append(k >= 1 ? 'X' : '.');
				}else if(x % 2 == 0){
					sb.append(k >= (n-1-x)/2+2 ? 'X' : '.');
				}else{
					sb.append(k >= (n-1)/2+(n-x)/2+1 ? 'X' : '.');
				}
			}
		}
		out.println(sb);
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
		new C2().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}