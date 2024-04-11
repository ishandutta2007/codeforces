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
			int n = readInt();
			int m = readInt();
			int add = readInt();
			Integer[] list = new Integer[n];
			for(int i = 0; i < n; i++) {
				list[i] = readInt();
			}
			Arrays.sort(list);
			Integer[] bikes = new Integer[m];
			for(int i = 0; i < m; i++) {
				bikes[i] = readInt();
			}
			Arrays.sort(bikes);
			int min = 0;
			int max = Math.min(n, m);
			long have = 0;
			while(min != max) {
				int mid = (min+max+1)/2;
				long use = 0;
				long bikeSum = 0;
				for(int i = 0; i < mid; i++) {
					use += Math.max(0, bikes[i] - list[list.length-mid+i]);
					bikeSum += bikes[i];
				}
				if(use <= add) {
					min = mid;
					have = Math.max(0, bikeSum - add);
				}
				else {
					max = mid-1;
				}
			}
			pw.println(min + " " + have);
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