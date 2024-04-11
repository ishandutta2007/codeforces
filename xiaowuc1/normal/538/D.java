import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

/*
br = new BufferedReader(new FileReader("input.txt"));
pw = new PrintWriter(new BufferedWriter(new FileWriter("output.txt")));
br = new BufferedReader(new InputStreamReader(System.in));
pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
 */

public class D {
	private static BufferedReader br;
	private static StringTokenizer st;
	private static PrintWriter pw;
	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			char[][] grid = new char[n][n];
			for(int i = 0; i < n; i++) {
				String s = br.readLine();
				for(int j = 0; j < n; j++) {
					grid[i][j] = s.charAt(j);
				}
			}
			boolean[][] attacked = new boolean[n][n];
			boolean[][] ret = new boolean[2*n-1][2*n-1];
			for(int dx = -n+1; dx <= n-1; dx++) {
				for(int dy = -n+1; dy <= n-1; dy++) {
					boolean valid = true;
					for(int i = 0; i < n; i++) {
						for(int j = 0; j < n; j++) {
							if(grid[i][j] != 'o') continue;
							int nx = i + dx;
							int ny = j + dy;
							if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
							if(grid[nx][ny] == '.') {
								valid = false;
							}
						}
					}
					if(!valid) continue;
					ret[dx+n-1][dy+n-1] = true;
					for(int i = 0; i < n; i++) {
						for(int j = 0; j < n; j++) {
							if(grid[i][j] != 'o') continue;
							int nx = i + dx;
							int ny = j + dy;
							if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
							attacked[nx][ny] = true;
						}
					}
				}
			}
			boolean last = true;
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					if(grid[i][j] == 'x' && !attacked[i][j]) {
						last = false;
					}
				}
			}
			if(!last) {
				pw.println("NO");
				continue;
			}
			pw.println("YES");
			for(int i = 0; i < ret.length; i++) {
				for(int j = 0; j < ret[i].length; j++) {
					if(i == n-1 && j == n-1) {
						pw.print('o');
					}
					else if(ret[i][j]) {
						pw.print('x');
					}
					else {
						pw.print('.');
					}
				}
				pw.println();
			}
		}
		pw.close();
	}

	static class State {
		public int x,y;
		public State(int a, int b) {
			x=a;
			y=b;
		}
	}
	
	private static void exitImmediately()	{
		pw.close();
		System.exit(0);
	}

	private static long readLong() throws IOException	{
		return Long.parseLong(nextToken());
	}

	private static double readDouble() throws IOException	{
		return Double.parseDouble(nextToken());
	}

	private static int readInt() throws IOException	{
		return Integer.parseInt(nextToken());
	}

	private static String nextToken() throws IOException	{
		while(st == null || !st.hasMoreTokens())	{
			if(!br.ready())	{
				exitImmediately();
			}
			st = new StringTokenizer(br.readLine().trim());
		}
		return st.nextToken();
	}
}