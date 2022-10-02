//package round25;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {
	private Scanner in;
	private PrintWriter out;
	private String INPUT = "";
	
	public void solve()
	{
		int n = ni();
		String p = in.next();
		StringBuilder sb = new StringBuilder();
		int u = n % 2 == 1 ? n - 1 : n;
		for(int i = 0;i < u;i+=2){
			sb.append(p.substring(i, i + 2));
			if(i < u - 2)sb.append('-');
		}
		if(n % 2 == 1)sb.append(p.charAt(n - 1));
		out.println(sb.toString());
	}
	
	public void run() throws Exception
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
	
	private int ni() { return Integer.parseInt(in.next()); }
	private static void tr(Object... o) { System.out.println(o.length == 1 ? o[0] : Arrays.toString(o)); }
}