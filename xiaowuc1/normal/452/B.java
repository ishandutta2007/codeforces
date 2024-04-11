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
			int r = readInt();
			int c = readInt();
			Set<State> set = new HashSet<State>();
			for(int i = 0; i <= 2 && i <= c; i++) {
				set.add(new State(0, i));
				set.add(new State(r, i));
			}
			for(int i = c; i >= 0 && i >= c-2; i--) {
				set.add(new State(0, i));
				set.add(new State(r, i));
			}
			for(int i = 0; i <= 2 && i <= r; i++) {
				set.add(new State(i, 0));
				set.add(new State(i, c));
			}
			for(int i = r; i >= r-2 && i >= 0; i--) {
				set.add(new State(i, 0));
				set.add(new State(i, c));
			}
			ArrayList<State> list = new ArrayList<State>();
			for(State out: set) {
				list.add(out);
			}
			double ret = 0;
			State aa = null;
			State bb = null;
			State cc = null;
			State dd = null;
			for(int qqq = 0; qqq < 100000; qqq++) {
				Collections.shuffle(list);
				double curr = list.get(0).dist(list.get(1));
				curr += list.get(1).dist(list.get(2));
				curr += list.get(2).dist(list.get(3));
				if(curr > ret){
					ret = curr;
					aa = new State(list.get(0));
					bb = new State(list.get(1));
					cc = new State(list.get(2));
					dd = new State(list.get(3));
				}
			}
			pw.println(aa);
			pw.println(bb);
			pw.println(cc);
			pw.println(dd);
		}
		exitImmediately();
	}

	static class State {
		public int x,y;

		public State(State s) {
			x = s.x;
			y = s.y;
		}
		
		public String toString() {
			return x + " " + y;
		}
		
		public double dist(State s) {
			int xx = x - s.x;
			int yy = y - s.y;
			return Math.sqrt(xx*xx+yy*yy);
		}
		
		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + x;
			result = prime * result + y;
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			State other = (State) obj;
			if (x != other.x)
				return false;
			if (y != other.y)
				return false;
			return true;
		}

		public State(int x, int y) {
			super();
			this.x = x;
			this.y = y;
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