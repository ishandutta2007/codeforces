//package round60;

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
		int[] y = new int[n];
		for(int i = 0;i < n;i++){
			y[i] = ni();
		}
		int[] z = new int[n];
		int inf = 1000;
		for(int i = 0;i < n;i++){
			int min = 2012;
			for(int j = 1;j <= 1000;j *= 10){
				int cy = y[i] - ((y[i]/j)%10)*j;
				for(int k = 0;k <= 9;k++){
					if(cy+k*j >= inf){
						min = Math.min(min, cy + k*j);
					}
				}
			}
			if(min == 2012){
				out.println("No solution");
				return;
			}
			z[i] = min;
			inf = min;
		}
		for(int i = 0;i < n;i++){
			out.println(z[i]);
		}
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