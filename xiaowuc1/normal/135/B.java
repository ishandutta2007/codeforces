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
			ArrayList<State> list = new ArrayList<State>();
			for(int i = 1; i <= 8; i++) {
				list.add(new State(readInt(), readInt(), i));
			}
			boolean win = false;
			for(int qqq = 0; !win && qqq < 10000; qqq++) {
				Collections.shuffle(list);
				State[] first = new State[4];
				State[] last = new State[4];
				for(int i = 0; i < 4; i++) {
					first[i] = list.get(i);
					last[i] = list.get(i+4);
				}
				if(isSquare(first) && isRectangle(last)) {
					win = true;
					pw.println("YES");
					for(State out: first) {
						pw.print(out.index + " ");
					}
					pw.println();
					for(State out: last) {
						pw.print(out.index + " ");
					}
					pw.println();
				}
			}
			if(!win) {
				pw.println("NO");
			}
		}
		exitImmediately();
	}

	public static boolean isSquare(State[] list) {
		Set<Integer> set = new HashSet<Integer>();
		for(int i = 0; i < list.length; i++) {
			int j = (i+1)%list.length;
			set.add(list[i].distSq(list[j]));
		}
		if(set.size() > 1) {
			return false;
		}
		for(int i = 0; i < list.length; i++) {
			int j = (i+3)%list.length;
			int k = (i+1)%list.length;
			State a = list[j].subtract(list[i]);
			State b = list[k].subtract(list[i]);
			if(a.dot(b) != 0) return false;
		}
		return true;
	}

	public static boolean isRectangle(State[] list) {
		for(int a = 0; a < 2; a++) {
			Set<Integer> set = new HashSet<Integer>();
			for(int i = a; i < list.length; i+=2) {
				int j = (i+1)%list.length;
				set.add(list[i].distSq(list[j]));
			}
			if(set.size() > 1) {
				return false;
			}
		}
		for(int i = 0; i < list.length; i++) {
			int j = (i+3)%list.length;
			int k = (i+1)%list.length;
			State a = list[j].subtract(list[i]);
			State b = list[k].subtract(list[i]);
			if(a.dot(b) != 0) return false;
		}
		return true;
	}

	static class State {
		public int x,y;
		public int index;
		public State(int a, int b, int c) {
			x=a;
			y=b;
			index=c;
		}
		public int distSq(State s) {
			int xx = x - s.x;
			int yy = y - s.y;
			return xx*xx+yy*yy;
		}
		public int dot(State s) {
			return x * s.x + y * s.y;
		}
		public State subtract(State s) {
			return new State(x - s.x, y - s.y, -1);
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