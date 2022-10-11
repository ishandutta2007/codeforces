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
			TreeMap<Long, TreeSet<Integer>> dp = new TreeMap<>();
			for(int i = 0; i < n; i++) {
				long x = readLong();
				if(!dp.containsKey(x)) {
					dp.put(x, new TreeSet<>());
				}
				dp.get(x).add(i);
			}
			ArrayList<State> ret = new ArrayList<>();
			while(!dp.isEmpty()) {
				long now = dp.firstKey();
				TreeSet<Integer> set = dp.remove(now);
				while(set.size() >= 2) {
					set.remove(set.first());
					int idx = set.first();
					set.remove(idx);
					if(!dp.containsKey(2*now)) {
						dp.put(2*now, new TreeSet<>());
					}
					dp.get(2*now).add(idx);
				}
				if(!set.isEmpty()) {
					ret.add(new State(set.first(), now));
				}
			}
			Collections.sort(ret);
			pw.println(ret.size());
			for(int i = 0; i < ret.size(); i++) {
				pw.print(ret.get(i).v);
				if(i == ret.size()-1) pw.println();
				else pw.print(" ");
			}
		}
		exitImmediately();
	}

	static class State implements Comparable<State> {
		public int i;
		public long v;
		public State(int i, long v) {
			super();
			this.i = i;
			this.v = v;
		}
		public int compareTo(State s) {
			return i - s.i;
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