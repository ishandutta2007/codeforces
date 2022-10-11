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
			State[] list = new State[n];
			for(int i = 0; i < n; i++) {
				list[i] = new State(readInt(), readInt(), i+1);
			}
			TreeSet<Integer> ret = new TreeSet<Integer>();
			Arrays.sort(list);
			for(int i = 0; i < n; i++) {
				int last = -1;
				boolean good = true;
				for(int j = 0; j < n; j++) {
					if(j == i) continue;
					if(list[j].l < last) {
						good = false;
						break;
					}
					last = list[j].r;
				}
				if(good) {
					ret.add(list[i].index);
				}
			}
			pw.println(ret.size());
			StringBuilder sb = new StringBuilder();
			for(int out: ret) {
				sb.append(out);
				sb.append(' ');
			}
			pw.println(sb.toString().trim());
		}
		exitImmediately();
	}

	static class State implements Comparable<State> {
		public int l, r, index;
		public State(int a, int b, int c) {
			l=a;
			r=b;
			index=c;
		}
		public int compareTo(State s) {
			return l - s.l;
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