//package round68;
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
		String maxn = "";
		int max = Integer.MIN_VALUE;
		for(int i = 0;i < n;i++){
			String name = in.next();
			int plus = ni();
			int minus = ni();
			int a = ni();
			int b = ni();
			int c = ni();
			int d = ni();
			int e = ni();
			int p = a+b+c+d+e+plus*100-minus*50;
			if(max < p){
				max = p;
				maxn = name;
			}
		}
		out.println(maxn);
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
		new A().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}