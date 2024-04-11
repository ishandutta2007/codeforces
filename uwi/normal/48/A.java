//package round45;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		String f = in.next();
		String m = in.next();
		String s = in.next();
		String R = "rock";
		String S = "scissors";
		String P = "paper";
		if(f.equals(R) && m.equals(S) && s.equals(S)){ out.println("F"); return; }
		if(f.equals(S) && m.equals(P) && s.equals(P)){ out.println("F"); return; }
		if(f.equals(P) && m.equals(R) && s.equals(R)){ out.println("F"); return; }
		if(m.equals(R) && s.equals(S) && f.equals(S)){ out.println("M"); return; }
		if(m.equals(S) && s.equals(P) && f.equals(P)){ out.println("M"); return; }
		if(m.equals(P) && s.equals(R) && f.equals(R)){ out.println("M"); return; }
		if(s.equals(R) && f.equals(S) && m.equals(S)){ out.println("S"); return; }
		if(s.equals(S) && f.equals(P) && m.equals(P)){ out.println("S"); return; }
		if(s.equals(P) && f.equals(R) && m.equals(R)){ out.println("S"); return; }
		out.println("?");
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