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
			int[] rowCount = new int[n];
			int[] colCount = new int[m];
			boolean[][] is = new boolean[n][m];
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < m; j++) {
					is[i][j] = readInt() == 1;
					if(is[i][j]) {
						rowCount[i]++;
						colCount[j]++;
					}
				}
			}
			boolean[][] load = new boolean[n][m];
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < m; j++) {
					if(rowCount[i] == m && colCount[j] == n) {
						load[i][j] = true;
					}
				}
			}
			boolean[][] get = new boolean[n][m];
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < m; j++) {
					if(load[i][j]) {
						for(int k = 0; k < n; k++) {
							get[k][j] = true;
						}
						for(int l = 0; l < m; l++) {
							get[i][l] = true;
						}
					}
				}
			}
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < m; j++) {
					if(get[i][j] != is[i][j]) {
						pw.println("NO");
						exitImmediately();
					}
				}
			}
			pw.println("YES");
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < m; j++) {
					if(load[i][j]) {
						pw.print("1 ");
					}
					else {
						pw.print("0 ");
					}
				}
				pw.println();
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