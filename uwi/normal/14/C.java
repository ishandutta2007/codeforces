//package round14;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class C {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int[][] l = new int[4][4];
		for(int i = 0;i < 4;i++) {
			for(int j = 0;j < 4;j++) {
				l[i][j] = ni();
			}
		}
		boolean[] x = new boolean[4];
		boolean[] y = new boolean[4];
		int cx = 0, cy = 0;
		for(int i = 0;i < 4;i++) {
			if(l[i][0] == l[i][2]) {
				y[i] = true;
				cy++;
			}
			if(l[i][1] == l[i][3]) {
				x[i] = true;
				cx++;
			}
			if(x[i] && y[i]) {
				out.println("NO");
				return;
			}
		}
		if(cx == 2 && cy == 2) {
			long Q = 2*1000000000+2;
			long R = 1000000000;
			long[] cox = new long[4];
			long[] coy = new long[4];
			int cpx = 0, cpy = 0;
			for(int i = 0;i < 4;i++) {
				if(x[i]) {
					cox[cpx++] = (l[i][0]+R)*Q+l[i][1]+R;
					cox[cpx++] = (l[i][2]+R)*Q+l[i][3]+R;
				}
				if(y[i]) {
					coy[cpy++] = (l[i][0]+R)*Q+l[i][1]+R;
					coy[cpy++] = (l[i][2]+R)*Q+l[i][3]+R;
				}
			}
			Arrays.sort(cox);
			Arrays.sort(coy);
			for(int i = 0;i < 4;i++) {
				if(cox[i] != coy[i]) {
					out.println("NO");
					return;
				}
			}
			out.println("YES");
		}else {
			out.println("NO");
		}
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