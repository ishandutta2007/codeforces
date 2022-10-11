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
			int max = readInt();
			State[] list = new State[2];
			int v1 = readInt();
			int v2 = readInt();
			int w1 = readInt();
			int w2 = readInt();
			list[0] = new State(w1, v1);
			list[1] = new State(w2, v2);
			long ret = 0;
			for(int i = 0; i < 2; i++) {
				for(long j = 0; j <= 100000 && j * list[i].w <= max; j++) {
					long other = (max - j * list[i].w) / list[1-i].w;
					ret = Math.max(ret, j * list[i].v + other * list[1-i].v);
				}
			}
			pw.println(ret);
		}
		exitImmediately();
	}

	static class State implements Comparable<State> {
		public int w,v;
		public State(int a, int b){
			w=a;
			v=b;
		}
		public double ratio() {
			return 1.0 * v / w;
		}
		public int compareTo(State s) {
			return Double.compare(ratio(), s.ratio());
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