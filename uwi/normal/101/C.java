//package round79;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class C {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		long ax = ni();
		long ay = ni();
		long bx = ni();
		long by = ni();
		long cx = ni();
		long cy = ni();
		
		if(cx*cx+cy*cy == 0){
			if(bx==ax && by==ay){
				out.println("YES");
				return;
			}
			if(bx==ay && by==-ax){
				out.println("YES");
				return;
			}
			if(bx==-ax && by==-ay){
				out.println("YES");
				return;
			}
			if(bx==-ay && by==ax){
				out.println("YES");
				return;
			}
		}else{
			if(
					check(ax,ay,bx,by,cx,cy) ||
					check(ax,ay,by,-bx,cx,cy) ||
					check(ax,ay,-bx,-by,cx,cy) ||
					check(ax,ay,-by,bx,cx,cy)){
				out.println("YES");
				return;
			}
		}
		
		out.println("NO");
	}
	
	boolean check(long ax, long ay, long bx, long by, long cx, long cy)
	{
		long nk = (bx-ax)*cx+(by-ay)*cy;
		long nl = (bx-ax)*cy-(by-ay)*cx;
		long det = cx*cx+cy*cy;
		return (nk % det == 0 && nl % det == 0);
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
		new C().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}