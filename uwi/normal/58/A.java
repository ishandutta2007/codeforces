//package round54;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		String line = in.next();
		int f = 0;
		String hello = "hello";
		for(int i = 0;i < line.length();i++){
			char c = line.charAt(i);
			if(c == hello.charAt(f)){
				f++;
				if(f == 5){
					out.println("YES");
					return;
				}
			}
		}
		out.println("NO");
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