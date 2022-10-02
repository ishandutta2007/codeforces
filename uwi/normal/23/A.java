//package round23;

import java.io.PrintWriter;
import java.io.StringReader;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;

public class A {
	private Scanner in;
	private PrintWriter out;
//	private String INPUT = add("a", 100);
	private String INPUT = "";
	
	public void solve()
	{
		String str = in.next();
		int n = str.length();
		for(int k = n - 1;k >= 1;k--){
			HashSet<String> set = new HashSet<String>();
			for(int i = 0;i < str.length() - k + 1;i++){
				if(!set.add(str.substring(i, i + k))){
					out.println(k);
					return;
				}
			}
		}
		out.println(0);
	}
	
	public void run() throws Exception
	{
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(new StringReader(INPUT));
		out = new PrintWriter(System.out);
		
		solve();
		out.flush();
	}
	
	public static String add(String str, int k)
	{
		StringBuilder mul = new StringBuilder(str);
		StringBuilder ret = new StringBuilder();
		for(int i = k;i > 0;i >>= 1){
			if((i & 1) == 1)ret.append(mul);
			mul.append(mul);
		}
		return ret.toString();
	}
	
	public static void main(String[] args) throws Exception
	{
		new A().run();
	}
	
	private int ni() { return Integer.parseInt(in.next()); }
	private static void tr(Object... o) { System.out.println(o.length == 1 ? o[0] : Arrays.toString(o)); }
}