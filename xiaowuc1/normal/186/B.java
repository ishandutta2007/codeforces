import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

/*
br = new BufferedReader(new FileReader("input.txt"));
pw = new PrintWriter(new BufferedWriter(new FileWriter("output.txt")));
br = new BufferedReader(new InputStreamReader(System.in));
pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
 */

public class Main {
	private static BufferedReader br;
	private static StringTokenizer st;
	private static PrintWriter pw;

	static int numFloor;

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int n = readInt();
		int t1 = 100*readInt();
		int t2 = 100*readInt();
		int percentDrop = readInt();
		PriorityQueue<State> q = new PriorityQueue<State>();
		for(int i = 1; i <= n; i++)	{
			int r1 = readInt();
			int r2 = readInt();
			int first = r1 * t1 / 100 * (100-percentDrop) + r2 * t2;
			int second = r2 * t1 / 100 * (100-percentDrop) + r1 * t2;
			q.add(new State(i, Math.max(first, second)));
		}
		while(!q.isEmpty())	{
			pw.println(q.poll());
		}
		pw.close(); 
	}

	static class State implements Comparable<State> {
		public int i;
		public int h;
		public State(int a, int b)	{
			i=a;
			h=b;
		}
		public int compareTo(State s)	{
			if(h != s.h)	{
				return s.h - h;
			}
			return i - s.i;
		}
		public String toString()	{
			return i + " " + String.format("%.2f", h/100.);
		}
	}
	
	/* NOTEBOOK CODE */

	public static void loadArray(int[][] grid) throws IOException {
		for(int[] a: grid)
			loadArray(a);
	}

	public static void loadArray(int[] in) throws IOException {
		for(int i = 0; i < in.length; i++)
			in[i] = readInt();
	}

	public static void loadArray(long[] in) throws IOException {
		for(int i = 0; i < in.length; i++)
			in[i] = readLong();
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
			if(!br.ready())	{
				pw.close();
				System.exit(0);
			}
			st = new StringTokenizer(br.readLine().trim());
		}
		return st.nextToken();
	}
}