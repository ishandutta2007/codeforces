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
			int k = readInt();
			boolean[] is = new boolean[n];
			for(int i = 0; i < n; i++) {
				is[i] = readInt() == 1;
			}
			LinkedList<Integer>[] edges = new LinkedList[n];
			for(int i = 0; i < n; i++) {
				edges[i] = new LinkedList<Integer>();
			}
			for(int a = 1; a < n; a++) {
				int x = readInt()-1;
				int y = readInt()-1;
				edges[x].add(y);
				edges[y].add(x);
			}
			int[] p = new int[n];
			Arrays.fill(p, -1);
			p[0] = -2;
			LinkedList<Integer> q = new LinkedList<Integer>();
			int[] dp = new int[n];
			boolean[] seen = new boolean[n];
			dp[0] = is[0] ? 1 : 0;
			q.add(0);
			seen[0] = true;
			while(!q.isEmpty()) {
				int curr = q.removeFirst();
				for(int out: edges[curr]) {
					if(p[out] == -1) {
						if(dp[curr] == k && is[out]) continue;
						if(is[out]) {
							dp[out] = dp[curr]+1;
						}
						else {
							dp[out] = 0;
						}
						q.add(out);
						seen[out] = true;
						p[out] = curr;
					}
				}
			}
			int ret = 0;
			for(int i = 0; i < n; i++) {
				if(seen[i] && edges[i].size() == 1 && p[i] >= 0) {
					ret++;
				}
			}
			pw.println(ret);
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