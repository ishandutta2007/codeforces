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
		int qq = 1;
		//int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++) {
			int n = readInt();
			int[] list = new int[n];
			for(int i = 0; i < n; i++) {
				list[i] = readInt();
			}
			PriorityQueue<State> q = new PriorityQueue<State>();
			int qqq = readInt();
			long[] ret = new long[qqq];
			for(int i = 0; i < qqq; i++) {
				q.add(new State(readInt()-1, readInt(), i));
			}
			int lastB = -1;
			long[] dp = null;
			while(!q.isEmpty()) {
				State curr = q.poll();
				if(curr.b >= Math.sqrt(n)) {
					for(int i = curr.a; i < n; i += curr.b) {
						ret[curr.index] += list[i];
					}
					continue;
				}
				if(lastB != curr.b) {
					dp = new long[n];
					for(int i = n-1; i >= 0; i--) {
						if(i + curr.b < n) {
							dp[i] = dp[i+curr.b] + list[i];
						}
						else {
							dp[i] = list[i];
						}
					}
					lastB = curr.b;
				}
				ret[curr.index] = dp[curr.a];
			}
			for(long out: ret) {
				pw.println(out);
			}
		}
		exitImmediately();
	}

	static class State implements Comparable<State> {
		public int a, b;
		public int index;
		public State(int x, int y, int z) {
			a=x;
			b=y;
			index=z;
		}
		public int compareTo(State s) {
			return b - s.b;
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