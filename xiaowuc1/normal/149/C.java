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
		State[] list = new State[n];
		for(int i = 0; i < n; i++)
			list[i] = new State(i+1, readInt());
		Arrays.sort(list);
		ArrayList<Integer> a = new ArrayList<Integer>();
		ArrayList<Integer> b = new ArrayList<Integer>();
		a.add(list[0].x);
		b.add(list[1].x);
		for(int i = 2; i < n; i++)	{
			if(i%2==0)
				b.add(list[i].x);
			else
				a.add(list[i].x);
		}
		pw.println(a.size());
		for(int out: a)
			pw.print(out + " ");
		pw.println();
		pw.println(b.size());
		for(int out: b)
			pw.print(out + " ");
		pw.println();
		pw.close();
	}

	static class State implements Comparable<State> {
		public int x,y;
		public State(int a, int b)	{
			x=a;
			y=b;
		}
		public int compareTo(State s)	{
			return s.y - y;
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