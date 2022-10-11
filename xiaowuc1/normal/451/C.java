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
		//int qq = 1;
		//int qq = Integer.MAX_VALUE;
		int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			long n = readLong();
			long k = readLong();
			long d1 = readLong();
			long d2 = readLong();
			if(n%3!=0) {
				pw.println("no");
				continue;
			}
			n /= 3;
			if((k-d1-d2)%3 == 0) {
				long x = (k-d1-d2)/3;
				long y = x+d1;
				long z = x+d2;
				if(valid(x, y, z, n)) {
					pw.println("yes");
					continue;
				}
			}
			if((k-d1+d2)%3 == 0) {
				long x = (k-d1+d2)/3;
				long y = x+d1;
				long z = x-d2;
				if(valid(x, y, z, n)) {
					pw.println("yes");
					continue;
				}
			}
			if((k+d1-d2)%3 == 0) {
				long x = (k+d1-d2)/3;
				long y = x-d1;
				long z = x+d2;
				if(valid(x, y, z, n)) {
					pw.println("yes");
					continue;
				}
			}
			if((k+d1+d2)%3 == 0) {
				long x = (k+d1+d2)/3;
				long y = x-d1;
				long z = x-d2;
				if(valid(x, y, z, n)) {
					pw.println("yes");
					continue;
				}
			}
			
			pw.println("no");
		}
		pw.close();
	}

	public static boolean valid(long a, long b, long c, long n) {
		return Math.min(a, Math.min(b, c)) >= 0 && Math.max(a, Math.max(b, c)) <= n;
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