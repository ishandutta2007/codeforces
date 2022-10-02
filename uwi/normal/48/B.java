//package round45;

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
		int m = ni();
		int[][] t = new int[n][m];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				t[i][j] = ni();
			}
		}
		int a = ni();
		int b = ni();
		
		int min = n * m;
		for(int i = 0;i < n - a + 1;i++){
			for(int j = 0;j < m - b + 1;j++){
				int sum = 0;
				for(int r = 0;r < a;r++){
					for(int c = 0;c < b;c++){
						sum += t[i+r][j+c];
					}
				}
				min = Math.min(min, sum);
			}
		}
		for(int i = 0;i < n - b + 1;i++){
			for(int j = 0;j < m - a + 1;j++){
				int sum = 0;
				for(int r = 0;r < b;r++){
					for(int c = 0;c < a;c++){
						sum += t[i+r][j+c];
					}
				}
				min = Math.min(min, sum);
			}
		}
		out.println(min);
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
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}