//package round30;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A {
	private Scanner in;
	private PrintWriter out;
//	private String INPUT = "2 18 2";
//	private String INPUT = "1 1025 10";
//	private String INPUT = "-1 1024 10";
	private String INPUT = "";
	
	public void solve()
	{
		int a = ni();
		int b = ni();
		int n = ni();
		if(b == 0){
			out.println(0);
		}else{
			if(a != 0 && b % a == 0){
				boolean minus = b / a < 0;
				int ab = Math.abs(b / a);
				int x = (int)Math.round(Math.pow(ab, (double)1 / (double)n));
//				tr(ab , x, minus, n);
				
				long mul = 1;
				int i;
				for(i = 0;i < n && mul <= ab;i++){
					mul *= x;
				}
				if(mul == ab && i == n && (!minus || n % 2 == 1)){
					out.println(minus ? -x : x);
				}else{
					out.println("No solution");
				}
			}else{
				out.println("No solution");
			}
		}
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