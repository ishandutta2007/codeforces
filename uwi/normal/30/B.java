//package round30;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {
	private Scanner in;
	private PrintWriter out;
//	private String INPUT = "31.12.18\n01.01.01";
//	private String INPUT = "01.01.98\n01.01.80";
//	private String INPUT = "29.02.96\n29.02.04";
//	private String INPUT = "20.10.20\n09.02.30";
//	private String INPUT = "01.03.74\n29.02.56";
	private String INPUT = "";
	
	public void solve()
	{
		in.useDelimiter("\\s*[\\.\\r\\n]+\\s*");
		int dd = ni();
		int mm = ni();
		int yy = ni();
		int[] t = new int[3];
		for(int i = 0;i < 3;i++)t[i] = ni();
		
		
//		String[] ds = in.next().split("\\.");
//		String[] db = in.next().split("\\.");
//
//		int dd = Integer.parseInt(ds[0]);
//		int mm = Integer.parseInt(ds[1]);
//		int yy = Integer.parseInt(ds[2]);
//		int[] t = new int[3];
//		for(int i = 0;i < 3;i++)t[i] = Integer.parseInt(db[i]);
		
		if(	test(dd, mm, yy, t[0], t[1], t[2]) ||
				test(dd, mm, yy, t[0], t[2], t[1]) ||
				test(dd, mm, yy, t[1], t[0], t[2]) ||
		test(dd, mm, yy, t[1], t[2], t[0]) ||
		test(dd, mm, yy, t[2], t[1], t[0]) ||
		test(dd, mm, yy, t[2], t[0], t[1])){
			out.println("YES");
		}else{
			out.println("NO");
		}
	}
	
	public boolean test(int dd, int mm, int yy, int bd, int bm, int by)
	{
		if(yy < by + 18)return false;
		if(bm > 12)return false;
		if(bd > 31)return false;
		
		int[] md = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		if(by % 4 == 0)md[2]++;
		if(bd > md[bm])return false;
		
		if(yy > by + 18)return true;
		if(bm != mm)return mm > bm;
		return dd >= bd;
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
	private void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}