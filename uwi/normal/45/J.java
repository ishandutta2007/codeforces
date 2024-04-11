//package school3;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class J {
	Scanner in;
	PrintWriter out;
//	String INPUT = "5 8";
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int m = ni();
		if(n == 1 && m == 1){
			out.println(1);
		}else if(n <= 2 && m <= 2){
			out.println(-1);
		}else if(n >= 3 && m >= 3){
			for(int i = 0;i < n;i++){
				for(int j = 0;j < m;j++){
					int x = i + n * (j - i);
					x %= n * m;
					x = (x + n * m) % (n * m);
					out.print(x + 1 + " ");
				}
				out.println();
			}
		}else if((n == 1 && m == 3) || (n == 3 && m == 1)){
			out.println(-1);
		}else if(n == 1){
			for(int i = 0;i < m / 2;i++){
				out.print(1 + (m % 2) + 2 * (m/2 - 1 - i) + " ");
			}
			for(int i = m / 2;i < m;i++){
				out.print(m - 2 * (i - m / 2) + " ");
			}
			out.println();
		}else if(m == 1){
			for(int i = 0;i < n / 2;i++){
				out.println(1 + (n % 2) + 2 * (n/2 - 1 - i));
			}
			for(int i = n / 2;i < n;i++){
				out.println(n - 2 * (i - n / 2));
			}
		}else if(n == 2){
			for(int i = 0;i < n;i++){
				for(int j = 0;j < m;j++){
					out.print(((i + n * j + n * (m - i) * 2) % (n * m)) + 1 + " ");
				}
				out.println();
			}
		}else if(m == 2){
			for(int i = 0;i < n;i++){
				for(int j = 0;j < m;j++){
					out.print(((j + m * i + m * (n - j) * 2) % (n * m)) + 1 + " ");
				}
				out.println();
			}
		}else{
			throw new Error();
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
		new J().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}