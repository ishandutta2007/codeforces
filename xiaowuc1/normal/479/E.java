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
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			int a = readInt()-1;
			int b = readInt()-1;
			int qqq = readInt();
			long[] dp = new long[n];
			dp[a] = 1;
			while(qqq-- > 0) {
				long[] inc = new long[n+1];
				for(int i = 0; i < n; i++) {
					if(dp[i] == 0) continue;
					int dist = Math.abs(i - b);
					int low = Math.max(0, i - (dist-1));
					int high = Math.min(n-1, i + (dist-1));
					inc[low] += dp[i];
					inc[i] += MOD - dp[i];
					inc[i+1] += dp[i];
					inc[high+1] += MOD - dp[i];
				}
				long[] next = new long[n];
				next[0] = inc[0] % MOD;
				for(int i = 1; i < n; i++) {
					next[i] = inc[i] + next[i-1];
					next[i] %= MOD;
				}
				next[b] = 0;
				dp = next;
			}
			long ret = 0;
			for(long out: dp) {
				ret += out;
				ret %= MOD;
			}
			pw.println(ret);
		}
		pw.close();
	}

	static final int MOD = 1000000007;
	
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