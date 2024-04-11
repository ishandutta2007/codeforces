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

public class C {
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
			int k = readInt();
			int[] time = new int[k];
			int[] height = new int[k];
			for(int i = 0; i < k; i++) {
				time[i] = readInt();
				height[i] = readInt();
			}
			boolean possible = true;
			for(int i = 0; i < k-1; i++) {
				if(Math.abs(height[i+1] - height[i]) > time[i+1] - time[i]) {
					possible = false;
				}
			}
			if(!possible) {
				pw.println("IMPOSSIBLE");
				continue;
			}
			int ret = time[0] + height[0] - 1;
			ret = Math.max(ret, height[k-1] + (n - time[k-1]));
			for(int i = 0; i < k-1; i++) {
				int timeFree = time[i+1] - time[i] - Math.abs(height[i+1] - height[i]);
				ret = Math.max(ret, timeFree / 2 + Math.max(height[i], height[i+1]));
			}
			pw.println(ret);
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