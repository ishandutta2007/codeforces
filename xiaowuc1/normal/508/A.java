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
			Set<State> set = new HashSet<State>();
			nextToken();
			nextToken();
			int n = readInt();
			int ret = Integer.MAX_VALUE;
			for(int i = 1; i <= n; i++) {
				int x = readInt();
				int y = readInt();
				set.add(new State(x, y));
				if(set.contains(new State(x,y)) && set.contains(new State(x-1,y)) && set.contains(new State(x,y-1)) && set.contains(new State(x-1,y-1))) {
					ret = Math.min(ret, i);
				}
				if(set.contains(new State(x,y)) && set.contains(new State(x+1,y)) && set.contains(new State(x,y-1)) && set.contains(new State(x+1,y-1))) {
					ret = Math.min(ret, i);
				}
				if(set.contains(new State(x,y)) && set.contains(new State(x-1,y)) && set.contains(new State(x,y+1)) && set.contains(new State(x-1,y+1))) {
					ret = Math.min(ret, i);
				}
				if(set.contains(new State(x,y)) && set.contains(new State(x+1,y)) && set.contains(new State(x,y+1)) && set.contains(new State(x+1,y+1))) {
					ret = Math.min(ret, i);
				}
			}
			if(ret == Integer.MAX_VALUE) ret = 0;
			pw.println(ret);
		}
		exitImmediately();
	}

	static class State {
		public int x,y;
		public State(int a, int b) {
			x=a;
			y=b;
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