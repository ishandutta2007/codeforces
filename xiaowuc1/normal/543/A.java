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

public class A {
	private static BufferedReader br;
	private static StringTokenizer st;
	private static PrintWriter pw;
	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			int m = readInt();
			int b = readInt();
			int[][] dp = new int[m+1][b+1];
			dp[0][0] = 1;
			int mod = readInt();
			while(n-- > 0) {
				int bugAdd = readInt();
				for(int i = 0; i+1 <= m; i++) {
					for(int j = 0; j + bugAdd <= b; j++) {
						dp[i+1][j+bugAdd] += dp[i][j];
						if(dp[i+1][j+bugAdd] >= mod) {
							dp[i+1][j+bugAdd] -= mod;
						}
					}
				}
			}
			int ret = 0;
			for(int a = 0; a <= b; a++) {
				ret += dp[m][a];
				if(ret >= mod) {
					ret -= mod;
				}
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