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
		String token = nextToken();
		token = token.replaceAll("WUB", " ");
		token = token.trim();
		for(int i = 0; i < token.length()-1; i++)	{
			if(token.charAt(i) == ' ' && token.charAt(i+1) == ' ')	{
				token = token.substring(0,i) + token.substring(i+1);
				i--;
			}
		}
		pw.println(token);
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