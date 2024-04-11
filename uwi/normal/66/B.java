//package round61;

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
		int[] h = new int[n];
		for(int i = 0;i < n;i++){
			h[i] = ni();
		}
		int max = 0;
		for(int i = 0;i < n;i++){
			int j = i-1;
			for(;j >= 0 && h[j] <= h[j+1];j--);
			j++;
			int k = i+1;
			for(;k < n && h[k] <= h[k-1];k++);
			k--;
			max = Math.max(max, k-j+1);
		}
		out.println(max);
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