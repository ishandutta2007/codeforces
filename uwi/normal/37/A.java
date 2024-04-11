//package round37;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A {
	Scanner in;
	PrintWriter out;
//	String INPUT = "3 1 2 3";
//	String INPUT = "4 6 5 6 7";
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] l = new int[n];
		for(int i = 0;i < n;i++){
			l[i] = ni();
		}
		
		int[] ct = new int[1001];
		for(int i = 0;i < n;i++){
			ct[l[i]]++;
		}
		
		int ctct = 0;
		int ml = 0;
		for(int i = 0;i < ct.length;i++){
			if(ct[i] > 0){
				ctct++;
			}
			ml = Math.max(ct[i], ml);
		}
		out.println(ml + " " + ctct);
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
		new A().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
	static String join(int[] a, int d){StringBuilder sb = new StringBuilder();for(int v : a){sb.append(v + d + " ");}return sb.toString();}
}