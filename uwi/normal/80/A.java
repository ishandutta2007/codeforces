//package round69;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class D2A {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int m = ni();
		outer:
		for(int i = n+1;i < m;i++){
			for(int j = 2;j < i;j++){
				if(i % j == 0){
					continue outer;
				}
			}
			out.println("NO");
			return;
		}
		for(int j = 2;j < m;j++){
			if(m % j == 0){
				out.println("NO");
				return;
			}
		}
		out.println("YES");
	}
	
	void run() throws Exception
	{
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new D2A().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}