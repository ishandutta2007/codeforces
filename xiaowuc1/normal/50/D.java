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
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			int k = readInt();
			double prob = 1 - readInt()/1000.;
			int x = readInt();
			int y = readInt();
			double[] dist = new double[n];
			for (int i = 0; i < dist.length; i++) {
				dist[i] = Math.hypot(x-readInt(),y-readInt());
			}
			double min = 0;
			double max = 1e7;
			for(int qqq = 0; qqq < 50; qqq++){
				double mid = (min+max)/2;
				double[] can = new double[n];
				for (int i = 0; i < can.length; i++) {
					double ratio = dist[i] / mid;
					can[i] = Math.min(1, Math.exp(1 - ratio * ratio));
				}
				double[][] dp = new double[n+1][n+1];
				dp[0][0] = 1;
				for(int i = 0; i < n; i++)	{
					for(int j = 0; j <= i; j++)	{
						dp[i+1][j+1] += dp[i][j] * can[i];
						dp[i+1][j] += dp[i][j] * (1 - can[i]);
					}
				}
				double ret = 0;
				for(int i = k; i <= n; i++)	{
					ret += dp[n][i];
				}
				if(ret >= prob)	{
					max = mid;
				}
				else	{
					min = mid;
				}
			}
			pw.println(min);
		}
		pw.close();
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