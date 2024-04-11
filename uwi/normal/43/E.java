//package round42;

import java.awt.geom.Line2D;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class E2 {
	Scanner in;
	PrintWriter out;
//	String INPUT = "2 33\r\n" + 
//	"2 5 1 2 14\r\n" + 
//	"1 3 11";
//	String INPUT = "2 9\r\n" + 
//	"4 5 1 2 2 2 2 1 2\r\n" + 
//	"4 3 3 2 1 2 1 2 2";
//	String INPUT = "5 33\r\n" + 
//			"2 1 3 3 10\r\n" + 
//			"1 11 3\r\n" + 
//			"2 5 3 3 6\r\n" + 
//			"2 3 1 10 3\r\n" + 
//			"2 6 3 3 5";
//	String INPUT = "2 33\r\n" + 
//			"2 1 3 10 3\r\n" + 
//			"1 11 3";
//	String INPUT = "2 20 3 2 3 2 3 2 4 5 3 1 1 1 2 6 3 1 1 1";
//	String INPUT = "2 20 2 2 9 2 1 5 3 1 1 1 2 6 3 1 1 1";
	String INPUT = "";
	
	public void solve()
	{
		int n = ni();
		int s = ni();
		
		int[][] seg = new int[n][];
		for(int i = 0;i < n;i++){
			int k = ni();
			int[] ss = new int[2*k+2];
			ss[0] = 0; // t
			ss[1] = 0; // x
			for(int j = 0;j < k;j++){
				int v = ni();
				int t = ni();
				ss[2*j+2] = ss[2*j] + t;
				ss[2*j+3] = ss[2*j+1] + v * t;
			}
			seg[i] = ss;
		}
		
		int count = 0;
		for(int i = 0;i < n;i++){
			for(int j = i + 1;j < n;j++){
				for(int k = 0, l = 0;k < seg[i].length - 2 && l < seg[j].length - 2;){
//					{
//						double ak = a(seg[i], k);
//						double al = a(seg[j], l);
//						double hk = (double)seg[i][k+1] - ak * seg[i][k];
//						double hl = (double)seg[j][l+1] - al * seg[j][l];
//						if(Math.abs(ak - al) < EPS && Math.abs(hk - hl) < EPS){
//							if(seg[i][k+2] < seg[j][l+2]){
//								k+=2;
//							}else if(seg[i][k+2] > seg[j][l+2]){
//								l+=2;
//							}else{
//								k+=2;
//								l+=2;
//							}
//							continue;
//						}
//					}
					if(seg[i][k] == seg[j][l] && seg[i][k+1] == seg[j][l+1]){
						if(k > 0 || l > 0){
							count++;
						}
						if(seg[i][k+2] < seg[j][l+2]){
							k+=2;
						}else if(seg[i][k+2] > seg[j][l+2]){
							l+=2;
						}else{
							k+=2;
							l+=2;
						}
						continue;
					}
					if(seg[i][k+2] == seg[j][l+2] && seg[i][k+3] == seg[j][l+3]){
						if(seg[i][k+2] < seg[j][l+2]){
							k+=2;
						}else if(seg[i][k+2] > seg[j][l+2]){
							l+=2;
						}else{
							k+=2;
							l+=2;
						}
						continue;
					}
					{
						double ak = a(seg[i], k);
						double al = a(seg[j], l);
						double hk = (double)seg[i][k+1] - ak * seg[i][k];
						double hl = (double)seg[j][l+1] - al * seg[j][l];
						if(seg[i][k] <= seg[j][l+2] && seg[j][l+2] <= seg[i][k+2] && Math.abs(ak * seg[j][l+2] + hk - seg[j][l+3]) < EPS){
							if(seg[i][k+2] < seg[j][l+2]){
								k+=2;
							}else if(seg[i][k+2] > seg[j][l+2]){
								l+=2;
							}else{
								k+=2;
								l+=2;
							}
							continue;
						}
						if(seg[j][l] <= seg[i][k+2] && seg[i][k+2] <= seg[j][l+2] && Math.abs(al * seg[i][k+2] + hl - seg[i][k+3]) < EPS){
							if(seg[i][k+2] < seg[j][l+2]){
								k+=2;
							}else if(seg[i][k+2] > seg[j][l+2]){
								l+=2;
							}else{
								k+=2;
								l+=2;
							}
							continue;
						}
					}
					
//						tr(i, j, k, l);
//						tr(seg[i][k], seg[i][k+1], seg[i][k+2], seg[i][k+3], seg[j][l], seg[j][l+1], seg[j][l+2], seg[j][l+3]);
					if(Line2D.linesIntersect(seg[i][k], seg[i][k+1], seg[i][k+2], seg[i][k+3], seg[j][l], seg[j][l+1], seg[j][l+2], seg[j][l+3])){
						count++;
					}
					if(seg[i][k+2] < seg[j][l+2]){
						k+=2;
					}else if(seg[i][k+2] > seg[j][l+2]){
						l+=2;
					}else{
						k+=2;
						l+=2;
					}
					continue;
				}
			}
			
		}
		out.println(count);
	}
	
	double EPS = 1E-9;
	
	double a(int[] seg, int k)
	{
		return (double)(seg[k+3] - seg[k+1]) / (double)(seg[k+2] - seg[k]);
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
		new E2().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}