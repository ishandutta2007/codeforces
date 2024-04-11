//package round57;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		String[] a = new String[3];
		for(int i = 0;i < 3;i++){
			a[i] = trim(in.next());
		}
		
		String[] q = {
				a[0]+a[1]+a[2],
				a[0]+a[2]+a[1],
				a[1]+a[0]+a[2],
				a[1]+a[2]+a[0],
				a[2]+a[0]+a[1],
				a[2]+a[1]+a[0]
		};
		
		int n = ni();
		outer:
		for(int i = 0;i < n;i++){
			String s = trim(in.next());
			for(int j = 0;j < 6;j++){
				if(s.equals(q[j])){
					out.println("ACC");
					continue outer;
				}
			}
			out.println("WA");
		}
	}
	
	String trim(String s)
	{
		StringBuilder sb = new StringBuilder();
		for(int i = 0;i < s.length();i++){
			char c = s.charAt(i);
			if(c == '_' || c == ';' || c == '-'){
				
			}else{
				sb.append(c);
			}
		}
		return sb.toString().toLowerCase();
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
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}