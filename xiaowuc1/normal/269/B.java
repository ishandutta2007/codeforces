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

	static Set<Integer>[] edges;

	static int k;

	static boolean[] seen;
	static boolean[] used;

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			int m = readInt();
			int[] dp = new int[m];
			Arrays.fill(dp, 1 << 25);
			for(int i = 0; i < n; i++)	{
				int curr = readInt() - 1;
				dp[curr] = Math.min(dp[curr], i);
				for(int a = 0; a <= curr; a++)	{
					dp[curr] = Math.min(dp[a], dp[curr]);
				}
				for(int a = 0; a < m; a++)	{
					if(a != curr)	{
						dp[a]++;
					}
				}
				nextToken();

			}
			int ret = Integer.MAX_VALUE;
			for(int out: dp)	{
				ret = Math.min(ret, out);
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