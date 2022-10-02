//package round38;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class E {
	Scanner in;
	PrintWriter out;
//	String INPUT = "3 2 3 3 4 1 2";
//	String INPUT = "4 1 7 3 1 5 10 6 1";
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		Marble[] m = new Marble[n];
		for(int i = 0;i < n;i++){
			m[i] = new Marble(ni(), ni());
		}
		Arrays.sort(m);
		
		long[][] f = new long[n][n];
		f[0][0] = m[0].c;
		
		for(int i = 1;i < n;i++){
			for(int j = 0;j < i;j++){
				f[i][j] = f[i-1][j] + (m[i].x - m[j].x);
			}
			long min = Long.MAX_VALUE;
			for(int j = 0;j < i;j++){
				min = Math.min(min, f[i-1][j]);
			}
			f[i][i] = min + m[i].c;
		}
		
		long mina = Long.MAX_VALUE;
		for(int j = 0;j < n;j++){
			mina = Math.min(mina, f[n-1][j]);
		}
		out.println(mina);
	}
	
	static class Marble implements Comparable<Marble> {
		public int x;
		public int c;
		public Marble(int x, int c)
		{
			this.x = x;
			this.c = c;
		}
		
		public int compareTo(Marble targ)
		{
			return this.x - targ.x;
		}
	}
	
	void run() throws Exception
	{
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new E().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}