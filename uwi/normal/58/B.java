//package round54;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		if(n == 1){
			out.println("1");
			return;
		}
		
		out.print(n + " ");
		outer:
		while(n > 1){
			for(int i = 2;i < n;i++){
				if(n % i == 0){
					out.print(n / i + " ");
					n /= i;
					continue outer;
				}
			}
			break;
		}
		out.println("1");
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
		new B().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}