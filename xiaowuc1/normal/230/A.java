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
		int start = readInt();
		int n = readInt();
		int[] str = new int[n];
		int[] gain = new int[n];
		for(int i = 0; i < n; i++)	{
			str[i] = readInt();
			gain[i] = readInt();
		}
		boolean[] win = new boolean[n];
		while(true)	{
			boolean add = false;
			for(int i = 0; i < n; i++)	{
				if(start > str[i] && !win[i])	{
					add = true;
					start += gain[i];
					win[i] = true;
				}
			}
			if(!add)
				break;
		}
		int numBad = 0;
		for(boolean b: win)
			if(!b)
				numBad++;
		pw.println(numBad == 0 ? "YES" : "NO");
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