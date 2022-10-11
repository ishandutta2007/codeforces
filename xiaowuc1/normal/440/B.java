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
			long[] list = new long[n];
			long sum = 0;
			for(int i = 0; i < n; i++) {
				sum += list[i] = readLong();
			}
			sum /= n;
			long ret = 0;
			int below = 0;
			int above = 0;
			while(true) {
				while(below < n && list[below] >= sum) below++;
				while(above < n && list[above] <= sum) above++;
				if(below == n) break;
				long diff = Math.min(sum - list[below], list[above] - sum);
				ret += diff * Math.abs(below - above);
				list[below] += diff;
				list[above] -= diff;
			}
			pw.println(ret);
		}
		pw.close();
	}

	static class Edge implements Comparable<Edge> {
		public int a,b,w;
		public Edge(int x, int y, int z) {
			a=x;
			b=y;
			w=z;
		}
		public int compareTo(Edge e) {
			return w - e.w;
		}
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