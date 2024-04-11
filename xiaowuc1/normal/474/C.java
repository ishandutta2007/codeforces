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
		int qq = 1;
		//int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++) {
			int n = readInt();
			while(n-- > 0) {
				solve();
			}
		}
		exitImmediately();
	}

	public static void solve() throws IOException {
		State[] pointToRotate = new State[4];
		State[] center = new State[4];
		for(int i = 0; i < pointToRotate.length; i++) {
			pointToRotate[i] = new State(readInt(), readInt());
			center[i] = new State(readInt(), readInt());
		}
		int ret = Integer.MAX_VALUE;
		for(int mask = 0; mask < 256; mask++) {
			State[] temp = new State[4];
			int curr = mask;
			int count = 0;
			for(int a = 0; a < 4; a++) {
				temp[a] = new State(pointToRotate[a]);
				int num = curr % 4;
				count += num;
				curr /= 4;
				while(num-- > 0) {
					temp[a] = rotate(center[a], temp[a]);
				}
			}
			if(count >= ret) continue;
			if(valid(temp)) {
				ret = count;
			}
		}
		if(ret == Integer.MAX_VALUE) {
			ret = -1;
		}
		pw.println(ret);
	}
	
	public static boolean valid(State[] list) {
		ArrayList<State> temp = new ArrayList<State>();
		for(State out: list) {
			temp.add(out);
		}
		for(int qq = 0; qq < 50; qq++) {
			Collections.shuffle(temp);
			Set<Integer> set = new HashSet<Integer>();
			for(int i = 0; i < temp.size(); i++) {
				int j = (i+1)%temp.size();
				set.add(temp.get(i).dist(temp.get(j)));
			}
			if(set.size() > 1 || set.contains(0)) continue;
			boolean good = true;
			for(int i = 0; i < temp.size(); i++) {
				int j = (i+1)%temp.size();
				int k = (i+2)%temp.size();
				if(temp.get(j).subtract(temp.get(i)).dot(temp.get(k).subtract(temp.get(j))) != 0) {
					good = false;
				}
			}
			if(good) {
				return true;
			}
		}
		return false;
	}
	
	public static State rotate(State stay, State rotate) {
		int x = rotate.x - stay.x;
		int y = rotate.y - stay.y;
		State ret = new State(stay.x - y, stay.y + x);
		return ret;
	}
	
	static class State {
		public int x,y;
		public State(int a, int b) {
			x = a;
			y = b;
		}
		public State(State s) {
			this(s.x, s.y);
		}
		public String toString() {
			return x + " " + y;
		}
		public State subtract(State s) {
			return new State(x - s.x, y - s.y);
		}
		public int dot(State s) {
			return x * s.x + y * s.y;
		}
		public int dist(State s) {
			int xx = x - s.x;
			int yy = y - s.y;
			return xx*xx+yy*yy;
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