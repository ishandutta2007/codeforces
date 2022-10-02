//package round36;

import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A {
	Scanner in;
	PrintWriter out;
//	String INPUT = "8 00111000";
//	String INPUT = "7 1001011";
//	String INPUT = "7 1010100";
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		char[] s = in.next().toCharArray();
		int prev = -1;
		int inv = -1;
		for(int i = 0;i < n;i++){
			if(s[i] == '1'){
				if(prev != -1){
					int ii = i - prev;
					if(inv == -1){
						inv = ii;
					}else{
						if(inv != ii){
							out.println("NO");
							return;
						}
					}
				}
				prev = i;
			}
		}
		out.println("YES");
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
		new A().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
	static String join(int[] a, int d){StringBuilder sb = new StringBuilder();for(int v : a){sb.append(v + d + " ");}return sb.toString();}
}