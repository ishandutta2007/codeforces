//package round42;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class A {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		HashMap<String, Integer> x = new HashMap<String, Integer>();
		for(int i = 0;i < n;i++){
			String s = in.next();
			if(!x.containsKey(s)){
				x.put(s, 0);
			}
			x.put(s, x.get(s) + 1);
		}
		
		String max = "";
		int maxw = 0;
		for(Map.Entry<String, Integer> e : x.entrySet()){
			if(maxw < e.getValue()){
				max = e.getKey();
				maxw = e.getValue();
			}
		}
		out.println(max);
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