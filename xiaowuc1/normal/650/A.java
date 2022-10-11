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
			Map<Integer, Integer> xs = new HashMap<Integer, Integer>();
			Map<Integer, Integer> ys = new HashMap<Integer, Integer>();
			Map<State, Integer> zs = new HashMap<State, Integer>();
			for(int i = 0; i < n; i++) {
				int x = readInt();
				int y = readInt();
				inc(xs,x);
				inc(ys,y);
				State key = new State(x, y);
				if(!zs.containsKey(key)) {
					zs.put(key, 1);
				}
				else {
					zs.put(key, zs.get(key) + 1);
				}
			}
			long ret = 0;
			for(int out: xs.keySet()) {
				long now = xs.get(out);
				ret += now * (now-1)/2;
			}
			for(int out: ys.keySet()) {
				long now = ys.get(out);
				ret += now * (now-1)/2;
			}
			for(State out: zs.keySet()) {
				long now = zs.get(out);
				ret -= now * (now-1)/2;
			}
			pw.println(ret);
		}
		exitImmediately();
	}

	static class State {
		public int x,y;

		public State(int x, int y) {
			super();
			this.x = x;
			this.y = y;
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
	
	public static void inc(Map<Integer, Integer> m, int k) {
		if(!m.containsKey(k)) {
			m.put(k, 0);
		}
		m.put(k, m.get(k) + 1);
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