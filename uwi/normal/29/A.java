//package round29;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A {
	private Scanner in;
	private PrintWriter out;
//	private String INPUT = "3 0 1 1 1 2 -2";
	private String INPUT = "";
//	private String INPUT = "5 2 -10 3 10 0 5 5 -5 10 1";
	
	public void solve()
	{
		int n = ni();
		int[] x = new int[n];
		int[] d = new int[n];
		for(int i = 0;i < n;i++){
			x[i] = ni();
			d[i] = ni();
		}
		for(int i = 0;i < n;i++){
			for(int j = 0;j < i;j++){
				if(x[i] + d[i] == x[j] && x[j] + d[j] == x[i]){
					out.println("YES");
					return;
				}
			}
		}
		out.println("NO");
		return;
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