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

	static final long MAX = 1L << 50;

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			char[][] grid = new char[3][3];
			for (int i = 0; i < grid.length; i++) {
				grid[i] = nextToken().toCharArray();
			}
			int numX = 0;
			int numO = 0;
			for(char[] a: grid)	{
				for(char b: a)	{
					if(b == 'X')
						numX++;
					else if(b == '0')
						numO++;
				}
			}
			if(numX < numO || numX > numO+1)	{
				pw.println("illegal");
			}
			else if(numX == numO)	{
				if(hasThree(grid, 'X'))	{
					pw.println("illegal");
				}
				else if(hasThree(grid, '0'))	{
					pw.println("the second player won");
				}
				else	{
					pw.println("first");
				}
			}
			else	{
				if(hasThree(grid, '0'))	{
					pw.println("illegal");
				}
				else if(hasThree(grid, 'X'))	{
					pw.println("the first player won");
				}
				else if(numO < 4)	{
					pw.println("second");
				}
				else	{
					pw.println("draw");
				}
			}
		}
		pw.close();
	}

	public static boolean hasThree(char[][] grid, char ch)		{
		if(grid[0][0] == ch && grid[1][1] == ch && grid[2][2] == ch)
			return true;
		if(grid[0][2] == ch && grid[1][1] == ch && grid[2][0] == ch)
			return true;
		if(grid[0][0] == ch && grid[0][1] == ch && grid[0][2] == ch)
			return true;
		if(grid[1][0] == ch && grid[1][1] == ch && grid[1][2] == ch)
			return true;
		if(grid[2][0] == ch && grid[2][1] == ch && grid[2][2] == ch)
			return true;
		if(grid[0][0] == ch && grid[1][0] == ch && grid[2][0] == ch)
			return true;
		if(grid[0][1] == ch && grid[1][1] == ch && grid[2][1] == ch)
			return true;
		if(grid[0][2] == ch && grid[1][2] == ch && grid[2][2] == ch)
			return true;
		return false;
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