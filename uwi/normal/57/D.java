//package round53;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class D {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int m = ni();
		char[][] sp = new char[n][m];
		for(int i = 0;i < n;i++){
			sp[i] = in.next().toCharArray();
		}
		long sum = 0;
		int[] y = new int[n];
		int[] x = new int[m];
		int[] yp = new int[n];
		int[] xp = new int[m];
		int st = 0;
		for(int i = 0;i < n;i++){
			y[i] = m;
			for(int j = 0;j < m;j++){
				if(sp[i][j] == 'X'){
					y[i] = m - 1;
					yp[i] = j;
					st++;
					break;
				}
			}
		}
		for(int i = 0;i < m;i++){
			x[i] = n;
			for(int j = 0;j < n;j++){
				if(sp[j][i] == 'X'){
					x[i] = n - 1;
					xp[i] = j;
					break;
				}
			}
		}
		
		for(int i = 0;i < n;i++){
			for(int j = i+1;j < n;j++){
				sum += (long)(j-i)*y[j]*y[i];
			}
		}
		for(int i = 0;i < m;i++){
			for(int j = i+1;j < m;j++){
				sum += (long)(j-i)*x[j]*x[i];
			}
		}
		sum *= 2;
		
		for(int i = 0;i < n;i++){
			if(y[i] == m-1){
				sum += 4L*yp[i]*(m-yp[i]-1);
				int cur = yp[i];
				for(int j = i+1;j < n;j++){
					if(y[j] == m-1 && yp[j] > cur){
						cur = yp[j];
						sum += 4L*yp[i]*(m-yp[j]-1);
					}else{
						break;
					}
				}
				cur = yp[i];
				for(int j = i+1;j < n;j++){
					if(y[j] == m-1 && yp[j] < cur){
						cur = yp[j];
						sum += 4L*yp[j]*(m-yp[i]-1);
					}else{
						break;
					}
				}
			}
		}
		
		for(int i = 0;i < m;i++){
			if(x[i] == n-1){
				sum += 4L*xp[i]*(n-xp[i]-1);
				int cur = xp[i];
				for(int j = i+1;j < m;j++){
					if(x[j] == n-1 && xp[j] > cur){
						cur = xp[j];
						sum += 4L*xp[i]*(n-xp[j]-1);
					}else{
						break;
					}
				}
				cur = xp[i];
				for(int j = i+1;j < m;j++){
					if(x[j] == n-1 && xp[j] < cur){
						cur = xp[j];
						sum += 4L*xp[j]*(n-xp[i]-1);
					}else{
						break;
					}
				}
			}
		}
		
//		out.println(BigDecimal.valueOf(sum).divide(BigDecimal.valueOf((long)(n*m-st)*(n*m-st)), 20, RoundingMode.HALF_UP));
		out.println((double)sum / (n*m-st) / (n*m-st));
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
		new D().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}