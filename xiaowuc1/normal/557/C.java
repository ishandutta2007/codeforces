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
			State[] list = new State[n];
			for(int i = 0; i < n; i++) {
				list[i] = new State(0, 0);
			}
			for(int i = 0; i < n; i++) {
				list[i].size = readInt();
			}
			for(int i = 0; i < n; i++) {
				list[i].energy = readInt();
			}
			Arrays.sort(list);
			int totalSum = 0;
			for(State out: list) {
				totalSum += out.energy;
			}
			int ret = Integer.MAX_VALUE;
			int[] own = new int[201];
			for(int i = 0; i < n; ) {
				int j = i;
				int numCan = -1;
				int energy = 0;
				while(j < n && list[i].size == list[j].size) {
					energy += list[j].energy;
					numCan++;
					j++;
				}
				for(int a = 200; a >= 0; a--) {
					int could = Math.min(own[a], numCan);
					energy += could * a;
					numCan -= could;
				}
				ret = Math.min(ret, totalSum - energy);
				for(int a = i; a < j; a++) {
					own[list[a].energy]++;
				}
				i = j;
			}
			pw.println(ret);
		}
		exitImmediately();
	}

	static class State implements Comparable<State> {
		public int size, energy;
		public State(int a, int b) {
			size = a;
			energy = b;
		}
		public int compareTo(State s) {
			return size - s.size;
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