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
			int l = readInt();
			int[] list = new int[n];
			for(int i = 0; i < n; i++) {
				list[i] = readInt();
			}
			int k = Math.min(l, readInt());
			DS ds = new DS(k);
			long ret = 0;
			long currSum = 0;
			for(int i = 0; i < n; i++) {
				currSum += list[i];
				ds.insert(new State(i, list[i]));
				if(i >= l) {
					currSum -= list[i-l];
					ds.delete(new State(i-l, list[i-l]));
				}
				if(i >= l-1) {
					ret = Math.max(ret, Math.abs(currSum - 2 * ds.lowSum));
					ret = Math.max(ret, Math.abs(currSum - 2 * ds.highSum));
				}
			}
			pw.println(ret);
		}
		exitImmediately();
	}

	static class State implements Comparable<State> {
		public int index, val;

		public State(int index, int val) {
			super();
			this.index = index;
			this.val = val;
		}
		public int compareTo(State s) {
			if(val == s.val) {
				return index - s.index;
			}
			return val - s.val;
		}
	}
	
	static class DS {
		TreeSet<State> lowest, highest, all;
		long lowSum, highSum;
		int k;
		public DS(int k) {
			lowSum = 0;
			highSum = 0;
			this.k = k;
			lowest = new TreeSet<State>();
			highest = new TreeSet<State>();
			all = new TreeSet<State>();
		}
		public void insert(State s) {
			all.add(s);
			lowest.add(s);
			lowSum += s.val;
			highest.add(s);
			highSum += s.val;
			clean();
		}
		private void clean() {
			while(lowest.size() > k || (!lowest.isEmpty() && lowest.last().val >= 0)) {
				lowSum -= lowest.last().val;
				lowest.remove(lowest.last());
			}
			while(highest.size() > k || (!highest.isEmpty() && highest.first().val <= 0)) {
				highSum -= highest.first().val;
				highest.remove(highest.first());
			}
		}
		public void delete(State s) {
			all.remove(s);
			if(lowest.remove(s)) {
				lowSum -= s.val;
			}
			if(highest.remove(s)) {
				highSum -= s.val;
			}
			if(lowest.isEmpty() && k > 0) {
				lowest.add(all.first());
				lowSum += all.first().val;
			}
			while(lowest.size() < k && all.last().compareTo(lowest.last()) > 0 && all.higher(lowest.last()).val < 0) {
				lowest.add(all.higher(lowest.last()));
				lowSum += lowest.last().val;
			}
			if(highest.isEmpty() && k > 0) {
				highest.add(all.last());
				highSum += highest.last().val;
			}
			while(highest.size() < k && all.first().compareTo(highest.first()) < 0 && all.lower(highest.first()).val > 0) {
				highest.add(all.lower(highest.first()));
				highSum += highest.first().val;
			}
			clean();
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