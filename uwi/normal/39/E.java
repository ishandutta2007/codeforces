//package school1;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class E {
	Scanner in;
	PrintWriter out;
//	String INPUT = "2 2 10";
//	String INPUT = "5 5 16808";
//	String INPUT = "3 1 4";
//	String INPUT = "1 4 10";
//	String INPUT = "2 1 1000000000";
//	String INPUT = "2 29 1000000000";
//	String INPUT = "1 1 3";
//	String INPUT = "1 1 5";
//	String INPUT = "1 2 6";
//	String INPUT = "10000 1 10001";
//	String INPUT = "1 29 1000000000";
	String INPUT = "";
	
	void solve()
	{
		int a = ni();
		int b = ni();
		int n = ni();
		if(a == 1){
			if(n <= 1<<b){
				out.println("Missing");
			}else{
				int[][] h = judge(a+1, b, n);
				int u;
				for(u = b;1<<u < n;u++);
				
				h[u][1] = 0;
				for(int i = u - 1;i >= b;i--){
					int x = 0;
					x |= 1 << h[i+1][1];
					x |= 1 << h[i][2];
					for(int k = 0;k <= 2;k++){
						if((x & (1<<k)) == 0){
							h[i][1] = k;
							break;
						}
					}
				}
				int h0 = h[b][1];
				
				h[u][1] = 1;
				for(int i = u - 1;i >= b;i--){
					int x = 0;
					x |= 1 << h[i+1][1];
					x |= 1 << h[i][2];
					for(int k = 0;k <= 2;k++){
						if((x & (1<<k)) == 0){
							h[i][1] = k;
							break;
						}
					}
				}
				int h1 = h[b][1];
				
				if(h0 != 0 && h1 != 0){
					out.println("Masha");
					return;
				}
				if(h0 == 0 && h1 == 0){
					out.println("Stas");
					return;
				}
				
				out.println("Missing");
			}
		}else{
			int[][] h = judge(a, b, n);
			out.println(h[b][a] == 0 ? "Stas" : "Masha");
		}
	}
	
	double EPS = 1E-6;
	
	int[][] judge(int a, int b, int n)
	{
		// a^b<n
		int m = (int)Math.sqrt(1E9) + 2;
		int[][] h = new int[32][m+1];
		// n : 1
		// n-1 : 0
		// n-2 : 2
		for(int i = 31;i >= b;i--){
			for(int j = m;j >= a;j--){
				if(Math.log(n) <= Math.log(j) * i + EPS){
					h[i][j] = 1;
				}else{
					if(i == 1 && j == m){
						h[i][j] = n % 2 == m % 2 ? 2 : 0;
						continue;
					}
					int x = 0;
					if(i < 31)x |= 1 << h[i+1][j];
					if(j < m - 1)x |= 1 << h[i][j+1];
					for(int k = 0;k <= 2;k++){
						if((x & (1<<k)) == 0){
							h[i][j] = k;
//							tr(i, j, k);
							break;
						}
					}
				}
			}
		}
		return h;
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
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}