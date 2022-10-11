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

	static String base = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int n = readInt();
		TreeSet<Integer> set = new TreeSet<Integer>();
		PriorityQueue<State> q = new PriorityQueue<State>();
		for(int i = 0; i < n; i++)	{
			q.add(new State(readInt(), i));
		}
		int[] ret = new int[n];
		Arrays.fill(ret, -1);
		while(!q.isEmpty())	{
			State curr = q.poll();
			if(!set.isEmpty())	{
				Integer out = set.last();
				ret[curr.index] = Math.max(ret[curr.index], out - curr.index - 1);
			}
			set.add(curr.index);
		}
		StringBuilder sb = new StringBuilder();
		for(int out: ret)
			sb.append(out + " ");
		pw.println(sb.toString().trim());
		pw.close();
	}

	static class State implements Comparable<State> {
		public int age;
		public int index;
		public State(int a, int b)	{
			age = a;
			index = b;
		}
		public int compareTo(State s)	{
			if(age != s.age)
				return age - s.age;
			return index - s.index;
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