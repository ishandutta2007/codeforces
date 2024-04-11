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
			String s = br.readLine();
			int ret = 0;
			for(int i = 0; i < s.length(); i++) {
				if(s.charAt(i) != '.') continue;
				int toRight = i-1;
				while(toRight >= 0 && s.charAt(toRight) == '.') {
					toRight--;
				}
				int toLeft = i+1;
				while(toLeft < s.length() && s.charAt(toLeft) == '.') {
					toLeft++;
				}
				if(toRight == -1) {
					if(toLeft == s.length() || s.charAt(toLeft) == 'R') {
						ret++;
					}
				}
				else if(s.charAt(toRight) == 'L'){
					ret++;
				}
				else {
					if(toLeft < s.length() && 2 * i == toLeft + toRight) {
						ret++;
					}
				}
			}
			pw.println(ret);
		}
		pw.close();
	}

	static class State {
		public int r,c;
		public State(int a, int b) {
			r=a;
			c=b;
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