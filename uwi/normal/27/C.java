//package round27;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class C {
	private Scanner in;
	private PrintWriter out;
//	private String INPUT = "5 6 4 5 5 4";
//	private String INPUT = "5 0 1 1 1 0";
//	private String INPUT = "5 1 1 1 1 1";
//	private String INPUT = "5 1 1 1 1 2";
//	private String INPUT = "5 2 1 1 1 1";
//	private String INPUT = "5 5 4 3 2 1";
//	private String INPUT = "6 1 3 4 4 2 5";
//	private String INPUT = "7 1 1 2 2 3 3 2";
	private String INPUT = "";
	
	public void solve()
	{
		int n = ni();
		int pi = -1;
		int p = Integer.MAX_VALUE;
		int ppi = -1;
		int pp = Integer.MAX_VALUE;
		for(int i = 0;i < n;i++){
			int c = ni();
			if(ppi != -1 && ((pp < p && p > c) || (pp > p && p < c))){
				out.println(3);
				out.println((ppi+1) + " " + (pi+1) + " " + (i+1));
				return;
			}
			if(p != c){
				pp = p;
				ppi = pi;
				p = c;
				pi = i;
			}
		}
		out.println(0);
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
		new C().run();
	}
	
	private int ni() { return Integer.parseInt(in.next()); }
	private void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length == 1 ? o[0] : Arrays.toString(o)); }
}