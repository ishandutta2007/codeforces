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
			String a = nextToken();
			String b = nextToken();
			a = new StringBuilder(a).reverse().toString();
			b = new StringBuilder(b).reverse().toString();
			int maxLen = Math.max(a.length(), b.length());
			long[] x = new long[maxLen];
			long[] y = new long[maxLen];
			for(int i = 0; i < a.length(); i++) {
				x[i] = a.charAt(i) - '0';
			}
			for(int i = 0; i < b.length(); i++) {
				y[i] = b.charAt(i) - '0';
			}
			for(int i = maxLen-1; i >= 0; i--) {
				if(x[i] - y[i] > 1) {
					pw.println(">");
					exitImmediately();
				}
				if(y[i] - x[i] > 1) {
					pw.println("<");
					exitImmediately();
				}
				if(i <= 1) {
					if(x[i] > y[i]) {
						pw.println(">");
						exitImmediately();
					}
					if(y[i] > x[i]) {
						pw.println("<");
						exitImmediately();
					}
				}
				if(x[i] > y[i]) {
					if(i-1 >= 0) x[i-1]++;
					if(i-2 >= 0) x[i-2]++;
				}
				if(y[i] > x[i]) {
					if(i-1 >= 0) y[i-1]++;
					if(i-2 >= 0) y[i-2]++;
				}
			}
			pw.println("=");
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