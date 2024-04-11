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
		int[] a = new int[readInt()];
		for(int i = 0; i < a.length; i++)	{
			a[i] = readInt();
		}
		int[] b = new int[readInt()];
		for(int i = 0; i < b.length; i++)	{
			b[i] = readInt();
		}
		int max = 0;
		for(int x: a)	{
			for(int y: b)	{
				if(y%x==0)
					max = Math.max(max, y/x);
			}
		}
		int ret = 0;
		for(int x: a)	{
			for(int y: b)	{
				if(y%x==0 && y/x == max)
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