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

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int n = readInt();
		int k = readInt();
		int[] start = new int[n];
		int[] time = new int[n];
		for(int i = 0; i < n; i++)	{
			start[i] = readInt();
			time[i] = readInt();
		}
		int[][] dp = new int[n+1][k+1];
		for(int i = 0; i < dp.length; i++)	{
			Arrays.fill(dp[i], 1 << 25);
		}
		dp[0][0] = 0;
		for(int i = 0; i < n; i++)	{
			for(int j = 0; j <= k; j++)	{
				if(dp[i][j] == 1<<25)
					continue;
				dp[i+1][j] = Math.min(dp[i+1][j], Math.max(start[i], dp[i][j]+1) + time[i]-1);
				if(j < k)	{
					dp[i+1][j+1] = Math.min(dp[i+1][j+1], dp[i][j]);
				}
			}
		}
		int ret = 0;
		for(int i = 0; i < n; i++)	{
			for(int j = 0; j <= k; j++)	{
				ret = Math.max(ret, start[i] - dp[i][j] - 1);
			}
		}
		for(int j = 0; j <= k; j++)	{
			ret = Math.max(ret, 86400 - dp[n][j]);
		}
		pw.println(ret);
		pw.close();
	}

	/* NOTEBOOK CODE */

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