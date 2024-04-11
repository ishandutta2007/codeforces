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
		int k = readInt();
		int[] count = new int[26];
		char[] go = nextToken().toCharArray();
		for(char out: go)
			count[out-'a']++;
		boolean win = true;
		for(int out: count)	{
			if(out%k != 0)
				win = false;
		}
		if(!win)
			pw.println(-1);
		else	{
			StringBuilder sb = new StringBuilder();
			for(int i = 0; i < 26; i++)	{
				for(int j = 0; j < count[i]/k; j++)	{
					sb.append((char)('a'+i));
				}
			}
			for(int i = 0; i < k; i++)
				pw.print(sb.toString());
			pw.println();
		}
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