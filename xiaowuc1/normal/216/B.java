import java.awt.*;
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

	static boolean[][] grid;

	static boolean[] seen;
	static boolean[] processed;
	static int ret = 0;

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int n = readInt();
		int m = readInt();
		ret = 0;
		seen = new boolean[n];
		processed = new boolean[n];
		grid = new boolean[n][n];
		for(int i = 0; i < m; i++)	{
			int a = readInt();
			int b = readInt();
			a--;
			b--;
			grid[a][b] = grid[b][a] = true;
		}
		for(int i = 0; i < n; i++)	{
			dfs(-1, i, 0);
		}
		if(n%2 != ret%2)
			ret++;
		pw.println(ret);
		pw.close();
	}

	public static void dfs(int from, int curr, int depth)	{
		if(processed[curr])
			return;
		if(seen[curr])	{
			if(depth == 1)
				ret++;
		}
		else	{
			seen[curr] = true;
			for(int j = 0; j < grid[curr].length; j++)	{
				if(grid[curr][j] && j != from)	{
					dfs(curr, j, depth^1);
				}
			}
			processed[curr] = true;
		}
	}

	/* NOTEBOOK CODE */

	public static void loadArray(int[][] grid) throws IOException {
		for(int[] a: grid)
			loadArray(a);
	}

	public static void loadArray(int[] in) throws IOException {
		for(int i = 0; i < in.length; i++)
			in[i] = readInt();
	}

	public static void loadArray(long[] in) throws IOException {
		for(int i = 0; i < in.length; i++)
			in[i] = readLong();
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
				pw.close();
				System.exit(0);
			}
			st = new StringTokenizer(br.readLine().trim());
		}
		return st.nextToken();
	}
}