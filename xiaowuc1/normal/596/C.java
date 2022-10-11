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

	static Set<State> used;
	
	public static void main(String[] args) throws Exception {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			Set<State> set = new HashSet<State>();
			for(int i = 0; i < n; i++) {
				set.add(new State(readInt(), readInt()));
			}
			int[] w = new int[n];
			for(int i = 0; i < n; i++) {
				w[i] = readInt();
			}
			LinkedList<State> q = new LinkedList<State>();
			Map<Integer, ArrayList<State>> map = new HashMap<Integer, ArrayList<State>>();
			map.put(0, new ArrayList<State>());
			map.get(0).add(new State(0, 0));
			State[] ret = new State[n];
			boolean bad = false;
			used = new HashSet<State>();
			for(int i = 0; !bad && i < n; i++) {
				if(!map.containsKey(w[i])) {
					bad = true;
					break;
				}
				ArrayList<State> list = map.get(w[i]);
				ret[i] = list.remove(list.size()-1);
				used.add(ret[i]);
				if(list.isEmpty()) {
					map.remove(w[i]);
				}
				if(set.contains(new State(ret[i].x, ret[i].y+1)) && can(ret[i].x, ret[i].y + 1)) {
					add(map, ret[i].x, ret[i].y+1);
				}
				if(set.contains(new State(ret[i].x+1, ret[i].y)) && can(ret[i].x+1, ret[i].y)) {
					add(map, ret[i].x+1, ret[i].y);
				}
			}
			if(bad) {
				pw.println("NO");
			}
			else {
				pw.println("YES");
				for(State out: ret) {
					pw.println(out);
				}
			}
		}
		exitImmediately();
	}

	public static void add(Map<Integer, ArrayList<State>> map, int x, int y) {
		int key = y-x;
		if(!map.containsKey(key)) {
			map.put(key, new ArrayList<State>());
		}
		map.get(key).add(new State(x, y));
	}
	
	public static boolean can(int x, int y) {
		if(x > 0 && !used.contains(new State(x-1, y))) return false;
		if(y > 0 && !used.contains(new State(x, y-1))) return false;
		return true;
	}
	
	static class State {
		public int x,y;

		public String toString() {
			return x + " " + y;
		}
		
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