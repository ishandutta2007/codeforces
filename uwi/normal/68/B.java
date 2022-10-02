//package round62;

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
		int k = ni();
		int[] a = new int[n];
		for(int i = 0;i < n;i++){
			a[i] = ni();
		}
		
		double low = 0;
		double high = 11111;
		while(high - low > 1E-8){
			double mid = (high + low) / 2;
			double pm = 0;
			for(int i = 0;i < n;i++){
				if(a[i] > mid){
					pm += a[i] - mid;
				}else{
					pm -= (mid - a[i]) * 100 / (100-k);
				}
			}
			if(pm > 0){
				low = mid;
			}else{
				high = mid;
			}
		}
		out.println(low);
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