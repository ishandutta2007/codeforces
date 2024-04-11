import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

public class B {
	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter pw;

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++) {
			int n = readInt();
			LinkedList<State> zero = new LinkedList<State>();
			for(int i = 1; i <= n; i++) {
				zero.add(new State(i, readInt()));
			}
			Collections.sort(zero);
			LinkedList<State> one = new LinkedList<State>();
			String s = nextToken();
			for(int i = 0; i < s.length(); i++) {
				if(s.charAt(i) == '0') {
					pw.print(zero.peekFirst().index);
					one.addLast(zero.removeFirst());
				}
				else {
					pw.print(one.removeLast().index);
				}
				if(i == s.length()-1) pw.println();
				else pw.print(" ");
			}
		}
		pw.close();
	}

	static class State implements Comparable<State> {
		public int index;
		public int width;
		public State(int index, int width) {
			super();
			this.index = index;
			this.width = width;
		}
		public int compareTo(State s) {
			return width - s.width;
		}
	}
	
	public static void exitImmediately() {
		pw.close();
		System.exit(0);
	}

	public static int readInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	public static double readDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	public static long readLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	public static String nextLine() throws IOException {
		st = null;
		if(!br.ready()) {
			exitImmediately();
		}
		return br.readLine();
	}

	public static String nextToken() throws IOException {
		while(st == null || !st.hasMoreTokens()) {
			if(!br.ready()) {
				exitImmediately();
			}
			st = new StringTokenizer(br.readLine());
		}
		return st.nextToken();
	}
}