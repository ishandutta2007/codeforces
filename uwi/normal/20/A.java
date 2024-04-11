//package round20;


import java.io.BufferedOutputStream;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.io.StringReader;
import java.util.Arrays;
import java.util.Scanner;

public class B {
	private Scanner in;
	private PrintWriter out;
	
	public void solve()
	{
		String path = in.next();
		String[] sp = path.split("/");
		StringBuilder sb = new StringBuilder();
		sb.append('/');
		for(int i = 0;i < sp.length;i++){
			if(sp[i].isEmpty())continue;
			sb.append(sp[i]);
			if(i < sp.length - 1)sb.append('/');
		}
		out.println(sb.toString());
	}
	
	public void run() throws Exception
	{
//		in = new Scanner(new StringReader("//usr///local//nginx/sbin///"));
//		in = new Scanner(new StringReader("////"));
		in = new Scanner(System.in);
		System.setOut(new PrintStream(new BufferedOutputStream(System.out)));
		out = new PrintWriter(System.out);
		
//		int n = in.nextInt();
		int n = 1;
		for(int i = 1;i <= n;i++){
			long t = System.currentTimeMillis();
			solve();
			out.flush();
//			System.err.printf("%04d/%04d %7d%n", i, n, System.currentTimeMillis() - t);
		}
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new B().run();
	}
	
	private int ni() { return Integer.parseInt(in.next()); }
	private static void tr(Object... o) { System.out.println(o.length == 1 ? o[0] : Arrays.toString(o)); }
	private void tra(int[] a) {System.out.println(Arrays.toString(a));}
	private void tra(int[][] a)
	{
		for(int[] e : a){
			System.out.println(Arrays.toString(e));
		}
	}
	
}