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
			int k = readInt();
			int d = readInt();
			final int MOD = 1000000007;
			long[][] dp = new long[n+1][2];
			dp[0][0] = 1;
			long ret = 0;
			for(int qqq = 1; qqq <= n; qqq++) {
				long[][] next = new long[n+1][2];
				for(int i = 0; i < n; i++) {
					for(int j = 0; j < 2; j++) {
						for(int a = 1; a <= k; a++) {
							int nextI = i+a;
							int nextJ = (a >= d) ? 1 : j;
							if(nextI <= n) {
								next[nextI][nextJ] += dp[i][j];
								next[nextI][nextJ] %= MOD;
							}
						}
					}
				}
				ret += next[n][1];
				ret %= MOD;
				dp = next;
			}
			pw.println(ret);
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