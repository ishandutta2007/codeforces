//package round82;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		char[] rank = "6789TJQKA".toCharArray();
		
		char tru = in.next().charAt(0);
		char[] one = in.next().toCharArray();
		char[] two = in.next().toCharArray();
		if(tru == one[1] && tru != two[1]){
			out.println("YES");
			return;
		}
		if(one[1] == two[1]){
			for(int i = 0;i < rank.length;i++){
				if(rank[i] == one[0]){
					break;
				}else if(rank[i] == two[0]){
					out.println("YES");
					return;
				}
			}
		}
		out.println("NO");
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