//package round55;

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
		char[] str = line.toCharArray();
		int lower = 0;
		for(char c : str){
			if(c >= 'a' && c <= 'z'){
				lower++;
			}
		}
		if(lower >= str.length - lower){
			out.println(line.toLowerCase());
		}else{
			out.println(line.toUpperCase());
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
		new A().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}