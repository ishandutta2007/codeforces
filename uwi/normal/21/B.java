//package round21;


import java.io.PrintWriter;
import java.io.StringReader;
import java.util.Arrays;
import java.util.Scanner;

public class B {
	private Scanner in;
	private PrintWriter out;
	private String INPUT = "";
	
	public void solve()
	{
		int a1 = ni();
		int b1 = ni();
		int c1 = ni();
		int a2 = ni();
		int b2 = ni();
		int c2 = ni();
		
		int D = a1 * b2 - a2 * b1;
		if(D == 0){
			if(a1 != 0){
				if(a1 * c2 - a2 * c1 == 0){
					out.println(-1);
				}else{
					out.println(0);
				}
			}else if(b1 != 0){
				if(b1 * c2 - b2 * c1 == 0){
					out.println(-1);
				}else{
					out.println(0);
				}
			}else{
				if(c1 == 0){
					if(a2 != 0 || b2 != 0 || c2 == 0){
						out.println(-1);
					}else{
						out.println(0);
					}
				}else{
					out.println(0);
				}
			}
		}else{
			out.println(1);
		}
	}
	
	public void run() throws Exception
	{
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(new StringReader(INPUT));
		out = new PrintWriter(System.out);
		
		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new B().run();
	}
	
	private int ni() { return Integer.parseInt(in.next()); }
	private static void tr(Object... o) { System.out.println(o.length == 1 ? o[0] : Arrays.toString(o)); }
}