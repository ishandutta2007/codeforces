import java.awt.*;
import java.awt.event.*;
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
			int[] aSum = new int[n+1];
			int[] bSum = new int[n+1];
			for(int i = 1; i <= n; i++) {
				aSum[i] = aSum[i-1];
				bSum[i] = bSum[i-1];
				if(readInt() == 1) {
					aSum[i]++;
				}
				else {
					bSum[i]++;
				}
			}
			int[] aFirst = new int[n+1];
			int[] bFirst = new int[n+1];
			Arrays.fill(aFirst, Integer.MAX_VALUE);
			Arrays.fill(bFirst, Integer.MAX_VALUE);
			for(int i = 0; i < aSum.length; i++) {
				aFirst[aSum[i]] = Math.min(aFirst[aSum[i]], i);
				bFirst[bSum[i]] = Math.min(bFirst[bSum[i]], i);
			}
			ArrayList<State> ret = new ArrayList<State>();
			for(int t = 1; t <= n; t++) {
				int aWin = 0;
				int bWin = 0;
				int start = 0;
				int lastWin = -1;
				while(start < n) {
					int aNeed = aSum[start] + t;
					int bNeed = bSum[start] + t;
					int aIndex = aNeed < aFirst.length ? aFirst[aNeed] : Integer.MAX_VALUE;
					int bIndex = bNeed < bFirst.length ? bFirst[bNeed] : Integer.MAX_VALUE;
					if(Math.min(aIndex, bIndex) == Integer.MAX_VALUE) {
						start = Integer.MAX_VALUE;
						break;
					}
					if(aIndex < bIndex) {
						start = aIndex;
						aWin++;
						lastWin = 1;
					}
					else {
						start = bIndex;
						bWin++;
						lastWin = 2;
					}
				}
				if(start == n) {
					if(aWin > bWin && lastWin == 1) {
						ret.add(new State(aWin, t));
					}
					if(bWin > aWin && lastWin == 2) {
						ret.add(new State(bWin, t));
					}
				}
			}
			Collections.sort(ret);
			pw.println(ret.size());
			for(State out: ret) {
				pw.println(out);
			}
		}
		exitImmediately();
	}

	static class State implements Comparable<State> {
		public int x, y;
		public State(int a, int b) {
			x=a;
			y=b;
		}
		public String toString() {
			return x + " " + y;
		}
		public int compareTo(State s) {
			if(x == s.x) return y - s.y;
			return x - s.x;
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