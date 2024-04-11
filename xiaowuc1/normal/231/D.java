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
		int x = readInt();
		int y = readInt();
		int z = readInt();
		int x1 = readInt();
		int y1 = readInt();
		int z1 = readInt();
		int a = readInt();
		int b = readInt();
		int c = readInt();
		int d = readInt();
		int e = readInt();
		int f = readInt();
		int ret = 0;
		if(y < 0)
			ret += a;
		if(y > y1)
			ret += b;
		if(z < 0)
			ret += c;
		if(z > z1)
			ret += d;
		if(x < 0)
			ret += e;
		if(x > x1)
			ret += f;
		pw.println(ret);
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