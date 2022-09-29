//package educational.round60;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class E {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		char[] x = in.next().toCharArray();
		int n = x.length;
		char[][] q = new char[3][n];
		for(int j = 0;j < n;j++){
			q[0][j] = (char)('a'+j/26/26);
			q[1][j] = (char)('a'+j/26%26);
			q[2][j] = (char)('a'+j%26);
		}
		char[][] r = new char[3][];
		for(int i = 0;i < 3;i++){
			out.println("? " + new String(q[i]));
			out.flush();
			r[i] = in.next().toCharArray();
		}
		
		int[] res = new int[n];
		for(int i = 0;i < n;i++){
			res[i] = (r[0][i]-'a')*26*26+(r[1][i]-'a')*26+(r[2][i]-'a');
		}
		char[] ans = new char[n];
		for(int i = 0;i < n;i++){
			ans[res[i]] = x[i];
		}
		out.println("! " + new String(ans));
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
		new E().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}