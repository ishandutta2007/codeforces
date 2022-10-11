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

	static int[][][][] dp;
	static int[][] prefix;
	
	public static void main(String[] args) throws Exception {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			State[] list = new State[n];
			for(int i = 0; i < n; i++) {
				list[i] = new State(readInt(), i);
			}
			Arrays.sort(list);
			int[] ret = new int[n];
			boolean bad = false;
			for(int i = 0; i < n; i++) {
				ret[i] = list[i].amt + list[i].index - i;
				if(i > 0 && ret[i] < ret[i-1]) {
					bad = true;
				}
			}
			if(bad) {
				pw.println(":(");
				continue;
			}
			StringBuilder sb = new StringBuilder();
			for(int out: ret) {
				sb.append(out + " ");
			}
			pw.println(sb.toString().trim());
		}
		exitImmediately();
	}
	
	static class State implements Comparable<State> {
		public int amt, index;
		public State(int a, int b) {
			amt = a;
			index = b;
		}
		public int score() {
			return amt + index;
		}
		public int compareTo(State s) {
			return score() - s.score();
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