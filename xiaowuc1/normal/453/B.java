import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

import static java.lang.Math.min;
import static java.lang.Math.max;

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
			int[] primes = new int[]{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59};
			int n = readInt();
			int[] list = new int[n];
			for(int i = 0; i < n; i++) {
				list[i] = readInt();
			}
			int[] mask = new int[61];
			for(int i = 0; i < primes.length; i++) {
				for(int j = 1; j * primes[i] < mask.length; j++) {
					mask[j * primes[i]] |= 1 << i;
				}
			}
			int[][] dp = new int[n+1][1 << primes.length];
			for(int i = 0; i < dp.length; i++) {
				Arrays.fill(dp[i], 1 << 25);
			}
			int[][] parentNumber = new int[n+1][1 << primes.length];
			for(int a = 1; a <= 60; a++) {
				if(Math.abs(list[0] - a) < dp[1][mask[a]]) {
					dp[1][mask[a]] = Math.abs(list[0] - a);
					parentNumber[1][mask[a]] = a;
				}
			}
			for(int i = 1; i < n; i++) {
				for(int right = 0; right < dp[i].length; right++) {
					if(dp[i][right] == 1 << 25) continue;
					for(int j = 1; j <= 60; j++) {
						if((right&(mask[j])) != 0) continue;
						int nextVal = dp[i][right] + Math.abs(list[i] - j);
						if(nextVal < dp[i+1][right | mask[j]]) {
							dp[i+1][right | mask[j]] = nextVal;
							parentNumber[i+1][right | mask[j]] = j;
						}
					}
				}
			}
			int bestRight = 0;
			for(int a = 1; a < dp[n].length; a++) {
				if(dp[n][a] < dp[n][bestRight]) {
					bestRight = a;
				}
			}
			LinkedList<Integer> ret = new LinkedList<Integer>();
			int left = n;
			while(left > 0) {
				ret.addFirst(parentNumber[left][bestRight]);
				left--;
				bestRight ^= mask[ret.peekFirst()];
			}
			for(int out: ret) {
				pw.print(out + " ");
			}
			pw.println();
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