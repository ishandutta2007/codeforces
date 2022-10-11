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
		HashMap<State, Integer> map = new HashMap<State, Integer>();
		int ret = 0;
		while(n-- > 0)	{
			State curr = new State(readInt(), readInt());
			Integer ans = map.get(curr);
			if(ans == null)
				ans = 0;
			map.put(curr, ++ans);
			ret = Math.max(ret, ans);
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