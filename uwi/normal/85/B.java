//package yandex2011.r1;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		long[] k = new long[3];
		long[] t = new long[3];
		for(int i = 0;i < 3;i++)k[i] = ni();
		for(int i = 0;i < 3;i++)t[i] = ni();
		int n = ni();
		long[] c = new long[n];
		long[] start = new long[n];
		for(int i = 0;i < n;i++){
			c[i] = start[i] = ni();
		}
		for(int i = 0;i < 3;i++){
			long[] end = new long[n];
			for(int j = 0;j < n;j++){
				end[j] = start[j] + t[i];
				if(j-k[i] >= 0){
					end[j] = Math.max(end[j], end[(int)(j-k[i])] + t[i]);
				}
			}
			start = end;
		}
		
		long max = 0;
		for(int i = 0;i < n;i++){
			max = Math.max(max, start[i] - c[i]);
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
	double nd() { return Double.parseDouble(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}