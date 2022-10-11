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
		int p = readInt()-1;
		State[] list = new State[n];
		for(int i = 0; i < n; i++)	{
			list[i] = new State(readInt(), readInt());
		}
		Arrays.sort(list);
		State want = list[p];
		int ret = 0;
		for(State out: list)
			if(out.equals(want))
				ret++;
		pw.println(ret);
		pw.close();
	}

	static class State implements Comparable<State>	{
		public int a,b;
		public State(int x, int y)	{
			a=x;
			b=y;
		}
		public int compareTo(State s)	{
			if(a == s.a)
				return b - s.b;
			return s.a - a;
		}
		public boolean equals(Object o)	{
			State s = (State)o;
			return a == s.a && b == s.b;
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