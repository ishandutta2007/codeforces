//package round57;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		char[] a = in.next().toCharArray();
		char[] b = in.next().toCharArray();
		char[] ret = new char[a.length];
		for(int i = 0;i < a.length;i++){
			int aa = a[i] - '0';
			int bb = b[i] - '0';
			ret[i] = (char)('0' + (aa^bb));
		}
		out.println(new String(ret));
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
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}