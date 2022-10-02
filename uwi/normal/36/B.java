//package round36;

import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {
	Scanner in;
	PrintWriter out;
//	String INPUT = "2 1 .* ..";
//	String INPUT = "3 5 .*. *** .*.";
//	String INPUT = "3 5 ... ... ...";
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int k = ni();
		char[][] model = new char[n][n];
		for(int i = 0;i < n;i++){
			model[i] = in.next().toCharArray();
		}
		
		int s = (int)Math.pow(n, k);
		char[][] m = new char[s][s];
		for(int i = 0;i < s;i++){
			for(int j = 0;j < s;j++){
				m[i][j] = '.';
			}
		}
		for(int p = s/n;p > 0;p/=n){
			for(int i = 0;i < s;i++){
				for(int j = 0;j < s;j++){
					if(m[i][j] == '.' && model[(i%(p*n))/p][(j%(p*n))/p] == '*'){
						m[i][j] = '*';
					}
				}
			}
		}
		
		for(int i = 0;i < s;i++){
			out.println(new String(m[i]));
		}
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
		new B().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
	static String join(int[] a, int d){StringBuilder sb = new StringBuilder();for(int v : a){sb.append(v + d + " ");}return sb.toString();}
}