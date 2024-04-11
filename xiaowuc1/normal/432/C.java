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
		boolean[] comp = new boolean[100005];
		comp[0] = true;
		comp[1] = true;
		for(int i = 2; i * i < comp.length; i++) {
			if(!comp[i]) {
				for(int j = i*i; j < comp.length; j += i) {
					comp[j] = true;
				}
			}
		}
		for(int casenum = 1; casenum <= qq; casenum++) {
			ArrayList<State> ret = new ArrayList<State>();
			int n = readInt();
			int[] location = new int[n];
			int[] list = new int[n];
			for(int i = 0; i < n; i++) {
				list[i] = readInt()-1;
				location[list[i]] = i;
			}
			for(int i = 0; i < n; i++) {
				int numToSort = i;
				while(location[numToSort] != i) {
					int currLoc = location[numToSort];
					for(int a = i; a < currLoc; a++) {
						int num = currLoc - a + 1;
						if(!comp[num]) {
							ret.add(new State(a+1, currLoc+1));
							swap(location, list, a, currLoc);
							break;
						}
					}
				}
			}
			pw.println(ret.size());
			for(State out: ret) {
				pw.println(out);
			}
		}
		exitImmediately();
	}

	public static void swap(int[] loc, int[] list, int x, int y) {
		int t = list[x];
		list[x] = list[y];
		list[y] = t;
		t = loc[x];
		loc[list[x]] = x;
		loc[list[y]] = y;
	}
	
	static class State {
		public int x,y;
		public String toString() {
			return x + " " + y;
		}
		public State(int a, int b) {
			x=a;
			y=b;
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