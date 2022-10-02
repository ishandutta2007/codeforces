//package round43;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class C {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		char[] x = in.next().toCharArray();
		int t = 0;
		for(int i = 0;i < n;i++){
			if(x[i] == 'T'){
				t++;
			}
		}
		
		int min = 9999;
		for(int i = 0;i < n;i++){
			int y = 0;
			for(int j = i;j < i + t;j++){
				if(x[j % n] == 'T'){
					y++;
				}
			}
			min = Math.min(min, t - y);
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
		new C().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}