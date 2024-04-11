//package round504;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class E2 {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
//	String INPUT = "5 NO NO YES NO YES YES YES";
//	String INPUT = "5 YES YES YES YES YES YES YES";
//	String INPUT = "5 YES YES YES YES YES YES YES";

//	String INPUT = "";
	// .#
	// ..
	
	// .....
	// .###.
	// ..##.
	// ....#
	// ..#..
	
	int n;
	
	boolean ok(int r1, int c1, int r2, int c2)
	{
		if(r1 > r2)return false;
		if(c1 > c2)return false;
		if(r2 > n)return false;
		if(c2 > n)return false;
		if(r1 < 1)return false;
		if(c1 < 1)return false;
		out.printf("? %d %d %d %d\n", r1, c1, r2, c2);
		out.flush();
		return in.next().trim().equals("YES");
	}
	
	void solve()
	{
		n = ni();
		int r = 1, c = 1;
		StringBuilder sbf = new StringBuilder();
		while(r+c < n+1){
			if(ok(r, c+1, n, n)){
				sbf.append("R");
				c++;
			}else{
				sbf.append("D");
				r++;
			}
		}
		
		StringBuilder sbb = new StringBuilder();
		r = n; c = n;
		while(r+c > n+1){
			if(ok(1, 1, r-1, c)){
				sbb.append("D");
				r--;
			}else{
				sbb.append("R");
				c--;
			}
		}
		
		out.print("! ");
		out.print(sbf);
		out.print(sbb.reverse());
		out.println();
		out.flush();
	}
	
	void run() throws Exception
	{
		in = oj ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception
	{
		new E2().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}