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

public class Main {
	private static BufferedReader br;
	private static StringTokenizer st;
	private static PrintWriter pw;

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int qq = 1;
		//int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			char[][] grid = new char[n][n];
			for(int i = 0; i < n; i++) {
				grid[i] = br.readLine().toCharArray();
			}
			boolean win = true;
			int[] dx = new int[]{1,-1,0,0};
			int[] dy = new int[]{0,0,-1,1};
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					int num = 0;
					for(int k = 0; k < dx.length; k++) {
						int nx = i + dx[k];
						int ny = j + dy[k];
						if(Math.min(nx,ny) < 0 || Math.max(nx,ny) >= n) continue;
						if(grid[nx][ny] == 'o') num++;
					}
					win &= num % 2 == 0;
				}
			}
			pw.println(win ? "YES" : "NO");
		}
		pw.close();
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