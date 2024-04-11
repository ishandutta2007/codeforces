//package round38;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class D2 {
	Scanner in;
	PrintWriter out;
//	String INPUT = "2 0 0 3 3 2 0 5 3";
//	String INPUT = "3 0 0 3 3 1 0 4 3 2 0 5 3";
//	String INPUT = "2 -50 -50 50 50 -1 -1 0 0";
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] x1 = new int[n];
		int[] x2 = new int[n];
		int[] y1 = new int[n];
		int[] y2 = new int[n];
		for(int i = 0;i < n;i++){
			x1[i] = ni();
			y1[i] = ni();
			x2[i] = ni();
			y2[i] = ni();
			if(x1[i] > x2[i]){
				int d = x1[i]; x1[i] = x2[i]; x2[i] = d;
			}
			if(y1[i] > y2[i]){
				int d = y1[i]; y1[i] = y2[i]; y2[i] = d;
			}
		}
		
		double EPS = 1E-7;
		for(int i = 1;i < n;i++){
			double ax = 0;
			double ay = 0;
			double w = 0;
			for(int j = i;j >= 1;j--){
				double lw = (x2[j] - x1[j]) * (x2[j] - x1[j]) * (x2[j] - x1[j]);
				w += lw;
				ax += (double)(x1[j] + x2[j]) / 2 * lw;
				ay += (double)(y1[j] + y2[j]) / 2 * lw;
				
				if(
						x1[j-1] - EPS <= ax / w && ax / w <= x2[j-1] + EPS &&
						y1[j-1] - EPS <= ay / w && ay / w <= y2[j-1] + EPS
						){
				}else{
					out.println(i);
					return;
				}
			}
		}
		out.println(n);
	}
	
	void run() throws Exception
	{
//		int n = 100;
//		StringBuilder sb = new StringBuilder(n + " ");
//		for(int i = 0;i < n;i++){
//			if(i == 10){
//				sb.append("0 1 0 1 ");
//			}else{
//				sb.append("-50 -49 -49 -50 ");
//			}
//		}
//		INPUT = sb.toString();
		
		
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new D2().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}