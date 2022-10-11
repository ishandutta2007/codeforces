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
		int n = readInt();
		int[][] grid = new int[n][];
		int[][] should = new int[n][];
		int c = 0;
		for(int i = 0; i < n; i++)	{
			grid[i] = new int[readInt()];
			should[i] = new int[grid[i].length];
			for(int a = 0; a < should[i].length; a++)	{
				should[i][a] = ++c;
			}
		}
		for(int i = 0; i < n; i++)	{
			for(int j = 0; j < grid[i].length; j++)	{
				grid[i][j] = readInt();
			}
		}
		ArrayList<int[]> ret = new ArrayList<int[]>();
		for(int i = 0; i < n; i++)	{
			for(int j = 0; j < grid[i].length; j++)	{
				if(grid[i][j] != should[i][j])	{
					int x = -1;
					int y = -1;
					for(int a = 0; a < n; a++)	{
						for(int b = 0; b < grid[a].length; b++)	{
							if(grid[a][b] == should[i][j])	{
								x=a;
								y=b;
							}
						}
					}
					grid[i][j] ^= grid[x][y];
					grid[x][y] ^= grid[i][j];
					grid[i][j] ^= grid[x][y];
					ret.add(new int[]{i+1,j+1,x+1,y+1});
				}
			}
		}
		pw.println(ret.size());
		for(int[] ans: ret)	{
			pw.println(ans[0] + " " + ans[1] + " " + ans[2] + " " + ans[3]);
		}
		pw.close();
	}

	/* NOTEBOOK CODE */

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