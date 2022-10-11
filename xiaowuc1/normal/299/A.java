import java.awt.*;
import java.awt.event.*;
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

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int qq = 1;
		//int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			boolean win = true;
			int max = Integer.MAX_VALUE;
			int[] list = new int[n];
			for(int i = 0; i < n; i++)	{
				list[i] = readInt();
				max = Math.min(max, list[i]);
			}
			for(int out: list)	{
				if(out%max!=0)	{
					win = false;
				}
			}
			if(!win)	{
				max = -1;
			}
			pw.println(max);
		}
		pw.close();
	}

	static class Compare implements Comparator<Set<Integer>>	{
		public int compare(Set<Integer> a, Set<Integer> b)	{
			return a.size() - b.size();
		}
	}

	public static boolean square(int x)	{
		int y = (int)Math.sqrt(x);
		while(y*y<x) y++;
		return y*y==x;
	}

	private static void exitImmediately()	{
		pw.close();
		System.exit(0);
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
				exitImmediately();
			}
			st = new StringTokenizer(br.readLine().trim());
		}
		return st.nextToken();
	}
}