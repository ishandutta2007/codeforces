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
			int k = readInt();
			boolean[][] bad = new boolean[n][n];
			while(k-- > 0) {
				int[] list = new int[n];
				for(int i = 0; i < n; i++) {
					list[i] = readInt()-1;
					for(int j = 0; j <= i; j++) {
						bad[list[i]][list[j]] = true;
					}
				}
			}
			LinkedList<Integer>[] edges = new LinkedList[n];
			for(int i = 0; i < n; i++) {
				edges[i] = new LinkedList<Integer>();
			}
			int[] parent = new int[n];
			int[] dp = new int[n];
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					if(!bad[i][j]) {
						parent[j]++;
						edges[i].add(j);
					}
				}
			}
			LinkedList<Integer> q = new LinkedList<Integer>();
			for(int i = 0; i < n; i++) {
				if(parent[i] == 0) {
					q.add(i);
					dp[i] = 1;
				}
			}
			while(!q.isEmpty()) {
				int curr = q.removeFirst();
				for(int out: edges[curr]) {
					if(--parent[out] == 0) {
						q.add(out);
					}
					dp[out] = Math.max(dp[out], 1 + dp[curr]);
				}
			}
			Arrays.sort(dp);
			pw.println(dp[n-1]);
		}
		exitImmediately();
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