//package round44;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		char[][] q = new char[3][3];
		for(int i = 0;i < 3;i++){
			q[i] = in.next().toCharArray();
		}
		int[] ok = null;
		int[][] pe = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};
		
		for(int[] p : pe){
			if(check(p, q)){
				if(ok != null){
					out.println("Impossible");
					return;
				}
				ok = p;
			}
		}
		if(ok == null){
			out.println("Impossible");
		}else{
			char[] oo = new char[3];
			for(int i = 0;i < 3;i++){
				oo[ok[i]] = (char)('A' + i);
			}
			out.println(new String(oo));
		}
	}
	
	boolean check(int[] p, char[][] q)
	{
		for(int i = 0;i < 3;i++){
			int l = p[q[i][0]-'A'];
			char qq = q[i][1];
			int r = p[q[i][2]-'A'];
			if(qq == '<'){
				if(!(l < r)){
					return false;
				}
			}else{
				if(!(l > r)){
					return false;
				}
			}
		}
		return true;
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