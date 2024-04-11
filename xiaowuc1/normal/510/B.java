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

	static char[][] grid;
	static boolean[][] seen;
	static boolean[][] processed;
	
	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++) {
			int r = readInt();
			int c = readInt();
			grid = new char[r][c];
			seen = new boolean[r][c];
			processed = new boolean[r][c];
			for(int i = 0; i < r; i++) {
				String s = nextToken();
				for(int j = 0; j < c; j++) {
					grid[i][j] = s.charAt(j);
				}
			}
			boolean ret = false;
			for(int i = 0; i < r; i++) {
				for(int j = 0; j < c; j++) {
					ret |= dfs(i, j, -1, -1);
				}
			}
			pw.println(ret ? "Yes" : "No");
		}
		exitImmediately();
	}

	static int[] dx = new int[]{-1,1,0,0};
	static int[] dy = new int[]{0,0,-1,1};
	
	public static boolean dfs(int x, int y, int px, int py) {
		if(processed[x][y]) return false;
		if(seen[x][y]) return true;
		seen[x][y] = true;
		for(int k = 0; k < dx.length; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if(nx >= 0 && nx < grid.length && ny >= 0 && ny < grid[x].length && grid[x][y] == grid[nx][ny] && (px != nx || py != ny)) {
				if(dfs(nx, ny, x, y)) {
					processed[x][y] = true;
					return true;
				}
			}
		}
		processed[x][y] = true;
		return false;
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