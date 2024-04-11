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
	
	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int n = readInt();
		int m = readInt();
		grid = new boolean[n][n];
		boolean win = false;
		for(int qq = 1; !win && qq <= m; qq++)	{
			int a = readInt();
			int b = readInt();
			grid[--a][--b] = true;
			for(int k = 0; k < 3; k++)	{
				for(int l = 0; l < 3; l++)	{
					win |= three(a-k,b-l);
				}
			}
			if(win)	{
				pw.println(qq);
			}
		}
		if(!win)	{
			pw.println(-1);
		}
		pw.close();
	}
	
	public static boolean three(int x, int y)	{
		for(int k = 0; k < 3; k++)	{
			for(int l = 0; l < 3; l++)	{
				if(!is(x+k,y+l))	{
					return false;
				}
			}
		}
		return true;
	}
	
	public static boolean is(int x, int y)	{
		return x >= 0 && x < grid.length && y >= 0 && y < grid[x].length && grid[x][y];
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