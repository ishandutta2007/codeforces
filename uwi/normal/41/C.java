//package round40;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class C {
	Scanner in;
	PrintWriter out;
//	String INPUT = "aatt";
//	String INPUT = "dotdotdotatdotdotat";
//	String INPUT = "vasyaatgmaildotcom";
	String INPUT = "";
	
	void solve()
	{
		char[] ad = in.next().toCharArray();
		int n = ad.length;
		StringBuilder sb = new StringBuilder();
		boolean at = false;
		for(int i = 0;i < n;){
			if(i > 0 && i < n - 3 && ad[i] == 'd' && ad[i+1] == 'o' && ad[i+2] == 't'){
				sb.append('.');
				i += 3;
			}else if(i > 0 && i < n - 2 && !at && ad[i] == 'a' && ad[i+1] == 't'){
				sb.append('@');
				at = true;
				i += 2;
			}else{
				sb.append(ad[i]);
				i++;
			}
		}
		out.println(sb);
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
		new C().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}