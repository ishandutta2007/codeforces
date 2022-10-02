//package round26;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A {
	private Scanner in;
	private PrintWriter out;
	private String INPUT = "";
	
	public void solve()
	{
		int n = ni();
		int[] a = new int[n + 1];
		int ct = 0;
		for(int p = 2;p <= n;p++){
			if(a[p] == 0){
				for(int i = p;i <= n;i += p){
					a[i]++;
				}
			}else if(a[p] == 2){
				ct++;
			}
		}
		out.println(ct);
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
	private void tr(Object... o) { if(INPUT.length() == 0)System.out.println(o.length == 1 ? o[0] : Arrays.toString(o)); }
}