//package round33;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class C {
	private Scanner in;
	private PrintWriter out;
//	private String INPUT = "3 -1 -2 -3";
//	private String INPUT = "5 -4 2 0 5 0";
//	private String INPUT = "5 -1 10 -5 10 -2";
	private String INPUT = "";
	
	public void solve()
	{
		int n = ni();
		int[] a = new int[n];
		long sum = 0;
		for(int i = 0;i < n;i++){
			a[i] = ni();
			sum += a[i];
		}
		
		long[] psum = new long[n+1];
		long[] ssum = new long[n+1];
		long pcur = 0L;
		long scur = 0L;
		for(int i = 0;i < n;i++){
			pcur += -a[i];
			scur += -a[n-1-i];
			psum[i+1] = Math.max(psum[i], pcur);
			ssum[i+1] = Math.max(ssum[i], scur);
		}
		
		long max = 0L;
		for(int i = 0;i < n;i++){
			max = Math.max(max, psum[i] + ssum[n-i]);
		}
		
		out.println(sum + 2 * max);
	}
	
	public void run() throws Exception
	{
//		Random r = new Random();
//		StringBuilder sb = new StringBuilder("100000 ");
//		for(int i = 0;i < 100000;i++){
//			sb.append(r.nextInt(20002) - 10001);
//			sb.append(' ');
//		}
		
//		INPUT = sb.toString();
		
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
	private void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}