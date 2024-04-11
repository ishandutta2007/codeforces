import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.abs;
import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.util.Arrays.binarySearch;
import static java.util.Arrays.fill;
import static java.util.Arrays.sort;
import static java.util.Collections.binarySearch;
import static java.util.Collections.shuffle;
import static java.util.Collections.sort;

public class C {
	static StringTokenizer st;
	static BufferedReader br;
	static PrintWriter pw;

	/*
	 * sorting primitive arrays is bad
	 */
	
	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(
				System.out)));
		int n = readInt();
		int k = readInt();
		int[] list = new int[n];
		for(int i = 0; i < n; i++)
			list[i] = readInt();
		long[] dp = new long[n];
		dp[0] = 1;
		for(int i = 1; i < dp.length; i++)	{
			dp[i] = dp[i-1];
			dp[i] *= (k+i-1);
			dp[i] %= MOD;
			dp[i] *= pow(i, MOD-2);
			dp[i] %= MOD;
		}
		for(int i = 0; i < n; i++)	{
			long curr = 0;
			for(int a = i; a >= 0; a--)	{
				curr += dp[i-a] * list[a];
				curr %= MOD;
			}
			pw.print(curr);
			if(i != n-1)
				pw.print(" ");
		}
		pw.println();
		pw.close();
	}

	static final int MOD = 1000000007;
	
	public static int pow(long b, long e)	{
		long r = 1;
		while(e > 0)	{
			if(e%2==1)	{
				r *= b;
				r %= MOD;
			}
			b *= b;
			b %= MOD;
			e /= 2;
		}
		return (int)r;
	}
	
	public static long readLong() throws IOException {
		return parseLong(nextToken());
	}

	public static double readDouble() throws IOException {
		return parseDouble(nextToken());
	}

	public static int readInt() throws IOException {
		return parseInt(nextToken());
	}

	public static String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			if (!br.ready()) {
				pw.close();
				System.exit(0);
			}
			st = new StringTokenizer(br.readLine());
		}
		return st.nextToken();
	}
}