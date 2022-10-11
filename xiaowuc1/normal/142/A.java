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

	static final long HASH = 3137;
	
	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int n = readInt();
		long min = Long.MAX_VALUE;
		long max = 0;
		for(int a = 1; a * a * a <= n; a++)	{
			if(n%a!=0)
				continue;
			for(int b = a; a * b * b <= n; b++)	{
				if(n%(a*b) != 0)
					continue;
				long x = a;
				long y = b;
				long z = n/a/b;
				max = Math.max((x+2)*(y+2)*(z+1)-n, max);
				max = Math.max((x+2)*(y+1)*(z+2)-n, max);
				max = Math.max((x+1)*(y+2)*(z+2)-n, max);
				min = Math.min((x+2)*(y+2)*(z+1)-n, min);
				min = Math.min((x+2)*(y+1)*(z+2)-n, min);
				min = Math.min((x+1)*(y+2)*(z+2)-n, min);
			}
		}
		pw.println(min + " " + max);
		pw.close();
	}

	static class State	{
		public int x,y;
		public State(int a, int b)	{
			x=a;
			y=b;
		}
		public int hashCode()	{
			return 3137*x+y;
		}
		public boolean equals(Object o)	{
			State s = (State)o;
			return x == s.x && y == s.y;
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