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
			int[][] dp = new int[n+1][2*n+5];
			for (int i = 0; i < dp.length; i++) {
				Arrays.fill(dp[i], 1 << 25);
			}
			int[] t = new int[n];
			int[] w = new int[n];
			for (int i = 0; i < w.length; i++) {
				t[i] = readInt();
				w[i] = readInt();
			}
			dp[0][0] = 0;
			for(int i = 0; i < n; i++)	{
				for(int j = 0; j <= 2*n; j++)	{
					dp[i+1][j] = Math.min(dp[i+1][j], dp[i][j] + w[i]);
					dp[i+1][j+t[i]] = Math.min(dp[i+1][j+t[i]], dp[i][j]);
				}
			}
			for(int k = 0; true; k++)	{
				if(k >= dp[n][k])	{
					pw.println(k);
					break;
				}
			}
		}
		pw.close();
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