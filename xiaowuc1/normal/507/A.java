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
		for(int casenum = 1; casenum <= qq; casenum++) {
			int n = readInt();
			int max = readInt();
			PriorityQueue<State> q = new PriorityQueue<State>();
			for(int i = 1; i <= n; i++) {
				q.add(new State(i, readInt()));
			}
			ArrayList<Integer> ret = new ArrayList<Integer>();
			while(!q.isEmpty()) {
				State curr = q.poll();
				if(curr.val <= max) {
					max -= curr.val;
					ret.add(curr.index);
				}
			}
			StringBuilder sb = new StringBuilder();
			for(int out: ret) {
				sb.append(out + " ");
			}
			pw.println(ret.size());
			pw.println(sb.toString().trim());
		}
		exitImmediately();
	}

	static class State implements Comparable<State> {
		public int index, val;
		public State(int a, int b) {
			index = a;
			val = b;
		}
		public int compareTo(State s) {
			return val - s.val;
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