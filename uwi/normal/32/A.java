//package round32;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A {
	private Scanner in;
	private PrintWriter out;
//	private String INPUT = "5 10 10 20 50 60 65";
//	private String INPUT = "5 1 55 30 29 31 55";
	private String INPUT = "";
	
	public void solve()
	{
		int n = ni();
		int d = ni();
		int[] h = new int[n];
		for(int i = 0;i < n;i++){
			h[i] = ni();
		}
		
		Arrays.sort(h);
		int ct = 0;
		int p = 0;
		for(int i = 0;i < n;i++){
			for(int j = i + 1;j < n;j++){
				if(h[j] - h[i] <= d){
					ct+=2;
				}else{
					break;
				}
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
	private void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}