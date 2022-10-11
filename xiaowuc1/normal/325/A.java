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

public class A {
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
			int[] x1 = new int[n];
			int[] y1 = new int[n];
			int[] x2 = new int[n];
			int[] y2 = new int[n];
			long total = 0;
			int maxX = 0;
			int minX = Integer.MAX_VALUE;
			int maxY = 0;
			int minY = Integer.MAX_VALUE;
			for (int i = 0; i < y2.length; i++) {
				x1[i] = readInt();
				y1[i] = readInt();
				x2[i] = readInt();
				y2[i] = readInt();
				total += (x2[i] - x1[i]) * (y2[i] - y1[i]);
				minX = Math.min(minX, x1[i]);
				minY = Math.min(minY, y1[i]);
				maxX = Math.max(maxX, x2[i]);
				maxY = Math.max(maxY, y2[i]);
			}
			boolean can = true;
			if(maxY - minY != maxX - minX) can = false;
			if((maxY - minY)*(maxX-minX) != total) can = false;
			pw.println(can ? "YES" : "NO");
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