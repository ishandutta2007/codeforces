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
		String[] list = new String[n];
		int[] score = new int[n];
		TreeSet<String> go = new TreeSet<String>();
		for(int i = 0; i < n; i++)	{
			list[i] = nextToken();
			score[i] = readInt();
			go.add(list[i]);
		}
		pw.println(go.size());
		String[] a = new String[go.size()];
		int[] b = new int[go.size()];
		int c = 0;
		for(String out: go)	{
			a[c] = out;
			for(int i = 0; i < n; i++)
				if(list[i].equals(out))
					b[c] = Math.max(b[c], score[i]);
			c++;
		}
		n = a.length;
		for(int j = 0; j < n; j++)	{
			String out = a[j];
			int max = b[j];
			int maxIsWorse = 0;
			int maxIsNotWorse = 0;
			for(int out2: b)
				if(out2 > max)
					maxIsWorse++;
				else
					maxIsNotWorse++;
			if(great(maxIsWorse, n, 50, 100))
				pw.println(out + " noob");
			else if(great(maxIsWorse, n, 20, 100))
				pw.println(out + " random");
			else if(great(maxIsWorse, n, 10, 100))
				pw.println(out + " average");
			else if(great(maxIsWorse, n, 1, 100))
				pw.println(out + " hardcore");
			else
				pw.println(out + " pro");
			
		}
		pw.close();
	}

	public static boolean great(int a, int b, int c, int d)	{
		return a*d > b * c;
	}
	
	public static boolean greatEq(int a, int b, int c, int d)	{
		return a*d >= b * c;
	}
	
	public static boolean less(int a, int b, int c, int d)	{
		return a*d < b * c;
	}
	
	public static boolean lessEq(int a, int b, int c, int d)	{
		return a*d <= b * c;
	}
	
	static class State implements Comparable<State> {
		public int cost;
		public boolean increase;
		public int index;
		public State(int a, boolean b, int c)	{
			cost = a;
			increase = b;
			index = c;
		}
		public int compareTo(State s)	{
			if(cost != s.cost)
				return cost - s.cost;
			if(increase != s.increase)	{
				if(increase)
					return 1;
				return -1;
			}
			if(!increase)
				return index - s.index;
			return s.index - index;
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