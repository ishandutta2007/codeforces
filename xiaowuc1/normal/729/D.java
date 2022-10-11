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
			int c = readInt();
			int w = readInt();
			st = null;
			String s = nextLine();
			PriorityQueue<State> q = new PriorityQueue<State>();
			int have = 0;
			for(int i = 0; i < s.length();) {
				if(s.charAt(i) == '1') {
					i++;
					continue;
				}
				int j = i+1;
				while(j < s.length() && s.charAt(j) == '0') {
					 j++;
				}
				if(j-i >= w) {
					q.add(new State(i+1, j));
					have += (j-i)/w;
				}
				i = j;
			}
			ArrayList<Integer> ret = new ArrayList<>();
			while(have-- >= c) {
				State curr = q.poll();
				ret.add(curr.l + w - 1);
				if((curr.r - curr.l + 1) / w >= 2) {
					q.add(new State(curr.l + w, curr.r));
				}
			}
			pw.println(ret.size());
			for(int i = 0; i < ret.size(); i++) {
				pw.print(ret.get(i));
				if(i == ret.size()-1) pw.println();
				else pw.print(" ");
			}
		}
		exitImmediately();
	}

	static class State implements Comparable<State> {
		public int l, r;

		public State(int l, int r) {
			super();
			this.l = l;
			this.r = r;
		}
		public int size() {
			return r - l;
		}
		public int compareTo(State s) {
			return s.size() - size();
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