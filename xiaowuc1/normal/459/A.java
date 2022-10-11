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
			int x1 = readInt();
			int y1 = readInt();
			int x2 = readInt();
			int y2 = readInt();
			int x3 = Integer.MAX_VALUE;
			int y3 = Integer.MAX_VALUE;
			int x4 = Integer.MAX_VALUE;
			int y4 = Integer.MAX_VALUE;
			if(x1 == x2) {
				x3 = x4 = x1 + Math.abs(y1 - y2);
				y3 = y1;
				y4 = y2;
			}
			else if(y1 == y2) {
				y3 = y4 = y1 + Math.abs(x1 - x2);
				x3 = x1;
				x4 = x2;
			}
			else if(Math.abs(x1 - x2) == Math.abs(y1 - y2)) {
				x3 = x1;
				x4 = x2;
				y3 = y2;
				y4 = y1;
			}
			else {
				pw.println(-1);
				exitImmediately();
			}
			pw.println(x3 + " " + y3 + " " + x4 + " " + y4);
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