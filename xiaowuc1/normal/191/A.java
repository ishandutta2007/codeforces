import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

import com.sun.org.apache.bcel.internal.generic.LLOAD;


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

	static int[] dx = new int[]{-1,0,1,0};
	static int[] dy = new int[]{0,1,0,-1};

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			int[][] dp = new int[26][26];
			while(n-- > 0)	{
				String str = nextToken();
				int first = str.charAt(0) - 'a';
				int last = str.charAt(str.length()-1) - 'a';
				for(int start = 0; start < 26; start++)	{
					if(dp[start][first] > 0)	{
						dp[start][last] = Math.max(dp[start][last], dp[start][first] + str.length());
					}
				}
				dp[first][last] = Math.max(dp[first][last], str.length());
			}
			int ret = 0;
			for (int i = 0; i < dp.length; i++) {
				ret = Math.max(ret, dp[i][i]);
			}
			pw.println(ret);
		}
		pw.close();
	}

	static class Vertex	implements Comparable<Vertex> {
		public int x,y,w;

		public Vertex(int x, int y, int w) {
			super();
			this.x = x;
			this.y = y;
			this.w = w;
		}

		public int compareTo(Vertex curr)	{
			return w - curr.w;
		}

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