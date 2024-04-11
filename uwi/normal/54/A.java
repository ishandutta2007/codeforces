//package round50;

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
		int k = ni();
		int c = ni();
		int[] h = new int[c+2];
		h[0] = -1;
		h[c+1] = n;
		for(int i = 1;i <= c;i++){
			h[i] = ni() - 1;
		}
		int sum = 0;
		for(int i = 0;i <= c;i++){
			sum += (h[i+1]-h[i]-1) / k + 1;
		}
		out.println(sum-1);
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