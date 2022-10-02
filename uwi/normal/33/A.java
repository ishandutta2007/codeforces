//package round33;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A {
	private Scanner in;
	private PrintWriter out;
//	private String INPUT = "4 3 18 2 3 1 2 3 6 2 3";
//	private String INPUT = "2 2 13 1 13 2 12";
	private String INPUT = "";
	
	public void solve()
	{
		int n = ni();
		int m = ni();
		int k = ni();
		int[] min = new int[m];
		int SUP = 1000001;
		Arrays.fill(min, SUP);
		for(int i = 0;i < n;i++){
			int r = ni() - 1;
			int c = ni();
			min[r] = Math.min(min[r], c);
		}
		
		int sum = 0;
		for(int i = 0;i < m;i++){
			if(min[i] != SUP)sum += min[i];
		}
		
		sum = Math.min(k, sum);
		out.println(sum);
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