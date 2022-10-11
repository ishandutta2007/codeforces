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
			int n = readInt();
			int total = readInt();
			ArrayList<State> list = new ArrayList<State>();
			for(int i = 1; i <= total; i++) {
				list.add(new State(i, readInt()));
			}
			Collections.sort(list);
			int[] ret = new int[n];
			for(State out: list) {
				outer: while(out.val-- > 0) {
					for(int i = 0; i < n; i++) {
						if(ret[i] > 0) continue;
						if(ret[(i+1)%n] == 0 && ret[(i+n-1)%n] == 0) {
							ret[i] = out.index;
							continue outer;
						}
					}
					for(int i = 0; i < n; i++) {
						if(ret[i] > 0) continue;
						if(ret[(i+1)%n] == out.index || ret[(i+n-1)%n] == out.index) {
							continue;
						}
						if(ret[(i+1)%n] == 0 || ret[(i+n-1)%n] == 0) {
							ret[i] = out.index;
							continue outer;
						}
					}
					for(int i = 0; i < n; i++) {
						if(ret[i] > 0) continue;
						if(ret[(i+1)%n] == out.index || ret[(i+n-1)%n] == out.index) {
							continue;
						}
						ret[i] = out.index;
						continue outer;
					}

				}
			}
			int count = 0;
			for(int out: ret) {
				if(out == 0) {
					count++;
				}
			}
			if(count > 0) {
				pw.println(-1);
			}
			else {
				for(int out: ret) {
					pw.print(out + " ");
				}
				pw.println();
			}
		}
		exitImmediately();
	}

	static class State implements Comparable<State> {
		public int index, val;
		public State(int a, int b) {
			index = a;
			val = b;
		}
		public int compareTo(State s) {
			return val - s.val;
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