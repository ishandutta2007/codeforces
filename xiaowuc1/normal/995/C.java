import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

public class C {
	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter pw;

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++) {
			int n = readInt();
			ArrayList<State> l = new ArrayList<>();
			for(int i = 0; i < n; i++) {
				l.add(new State(readLong(), readLong(), i));
			}
			while(true) {
				Collections.shuffle(l);
				long x = 0;
				long y = 0;
				int[] ret = new int[n];
				for(State out: l) {
					long xInc = x + out.x;
					long yInc = y + out.y;
					long xDec = x - out.x;
					long yDec = y - out.y;
					if(xInc*xInc+yInc*yInc > xDec*xDec+yDec*yDec) {
						x = xDec;
						y = yDec;
						ret[out.i] = -1;
					}
					else {
						x = xInc;
						y = yInc;
						ret[out.i] = 1;
					}
				}
				if(x*x+y*y >= 1500000L*1500000) continue;
				for(int i = 0; i < n; i++) {
					pw.print(ret[i]);
					if(i == n-1) pw.println();
					else pw.print(" ");
				}
				break;
			}
		}
		pw.close();
	}

	static class State implements Comparable<State> {
		public long x, y;
		public int i;
		public State(long x, long y, int i) {
			super();
			this.x = x;
			this.y = y;
			this.i = i;
		}
		public long mag() {
			return x*x+y*y;
		}
		public int compareTo(State s) {
			return Long.compare(s.mag(), mag());
		}
	}

	public static void exitImmediately() {
		pw.close();
		System.exit(0);
	}

	public static int readInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	public static double readDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	public static long readLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	public static String nextLine() throws IOException {
		st = null;
		if(!br.ready()) {
			exitImmediately();
		}
		return br.readLine();
	}

	public static String nextToken() throws IOException {
		while(st == null || !st.hasMoreTokens()) {
			if(!br.ready()) {
				exitImmediately();
			}
			st = new StringTokenizer(br.readLine());
		}
		return st.nextToken();
	}
}