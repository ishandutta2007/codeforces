import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.security.*;
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

	static final int SENTINEL = 1000000;

	static boolean transpose;

	public static void main(String[] args) throws Exception {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			int m = readInt();
			transpose = false;
			if(n > m) {
				int a = n;
				n = m;
				m = a;
				transpose = true;
			}
			Interval[] intervals = new Interval[n];
			for(int i = 0; i < n; i++) {
				intervals[i] = new Interval(m);
			}
			int qqq = readInt();
			while(qqq-- > 0) {
				int x = readInt()-1;
				int y = readInt()-1;
				if(transpose) {
					int t = x;
					x = y;
					y = t;
				}
				int rx = 1 << 26;
				int ry = 1 << 26;
				int ret = n+m;
				for(int diff = 0; diff <= ret; diff++) {
					for(int k = -1; k <= 1; k+=2) {
						int xCand = x + k * diff;
						if(xCand < 0 || xCand >= n) continue;
						int yCand = intervals[xCand].floor(y);
						if(valid(xCand, yCand, x, y, ret, rx, ry)) {
							ret = Math.abs(xCand - x) + Math.abs(yCand - y);
							rx = xCand;
							ry = yCand;
						}
						yCand = intervals[xCand].ceiling(y);
						if(valid(xCand, yCand, x, y, ret, rx, ry)) {
							ret = Math.abs(xCand - x) + Math.abs(yCand - y);
							rx = xCand;
							ry = yCand;
						}
					}
				}
				if(transpose) {
					pw.println((ry+1) + " " + (rx+1));
				}
				else {
					pw.println((rx+1) + " " + (ry+1));
				}
				intervals[rx].delete(ry);
			}
		}
		exitImmediately();
	}

	public static boolean valid(int cx, int cy, int x, int y, int ans, int rx, int ry) {
		int curr = Math.abs(cx - x) + Math.abs(cy - y);
		if(curr < ans) return true;
		if(curr == ans) {
			if(!transpose) {
				if(cx < rx) {
					return true;
				}
				if(cx == rx && cy < ry) {
					return true;
				}
			}
			else {
				if(cy < ry) {
					return true;
				}
				if(cy == ry && cx < rx) {
					return true;
				}
			}
		}
		return false;
	}

	static class Interval {
		public int[] ceilingInterval;
		public int[] floorInterval;
		public int size;
		public boolean firstDeleted;
		public boolean lastDeleted;
		public Interval(int n) {
			size = n;
			ceilingInterval = new int[n];
			floorInterval = new int[n];
			for(int i = 0; i < n; i++) {
				ceilingInterval[i] = floorInterval[i] = i;
			}
		}
		public void delete(int v) {
			if(v == 0) firstDeleted = true;
			else floorInterval[v] = find(floorInterval, v-1);

			if(v == size-1) lastDeleted = true;
			else ceilingInterval[v] = find(ceilingInterval, v+1);
		}
		private int find(int[] interval, int x) {
			if(interval[x] == x) return interval[x];
			interval[x] = find(interval, interval[x]);
			return interval[x];
		}
		public int floor(int k) {
			int ret = find(floorInterval, k);
			if(ret == 0 && firstDeleted) {
				ret = -SENTINEL;
			}
			return ret;
		}
		public int ceiling(int k) {
			int ret = find(ceilingInterval, k);
			if(ret == size - 1 && lastDeleted) {
				ret = SENTINEL;
			}
			return ret;
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
		if(!br.ready()) {
			exitImmediately();
		}
		st = null;
		return br.readLine();
	}

	private static String nextToken() throws IOException  {
		while(st == null || !st.hasMoreTokens())  {
			if(!br.ready()) {
				exitImmediately();
			}
			st = new StringTokenizer(br.readLine().trim());
		}
		return st.nextToken();
	}
}