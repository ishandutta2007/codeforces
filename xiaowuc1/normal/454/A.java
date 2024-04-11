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
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					int dist = Math.abs(i - n/2) + Math.abs(j - n/2);
					if(dist <= n/2) {
						pw.print("D");
					}
					else {
						pw.print("*");
					}
				}
				pw.println();
			}
		}
		pw.close();
	}

	public static long pow(long b, long e, long m) {
		long r = 1;
		while(e > 0) {
			if(e%2 == 1) {
				r *= b;
				r %= m;
			}
			b *= b;
			b %= m;
			e /= 2;
		}
		return r;
	}

	public static int sum(long x) {
		int ret = 0;
		while(x > 0) {
			ret += x%10;
			x /= 10;
		}
		return ret;
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