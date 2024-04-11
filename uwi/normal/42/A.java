//package round41;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A {
	Scanner in;
	PrintWriter out;
//	String INPUT = "2 100 1 1 25 30";
//	String INPUT = "2 100 1 1 60 60";
//	String INPUT = "2 100 2 3 10 15";
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int v = ni();
		int[] a = new int[n];
		int sum = 0;
		for(int i = 0;i < n;i++){
			a[i] = ni();
			sum += a[i];
		}
		int[] b = new int[n];
		for(int i = 0;i < n;i++){
			b[i] = ni();
		}
		
		double min = 99999;
		for(int i = 0;i < n;i++){
			if(min > (double)b[i] / a[i]){
				min = (double)b[i] / a[i];
			}
		}
		
		out.println(Math.min(v, min * sum));
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
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}