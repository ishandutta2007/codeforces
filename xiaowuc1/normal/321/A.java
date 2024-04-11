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
			long goalX = readInt();
			long goalY = readInt();
			String str = nextToken();
			Set<State> can = new HashSet<State>();
			can.add(new State(0, 0));
			long dx = 0;
			long dy = 0;
			for(int i = 0; i < str.length(); i++) {
				if(str.charAt(i) == 'U') {
					dy++;
				}
				if(str.charAt(i) == 'D') {
					dy--;
				}
				if(str.charAt(i) == 'R') {
					dx++;
				}
				if(str.charAt(i) == 'L') {
					dx--;
				}
				can.add(new State(dx, dy));
			}
			if(dx == 0 && dy == 0) {
				if(can.contains(new State(goalX, goalY))) {
					pw.println("Yes");
				}
				else {
					pw.println("No");
				}
				continue;
			}
			long min = 0;
			long max = 1100000000;
			while(max - min > 3) {
				long a = (2*min+max)/3;
				long b = (2*max+min)/3;
				long aDist = Math.abs(goalX - a * dx) + Math.abs(goalY - a * dy);
				long bDist = Math.abs(goalX - b * dx) + Math.abs(goalY - b * dy);
				if(aDist < bDist) {
					max = b;
				}
				else {
					min = a;
				}
			}
			boolean found = false;
			for(long change = -200; change <= 200 && !found; change++) {
				if(min + change < 0) continue;
				found = can.contains(new State(goalX - (min + change) * dx, goalY - (min+change) * dy));
			}
			if(found) {
				pw.println("Yes");
			}
			else {
				pw.println("No");
			}
		}
		exitImmediately();
	}

	static class State {
		public long x,y;

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + (int) (x ^ (x >>> 32));
			result = prime * result + (int) (y ^ (y >>> 32));
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

		public State(long x, long y) {
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