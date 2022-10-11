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
			State[] l = new State[n];
			for(int i = 0; i < n; i++) {
				int time = readInt();
				int dead = readInt();
				int v = readInt();
				l[i] = new State(i, time, dead, v);
			}
			Arrays.sort(l);
			int[][] dp = new int[n+1][2001];
			for(int i = 0; i <= n; i++) {
				Arrays.fill(dp[i], -1);
			}
			dp[0][0] = 0;
			for(int i = 0; i < n; i++) {
				for(int a = 0; a + l[i].timeToRescue < l[i].deadline; a++) {
					if(dp[i][a] < 0) continue;
					dp[i+1][a+l[i].timeToRescue] = Math.max(dp[i+1][a+l[i].timeToRescue], dp[i][a] + l[i].value); 
				}
				for(int a = 0; a < dp[i].length; a++) {
					dp[i+1][a] = Math.max(dp[i+1][a], dp[i][a]);
				}
			}
			int bestT = 0;
			for(int i = 1; i <= 2000; i++) {
				if(dp[n][i] > dp[n][bestT]) {
					bestT = i;
				}
			}
			pw.println(dp[n][bestT]);
			LinkedList<Integer> all = new LinkedList<Integer>();
			for(int i = n; i > 0; i--) {
				if(dp[i][bestT] != dp[i-1][bestT]) {
					all.addFirst(l[i-1].index+1);
					bestT -= l[i-1].timeToRescue;
				}
			}
			pw.println(all.size());
			for(int out: all) {
				pw.print(out);
				pw.print(" ");
			}
			pw.println();
		}
		exitImmediately();
	}

	static class State implements Comparable<State> {
		public int index;
		public int timeToRescue;
		public int deadline;
		public int value;
		public State(int index, int timeToRescue, int deadline, int value) {
			super();
			this.index = index;
			this.timeToRescue = timeToRescue;
			this.deadline = deadline;
			this.value = value;
		}
		public int compareTo(State s) {
			return deadline - s.deadline;
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