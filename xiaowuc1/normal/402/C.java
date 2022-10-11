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
		//int qq = Integer.MAX_VALUE;
		int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++) {
			ArrayList<State> list = new ArrayList<State>();
			int n = readInt();
			int p = readInt();
			for(int i = 1; i <= n; i++) {
				for(int j = i+1; j <= n; j++) {
					list.add(new State(i, j));
				}
			}
			Collections.sort(list);
			for(int i = 0; i < 2*n+p; i++) {
				pw.println(list.get(i));
			}
		}
		exitImmediately();
	}

	static class State implements Comparable<State> {
		public int x,y;
		public String toString() {
			return x + " " + y;
		}
		public State(int a, int b) {
			x=a;
			y=b;
		}
		public int compareTo(State s) {
			if(x != s.x) return x - s.x;
			return y - s.y;
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