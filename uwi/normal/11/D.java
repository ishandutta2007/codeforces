//package round11;


import java.io.BufferedOutputStream;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.io.StringReader;
import java.util.Arrays;
import java.util.Scanner;

public class D {
	private Scanner in;
	private PrintWriter out;
	
	private boolean[][] g;
	
	public void solve()
	{
		n = ni();
		int m = ni();
		g = new boolean[n][n];
		for(int i = 0;i < m;i++){
			int f = ni();
			int t = ni();
			g[f-1][t-1] = true;
			g[t-1][f-1] = true;
		}
		
		long ret = 0L;
		cache = new long[20 << 19];
		for(int i = 0;i < n;i++){
			start = i;
			ret += rec(1 << start, i, 0);
		}
		out.println(ret/2);
	}
	
	private long[] cache;
	private int n;
	private int start;
	
	private long rec(int passed, int cur, int depth)
	{
		int code = cur << 19 | passed;
		if(cache[code] != 0)return cache[code];
		long ret = 0L;
		
		if(g[cur][start] && depth >= 2)ret++;
		for(int i = start + 1;i < n;i++){
			if((passed & (1 << i)) == 0 && g[cur][i]){
				ret += rec(passed | (1 << i), i, depth + 1);
			}
		}
		
		cache[code] = ret;
		return ret;
	}
	
	public void run() throws Exception
	{
//		int m = 19;
//		StringBuilder sb = new StringBuilder();
//		sb.append(m + " ");
//		sb.append((m*(m-1)/2) + " ");
//		for(int i = 1;i <= m;i++){
//			for(int j = i + 1;j <= m;j++){
//				sb.append(i + " " + j + "\n");
//			}
//		}
//		
//		in = new Scanner(new StringReader(sb.toString()));
//		in = new Scanner(new StringReader("4 6 1 2 1 3 1 4 2 3 2 4 3 4"));
		in = new Scanner(System.in);
		System.setOut(new PrintStream(new BufferedOutputStream(System.out)));
		out = new PrintWriter(System.out);
		
//		int n = in.nextInt();
		int n = 1;
		for(int i = 1;i <= n;i++){
			long t = System.currentTimeMillis();
			solve();
			out.flush();
			System.err.printf("%04d/%04d %7d%n", i, n, System.currentTimeMillis() - t);
		}
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new D().run();
	}
	
	private int ni() { return Integer.parseInt(in.next()); }
	private static void tr(Object... o) { System.out.println(o.length == 1 ? o[0] : Arrays.toString(o)); }
	private void tra(int[] a) {System.out.println(Arrays.toString(a));}
	private void tra(int[][] a)
	{
		for(int[] e : a){
			System.out.println(Arrays.toString(e));
		}
	}
	
}