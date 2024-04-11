//package round51;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class E {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] x = new int[n];
		int[] y = new int[n];
		for(int i = 0;i < n;i++){
			x[i] = ni();
			y[i] = ni();
		}
		int t = ni();
		int[] tx = new int[t];
		int[] ty = new int[t];
		for(int i = 0;i < t;i++){
			tx[i] = ni();
			ty[i] = ni();
			double[] rad = new double[n];
			for(int j = 0;j < n;j++){
				rad[j] = Math.atan2(y[j] - ty[i], x[j] - tx[i]);
			}
			Arrays.sort(rad);
//			tr(rad);
			long ct = 0;
			long minus = 0;
			for(int j = 0;j < n;j++){
				if(rad[j] >= 0){
					int ind = Arrays.binarySearch(rad, rad[j] - Math.PI);
					ind = -ind - 2;
					long one = j-ind-1;
					long oth = n-1-one;
//					tr(j,one,oth);
					ct += one*oth;
					minus += one*(one-1)/2;
					minus += oth*(oth-1)/2;
				}else{
					int ind = Arrays.binarySearch(rad, rad[j] + Math.PI);
					ind = -ind - 2;
					long one = ind-j;
					long oth = n-1-one;
//					tr(j,one,oth);
					ct += one*oth;
					minus += one*(one-1)/2;
					minus += oth*(oth-1)/2;
				}
			}
			ct -= minus / 2;
//			if(ct%3!=0)tr("");
			out.println(ct/3);
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
		new E().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}