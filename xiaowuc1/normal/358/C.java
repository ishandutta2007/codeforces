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

	public static void main(String[] args) throws Exception {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			int[] op = new int[n];
			final int STACK = -1;
			final int QUEUE = -2;
			final int FRONT = -3;
			final int BACK = -4;
			for(int i = 0; i < n; i++) {
				op[i] = readInt();
			}
			int[] loc = new int[n];
			Arrays.fill(loc, BACK);
			String[] ret = new String[n];
			PriorityQueue<State> q = new PriorityQueue<State>();
			for(int i = 0; i < n; i++) {
				if(op[i] == 0) {
					ArrayList<String> things = new ArrayList<String>();
					for(int a = 1; a <= 3 && !q.isEmpty(); a++) {
						State curr = q.poll();
						loc[curr.index] = -a;
						if(a == 1) things.add("popStack");
						else if(a == 2) things.add("popQueue");
						else if(a == 3) things.add("popFront");
						else throw new RuntimeException();
					}
					ret[i] = "" + things.size();
					for(String out: things) {
						ret[i] += " " + out;
					}
					q = new PriorityQueue<State>();
				}
				else {
					q.add(new State(i, op[i]));
				}
			}
			for(int i = 0; i < n; i++) {
				if(op[i] > 0) {
					if(loc[i] == STACK) ret[i] = "pushStack";
					else if(loc[i] == QUEUE) ret[i] = "pushQueue";
					else if(loc[i] == FRONT) ret[i] = "pushFront";
					else if(loc[i] == BACK) ret[i] = "pushBack";
					else throw new RuntimeException();
				}
			}
			for(String out: ret) {
				pw.println(out);
			}
		}
		exitImmediately();
	}

	static class State implements Comparable<State> {
		public int index;
		public int val;
		public State(int index, int val) {
			super();
			this.index = index;
			this.val = val;
		}
		public int compareTo(State s) {
			return s.val - val;
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