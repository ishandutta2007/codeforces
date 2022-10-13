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
			int min = -2000000000;
			int max = 2000000000;
			while(n-- > 0) {
				String str = nextToken();
				int k = readInt();
				if(str.equals(">=")) {
					k--;
					str = ">";
				}
				if(str.equals("<=")) {
					k++;
					str = "<";
				}
				String correct = nextToken();
				if(str.equals(">") && correct.equals("Y")) {
					min = Math.max(min, k+1);
				}
				if(str.equals("<") && correct.equals("Y")) {
					max = Math.min(max, k-1);
				}
				if(str.equals(">") && correct.equals("N")) {
					max = Math.min(max, k);
				}
				if(str.equals("<") && correct.equals("N")) {
					min = Math.max(min, k);
				}
			}
			if(min > max) pw.println("Impossible");
			else pw.println(min);
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