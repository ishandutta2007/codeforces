import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*; 
import java.util.*;
import java.util.regex.*;

/*
		  br = new BufferedReader(new FileReader("input.txt"));
		  pw = new PrintWriter(new BufferedWriter(new FileWriter("output.txt")));
		  br = new BufferedReader(new InputStreamReader(System.in));
		  pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
 */

public class Main {
	private static BufferedReader br;
	private static StringTokenizer st;
	private static PrintWriter pw;

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			int x1 = readInt();
			int y1 = readInt();
			int x2 = readInt();
			int y2 = readInt();
			State[] l = new State[n];
			for(int i = 0; i < n; i++) {
				l[i] = new State(readInt(), readInt());
			}
			Arrays.sort(l, new DistComparator(x1, y1));
			long ret = dist(x1, y1, l[n-1].x, l[n-1].y);
			long max2 = 0;
			for(int i = n-1; i >= 0; i--) {
				max2 = Math.max(max2, dist(x2, y2, l[i].x, l[i].y));
				ret = Math.min(ret, max2 + (i == 0 ? 0 : dist(x1, y1, l[i-1].x, l[i-1].y)));
			}
			pw.println(ret);
		}
		exitImmediately();
	}

	public static long dist(int x1, int y1, int x2, int y2) {
		long x = x1 - x2;
		long y = y1 - y2;
		return x*x + y*y;
	}
	
	static class DistComparator implements Comparator<State> {
		public int x, y;

		public DistComparator(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}
		
		public int compare(State a, State b) {
			return Long.compare(dist(x, y, a.x, a.y), dist(x, y, b.x, b.y));
		}
		
	}
	
	static class State {
		public int x, y;

		public State(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}
		
	}
	
	private static void exitImmediately() {
		pw.close();
		System.exit(0);
	}

	private static long readLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	private static double readDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	private static int readInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	private static String nextLine() throws IOException  {
		String s = br.readLine();
		if(s == null) {
			exitImmediately();
		}
		st = null;
		return s;
	}

	private static String nextToken() throws IOException  {
		while(st == null || !st.hasMoreTokens())  {
			st = new StringTokenizer(nextLine().trim());
		}
		return st.nextToken();
	}
}