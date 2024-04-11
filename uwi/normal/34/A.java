//package round34;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A {
	private Scanner in;
	private PrintWriter out;
//	private String INPUT = "5 10 12 13 15 10";
//	private String INPUT = "4 10 20 30 40";
	private String INPUT = "";
	
	public void solve()
	{
		int n = ni();
		int[] a = new int[n+1];
		for(int i = 0;i < n;i++){
			a[i] = ni();
		}
		a[n] = a[0];
		
		int min = Integer.MAX_VALUE;
		int mini = -1;
		for(int i = 0;i < n;i++){
			if(min > Math.abs(a[i+1] - a[i])){
				min = Math.abs(a[i+1] - a[i]);
				mini = i;
			}
		}
		
		out.println((mini+1) + " " + (((mini+1)%n)+1));
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
		new A().run();
	}
	
	private int ni() { return Integer.parseInt(in.next()); }
	private void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}