import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

public class Main {
	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter pw;

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int n = readInt();
		int ret = 0;
		int[][] grid = new int[n][n];
		for (int i = 0; i < n; i++)	{
			for (int j = 0; j < n; j++)	{
				grid[i][j] = readInt();
			}
		}
		for (int i = 0; i < n; i++)	{
			for (int j = 0; j < n; j++)	{
				int colSum = 0;
				int rowSum = 0;
				for (int k = 0; k < n; k++)	{
					rowSum += grid[i][k];
					colSum += grid[k][j];
				}
				if (colSum > rowSum)
					ret++;
			}
		}
		pw.println(ret);
		pw.close();
	}

	static class State	{
		public int x,y;
		public State(int a, int b)	{
			x=a;
			y=b;
		}
	}

	public static long readLong() throws IOException	{
		return Long.parseLong(nextToken());
	}
	public static double readDouble() throws IOException	{
		return Double.parseDouble(nextToken());
	}
	public static int readInt() throws IOException	{
		return Integer.parseInt(nextToken());
	}
	public static short readShort() throws IOException	{
		return Short.parseShort(nextToken());
	}
	public static String nextToken() throws IOException	{
		while(st == null || !st.hasMoreTokens())	{
			if(!br.ready())	{
				pw.close();
				System.exit(0);
			}
			st = new StringTokenizer(br.readLine());
		}
		return st.nextToken();
	}
}