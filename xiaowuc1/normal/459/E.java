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
			Edge[] list = new Edge[m];
			for(int i = 0; i < m; i++) {
				list[i] = new Edge(readInt()-1, readInt()-1, readInt());
			}
			Arrays.sort(list);
			int[] dp = new int[n];
			int[] next = new int[n];
			int last = -1;
			ArrayList<Integer> updated = new ArrayList<Integer>();
			for(Edge out: list) {
				if(out.w != last) {
					for(int out2: updated) {
						dp[out2] = next[out2];
					}
					updated = new ArrayList<Integer>();
				}
				next[out.b] = Math.max(next[out.b], dp[out.a]+1);
				updated.add(out.b);
				last = out.w;
			}
			int ret = 0;
			for(int out: next) {
				ret = Math.max(ret, out);
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