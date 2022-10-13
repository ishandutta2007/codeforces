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
			long n = readLong();
			int k = readInt();
			if(ans(2,k) < n)	{
				pw.println(-1);
			}
			else if(n == 1) {
				pw.println(0);
			}
			else	{
				int min = 1;
				int max = k-1;
				while(min != max)	{
					int mid = (min+max)/2;
					if(ans(k-mid+1,k) >= n)	{
						max = mid;
					}
					else	{
						min = mid+1;
					}
				}
				pw.println(min);
			}
		}
		pw.close();
	}

	public static long ans(int min, int max)	{
		int num = max-min+1;
		long ret = tri(max) - tri(min-1);
		return ret - (num - 1);
	}
	
	public static long tri(long n)	{
		return (n*n+n)/2;
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