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
			int[] list = new int[n];
			int[] sorted = new int[n];
			for(int i = 0; i < n; i++) {
				sorted[i] = list[i] = readInt();
			}
			for(int a = 0; a < n; a++) {
				int x = (int)(n*Math.random());
				int y = (int)(n*Math.random());
				if(sorted[x] != sorted[y]) {
					sorted[x] ^= sorted[y];
					sorted[y] ^= sorted[x];
					sorted[x] ^= sorted[y];
				}
			}
			Arrays.sort(sorted);
			long[] prefixList = new long[n+1];
			long[] sortedList = new long[n+1];
			for(int i = 0; i < n; i++) {
				prefixList[i+1] = prefixList[i] + list[i];
				sortedList[i+1] = sortedList[i] + sorted[i];
			}
			int qqq = readInt();
			while(qqq-- > 0) {
				int type = readInt();
				int l = readInt();
				int r = readInt();
				long[] array = type == 1 ? prefixList : sortedList;
				pw.println(array[r] - array[l-1]);
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