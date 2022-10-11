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
			int[] dp = new int[n];
			PriorityQueue<Vertex> q = new PriorityQueue<Vertex>();
			for(int i = 0; i < n; i++) {
				int height = readInt();
				if(i == 0 || i == n-1) {
					height = 1;
				}
				dp[i] = height;
				q.add(new Vertex(i, dp[i]));
			}
			boolean[] seen = new boolean[n];
			int ret = 1;
			while(!q.isEmpty()) {
				Vertex curr = q.poll();
				if(seen[curr.v]) continue;
				seen[curr.v] = true;
				ret = curr.w;
				for(int dx = -1; dx <= 1; dx++) {
					int nextV = curr.v + dx;
					if(nextV >= 0 && nextV < n && dp[nextV] > curr.w + 1) {
						dp[nextV] = curr.w+1;
						q.add(new Vertex(nextV, dp[nextV]));
					}
				}
			}
			pw.println(ret);
		}
		exitImmediately();
	}

	static class Vertex implements Comparable<Vertex> {
		public int v,w;

		public Vertex(int v, int w) {
			super();
			this.v = v;
			this.w = w;
		}
		public int compareTo(Vertex curr) {
			return w - curr.w;
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