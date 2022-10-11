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
		int x = readInt();
		int t = readInt();
		int a = readInt();
		int b = readInt();
		int da = readInt();
		int db = readInt();
		boolean win = false;
		for(int i = 0; i < t; i++)	{
			for(int j = 0; j < t; j++)	{
				if(a-da*i+b-db*j==x)
					win = true;
				if(b-db*j==x)
					win = true;
				if(a-da*i==x)
					win = true;
				if(0==x)
					win = true;
			}
		}
		pw.println(win ? "YES" : "NO");
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