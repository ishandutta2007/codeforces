//package round42;

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
		if(n == 1 && m == 1){
			out.println(0);
			out.println("1 1");
			out.println("1 1");
		}else if(m == 1 && n >= 3){
			out.println(1);
			out.println(1 + " " + 1 + " " + n + " " + 1);
			out.println("1 1");
			for(int i = n - 1;i >= 0;i--){
				out.println(i+1 + " "  + 1);
			}
		}else if(n == 1 && m >= 3){
			out.println(1);
			out.println(1 + " " + 1 + " " + 1 + " " + m);
			out.println("1 1");
			for(int i = m - 1;i >= 0;i--){
				out.println(1 + " "  + (i+1));
			}
		}else if(n % 2 == 1 && m % 2 == 1){
			out.println(1);
			out.println(n + " " + m + " " + n + " " + 1);
			out.println("1 1");
			for(int i = 0;i < n;i++){
				if(i % 2 == 0){
					for(int j = 1;j < m;j++){
						out.println((i+1) + " " + (j+1));
					}
				}else{
					for(int j = m - 1;j >= 1;j--){
						out.println((i+1) + " " + (j+1));
					}
				}
			}
			for(int i = n - 1;i >= 0;i--){
				out.println((i+1) + " " + 1);
			}
		}else if(n % 2 == 1){
			out.println(0);
			out.println("1 1");
			for(int i = 0;i < m;i++){
				if(i % 2 == 0){
					for(int j = 1;j < n;j++){
						out.println((j+1) + " " + (i+1));
					}
				}else{
					for(int j = n - 1;j >= 1;j--){
						out.println((j+1) + " " + (i+1));
					}
				}
			}
			for(int i = m - 1;i >= 0;i--){
				out.println(1 + " " + (i+1));
			}
		}else{
			out.println(0);
			out.println("1 1");
			for(int i = 0;i < n;i++){
				if(i % 2 == 0){
					for(int j = 1;j < m;j++){
						out.println((i+1) + " " + (j+1));
					}
				}else{
					for(int j = m - 1;j >= 1;j--){
						out.println((i+1) + " " + (j+1));
					}
				}
			}
			for(int i = n - 1;i >= 0;i--){
				out.println((i+1) + " " + 1);
			}
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
		new D().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}