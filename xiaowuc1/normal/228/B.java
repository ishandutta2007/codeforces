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

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int r1 = readInt();
		int c1 = readInt();
		int[][] grid1 = new int[r1][c1];
		for(int i = 0; i < grid1.length; i++)	{
			String str = nextToken();
			for(int j = 0; j < grid1[i].length; j++)	{
				grid1[i][j] = str.charAt(j) - '0';
			}
		}
		int r2 = readInt();
		int c2 = readInt();
		int[][] grid2 = new int[r2][c2];
		for(int i = 0; i < grid2.length; i++)	{
			String str = nextToken();
			for(int j = 0; j < grid2[i].length; j++)	{
				grid2[i][j] = str.charAt(j) - '0';
			}
		}
		int know = 0;
		int retX = 0;
		int retY = 0;
		for(int shiftX = -50; shiftX <= 50; shiftX++)	{
			for(int shiftY = -50; shiftY <= 50; shiftY++)	{
				int curr = 0;
				for(int i = 0; i < r1; i++)	{
					for(int j = 0; j < c1; j++)	{
						curr += grid1[i][j] * get(grid2, i+shiftX, j+shiftY); 
					}
				}
				if(curr > know)	{
					know = curr;
					retX = shiftX;
					retY = shiftY;
				}
			}
		}
		pw.println(retX + " " + retY);
		pw.close();
	}

	public static int get(int[][] grid, int x, int y)	{
		if(x < 0)
			return 0;
		if(x >= grid.length)
			return 0;
		if(y < 0)
			return 0;
		if(y >= grid[x].length)
			return 0;
		return grid[x][y];
	}
	
	public static void loadArray(int[][] grid) throws IOException {
		for(int[] a: grid)
			loadArray(a);
	}
	
	public static void loadArray(int[] in) throws IOException {
		for(int i = 0; i < in.length; i++)
			in[i] = readInt();
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