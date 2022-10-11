import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

public class Main {
	private static BufferedReader br;
	private static StringTokenizer st;
	private static PrintWriter pw;

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int n = readInt();
		int[][] grid = new int[2][2];
		for(int i = 0; i < n; i++)	{
			int k = readInt()-1;
			grid[k][0] += readInt();
			grid[k][1] += readInt();
		}
		for(int i = 0; i < 2; i++)	{
			pw.println(grid[i][0] >= grid[i][1] ? "LIVE" : "DEAD");
		}
		pw.close();
	}

	public static boolean isPrime(long k)	{
		if(k == 1)
			return false;
		int ret = 2;
		for(int i = 2; ret == 2 && i * i <= k; i++)	{
			if(k%i==0)
				ret++;
		}
		return ret == 2;
	}

	static class State	{
		public int x,y;
		public State(int a, int b)	{
			x=a;
			y=b;
		}
		public int hashCode()		{
			return 3137*x+y;
		}
		public boolean equals(Object o)	{
			State s = (State)o;
			return x == s.x && y == s.y;
		}
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
			st = new StringTokenizer(br.readLine().trim());
		}
		return st.nextToken();
	}
}