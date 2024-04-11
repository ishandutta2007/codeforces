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
			int n = readInt();
			LinkedList<State> q = new LinkedList<>();
			int[] ret = new int[n];
			for(int i = 0; i < n; i++) {
				int lhs = readInt();
				int rhs = readInt();
				q.add(new State(lhs, rhs, i));
			}
			int nextS = 1;
			while(!q.isEmpty()) {
				State curr = q.removeFirst();
				if(nextS > curr.r) continue;
				nextS = 1 + (ret[curr.i] = Math.max(nextS, curr.l));
			}
			StringBuilder sb = new StringBuilder();
			for(int out: ret) {
				sb.append(out);
				sb.append(" ");
			}
			pw.println(sb.toString().trim());
		}
		exitImmediately();
	}

	static class State {
		public int l,r,i;

		public State(int l, int r, int i) {
			super();
			this.l = l;
			this.r = r;
			this.i = i;
		}
		
	}
	
	private static void exitImmediately() {
		pw.close();
		System.exit(0);
	}

	private static long readLong() throws IOException {
		return Long.parseLong(readToken());
	}

	private static double readDouble() throws IOException {
		return Double.parseDouble(readToken());
	}

	private static int readInt() throws IOException {
		return Integer.parseInt(readToken());
	}

	private static String readLine() throws IOException  {
		String s = br.readLine();
		if(s == null) {
			exitImmediately();
		}
		st = null;
		return s;
	}

	private static String readToken() throws IOException  {
		while(st == null || !st.hasMoreTokens())  {
			st = new StringTokenizer(readLine().trim());
		}
		return st.nextToken();
	}
}