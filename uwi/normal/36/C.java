//package round36;

import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class C2 {
	Scanner in;
	PrintWriter out;
//	String INPUT = "2 40 10 50 60 20 30";
//	String INPUT = "2 40 30 50 60 20 30";
//	String INPUT = "3 50 30 80 35 25 70 40 10 90";
//	String INPUT = "2 30 10 15 30 5 10";
//	String INPUT = "3 30 10 15 30 10 16 30 10 17";
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		double[] d = new double[n];
		int[] h = new int[n];
		int[] r = new int[n];
		int[] R = new int[n];
		for(int i = 0;i < n;i++){
			h[i] = ni();
			r[i] = ni();
			R[i] = ni();
			double[] ux = {0, r[i], R[i]};
			double[] uy = {0, 0, h[i]};
			
			double hh = 0;
			for(int j = 0;j < i;j++){
				double[] x = {0, r[j], R[j]};
				double[] y = {d[j], d[j], h[j]+d[j]};
				int v = 0;
				int w = 0;
				while(v < 3-1 && w < 3-1){
					if(x[w] > ux[v]){
						double t0 = (x[w] - ux[v]) / (ux[v+1] - ux[v]);
						hh = Math.max(hh, y[w] - (uy[v] * (1 - t0) + uy[v+1] * t0));
					}else{
						double t0 = (ux[v] - x[w]) / (x[w+1] - x[w]);
						hh = Math.max(hh, (y[w] * (1 - t0) + y[w+1] * t0) - uy[v]);
					}
					
					if(x[w+1] < ux[v+1]){
						double t0 = (x[w+1] - ux[v]) / (ux[v+1] - ux[v]);
						hh = Math.max(hh, y[w+1] - (uy[v] * (1 - t0) + uy[v+1] * t0));
					}else{
						double t0 = (ux[v+1] - x[w]) / (x[w+1] - x[w]);
						hh = Math.max(hh, (y[w] * (1 - t0) + y[w+1] * t0) - uy[v+1]);
					}
					if(ux[v+1] == x[w+1]){
						v++; w++;
					}else if(ux[v+1] < x[w+1]){
						v++;
					}else{
						w++;
					}
				}
			}
			d[i] = hh;
		}
		
		double max = 0;
		for(int i = 0;i < n;i++){
			max = Math.max(max, h[i] + d[i]);
		}
		out.printf("%1.7f\n", max);
	}
	
	void run() throws Exception
	{
//		StringBuilder sb = new StringBuilder("3000 ");
//		Random r = new Random();
//		for(int i = 0;i < 3000;i++){
////			sb.append(10000);
////			sb.append(' ');
////			sb.append(i+1);
////			sb.append(' ');
////			sb.append(i+2);
////			sb.append(' ');
////			sb.append(r.nextInt(10000)+1);
////			sb.append(' ');
////			sb.append(r.nextInt(5000)+1);
////			sb.append(' ');
////			sb.append(r.nextInt(5000)+5001);
////			sb.append(' ');
//		}
//		INPUT = sb.toString();
		in = INPUT.isEmpty() ? new Scanner(new File("input.txt")) : new Scanner(INPUT);
		out = INPUT.isEmpty() ? new PrintWriter("output.txt") : new PrintWriter(System.out);

		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new C2().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
	static String join(int[] a, int d){StringBuilder sb = new StringBuilder();for(int v : a){sb.append(v + d + " ");}return sb.toString();}
}