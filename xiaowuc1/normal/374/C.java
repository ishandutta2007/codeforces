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

	static int[][] grid;
	
	static boolean[][] seen;
	static boolean[][] processed;
	static int[][] dp;
	
	static boolean forceReturn;
	
	public static void main(String[] args) throws Exception {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			int m = readInt();
			grid = new int[n][m];
			seen = new boolean[n][m];
			processed = new boolean[n][m];
			dp = new int[n][m];
			forceReturn = false;
			for(int i = 0; i < n; i++) {
				String s = nextToken();
				for(int j = 0; j < m; j++) {
					if(s.charAt(j) == 'I') grid[i][j] = 1;
					if(s.charAt(j) == 'M') grid[i][j] = 2;
					if(s.charAt(j) == 'A') grid[i][j] = 3;
				}
			}
			int ret = 0;
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < m && !forceReturn; j++) {
					if(grid[i][j] != 0) continue;
					ret = Math.max(ret, solve(i, j));
				}
			}
			if(forceReturn) {
				pw.println("Poor Inna!");
			}
			else if(ret == 0) {
				pw.println("Poor Dima!");
			}
			else {
				pw.println(ret);
			}
		}
		exitImmediately();
	}

	public static int solve(int x, int y) {
		if(forceReturn) return -1;
		if(processed[x][y]) return dp[x][y];
		if(seen[x][y]) {
			forceReturn = true;
			return -1;
		}
		seen[x][y] = true;
		int inc = 0;
		if(grid[x][y] == 3) {
			dp[x][y] = 1;
			inc = 1;
		}
		for(int k = 0; k < dx.length; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if(nx < 0 || nx >= grid.length || ny < 0 || ny >= grid[nx].length) continue;
			if((grid[nx][ny] + 3)%4 != grid[x][y]) continue;
			dp[x][y] = Math.max(dp[x][y], inc + solve(nx, ny));
		}
		processed[x][y] = true;
		return dp[x][y];
	}
	
	static int[] dx = new int[]{-1,1,0,0};
	static int[] dy = new int[]{0,0,-1,1};
	
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