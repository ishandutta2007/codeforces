//package round48;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Scanner;

public class A {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[][] am = new int[n][4];
		for(int i = 0;i < n;i++){
			String str = in.next();
			am[i][0] = str.charAt(0) - '0';
			am[i][1] = str.charAt(1) - '0';
			str = in.next();
			am[i][2] = str.charAt(0) - '0';
			am[i][3] = str.charAt(1) - '0';
			if(i < n - 1)in.next();
		}
		BitSet aned = new BitSet();
		for(int i = aned.nextClearBit(0);i < n;i = aned.nextClearBit(i+1)){
			int a = am[i][0], b = am[i][1], c = am[i][2], d = am[i][3];
			for(int j = aned.nextClearBit(i+1);j < n;j = aned.nextClearBit(j+1)){
				int e = am[j][0], f = am[j][1], g = am[j][2], h = am[j][3];
				if(e==a && f==b && g==c && h==d)aned.set(j);
				if(e==b && f==d && g==a && h==c)aned.set(j);
				if(e==d && f==c && g==b && h==a)aned.set(j);
				if(e==c && f==a && g==d && h==b)aned.set(j);
			}
		}
		out.println(n - aned.cardinality());
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
}