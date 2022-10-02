//package round52;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		String[] alc = {
				"ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN",
				"RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE"
		};
		int ct = 0;
		for(int i = 0;i < n;i++){
			String x = in.next();
			if(x.charAt(0)>='0' && x.charAt(0)<='9'){
				int u = Integer.parseInt(x);
				if(u < 18)ct++;
			}else{
				for(String s : alc){
					if(s.equals(x)){
						ct++;
						break;
					}
				}
			}
		}
		out.println(ct);
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