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
		int a = readInt();
		int b = readInt();
		int c = readInt();
		int[] min = new int[b+c-1];
		int[] max = new int[b+c-1];
		max[0] = a-1;
		for(int i = 1; i < b; i++)	{
			max[i] = max[i-1] + 1;
		}
		for(int i = b; i < max.length; i++)	{
			max[i] = max[i-1];
		}
		for(int i = 1; i < c; i++)	{
			min[i] = min[i-1];
		}
		for(int i = c; i < min.length; i++)	{
			min[i] = min[i-1] + 1;
		}
		int count = 0;
		for(int i = 0; i < min.length; i++)	{
			count += max[i] - min[i] + 1;
		}
		pw.println(count);
		pw.close();
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