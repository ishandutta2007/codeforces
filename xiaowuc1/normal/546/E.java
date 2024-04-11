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
		int qq = 1;
		//int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++) {
			int n = readInt();
			int m = readInt();
			int[][] grid = new int[2*n+2][2*n+2];
			for(int i = 1; i <= n; i++) {
				grid[i][i+n] = 1 << 30;
			}
			int total = 0;
			for(int i = 1; i <= n; i++) {
				grid[0][i] = readInt();
				total += grid[0][i];
			}
			int total2 = 0;
			for(int i = 1; i <= n; i++) {
				grid[i+n][2*n+1] = readInt();
				total2 += grid[i+n][2*n+1];
			}
			if(total != total2) {
				pw.println("NO");
				continue;
			}
			while(m-- > 0) {
				int a = readInt();
				int b = readInt();
				grid[a][n+b] = 1 << 30;
				grid[b][n+a] = 1 << 30;
			}
			int amt = 0;
			while(true) {
				int[] parent = new int[2*n+2];
				Arrays.fill(parent, -1);
				parent[0] = -2;
				int[] dp = new int[2*n+2];
				dp[0] = 1 << 30;
				LinkedList<Integer> q = new LinkedList<Integer>();
				q.add(0);
				while(!q.isEmpty()) {
					int curr = q.removeFirst();
					if(curr == 2*n+1) break;
					for(int i = 0; i < grid[curr].length; i++) {
						if(grid[curr][i] == 0 || parent[i] != -1) continue;
						dp[i] = Math.min(dp[curr], grid[curr][i]);
						parent[i] = curr;
						q.addFirst(i);
					}
				}
				if(parent[2*n+1] == -1) break;
				amt += dp[2*n+1];
				int curr = 2*n+1;
				while(curr != 0) {
					int p = parent[curr];
					grid[p][curr] -= dp[2*n+1];
					grid[curr][p] += dp[2*n+1];
					curr = p;
				}
			}
			if(amt != total) {
				pw.println("NO");
				continue;
			}
			pw.println("YES");
			for(int i = 1; i <= n; i++) {
				for(int j = 1; j <= n; j++) {
					if(grid[i][j+n] == 0) pw.print("0 ");
					else pw.print((1<<30) - grid[i][j+n] + " ");
				}
				pw.println();
			}
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