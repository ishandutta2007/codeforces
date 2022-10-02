//package round36;

import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class D {
	Scanner in;
	PrintWriter out;
//	String INPUT = "10 2 1 1 1 2 2 1 2 2 1 3 2 3 3 1 3 2 3 3 7 7";
//	String INPUT = "1 999 999999999 999999999";
//	String INPUT = "1 1 5 5";
	String INPUT = "";
	
	void solve()
	{
		int t = ni();
		int k = ni();
		for(int i = 0;i < t;i++){
			long n = ni() - 1;
			long m = ni() - 1;
			if(k == 1){
				if(n % 2 == 0 && m % 2 == 0){
					out.println('-');
				}else{
					out.println('+');
				}
			}else{
				if((n >= m && m%(k+1) == k) || (n <= m && n%(k+1) == k)){
					out.println('+');
					continue;
				}
				long flip = Math.min(n/(k+1), m/(k+1));
				out.println((n+m+flip)%2 == 0 ? '-' : '+');
			}
		}
//		int x = 30;
//		int y = 30;
//		char[][] m = new char[x][y];
//		for(int i = 0;i < 30;i++){
//			for(int j = 0;j < 30;j++){
//				boolean q = true;
//				if(i >= 1)q &= m[i-1][j] == '*';
//				if(j >= 1)q &= m[i][j-1] == '*';
//				if(i >= k && j >= k)q &= m[i-k][j-k] == '*';
//				m[i][j] = q ? '.' : '*';
//			}
//		}
//		for(char[] r : m){
//			out.println(new String(r));
//		}
	}
	
	void run() throws Exception
	{
		in = INPUT.isEmpty() ? new Scanner(new File("input.txt")) : new Scanner(INPUT);
		out = INPUT.isEmpty() ? new PrintWriter("output.txt") : new PrintWriter(System.out);

		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new D().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
	static String join(int[] a, int d){StringBuilder sb = new StringBuilder();for(int v : a){sb.append(v + d + " ");}return sb.toString();}
}