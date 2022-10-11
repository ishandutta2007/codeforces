import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*; 
import java.util.*;
import java.util.regex.*;
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

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++) {
			int n = readInt();
			int qqq = readInt();
			long[] v = new long[n];
			int[] c = new int[n];
			for(int i = 0; i < n; i++) {
				v[i] = readLong();
			}
			for(int i = 0; i < n; i++) {
				c[i] = readInt()-1;
			}
			long[] best = new long[n];
			while(qqq-- > 0) {
				long a = readLong();
				long b = readLong();
				long ret = 0;
				Arrays.fill(best, Long.MIN_VALUE);
				int fC = -1;
				long fV = Long.MIN_VALUE;
				int sC = -1;
				long sV = Long.MIN_VALUE;
				for(int i = 0; i < n; i++) {
					long next = Long.MIN_VALUE;
					// choose that color
					if(best[c[i]] != Long.MIN_VALUE) {
						next = Math.max(next, best[c[i]] + a * v[i]);
					}
					// start a new thing
					next = Math.max(next, b * v[i]);
					// choose the best other color to follow
					if(fC != -1 && fC != c[i]) {
						next = Math.max(next, fV + b * v[i]);
					}
					if(sC != -1 && sC != c[i]) {
						next = Math.max(next, sV + b * v[i]);
					}
					ret = Math.max(ret, next);
					if(next > best[c[i]]) {
						best[c[i]] = next;
						if(fC == -1 || next > fV) {
							if(fC == c[i]) {
								fV = next;
							}
							else {
								sC = fC;
								sV = fV;
								fC = c[i];
								fV = next;
							}
						}
						else if(sC == -1 || next > sV) {
							sC = c[i];
							sV = next;
						}
					}
				}
				pw.println(ret);
			}
		}
		exitImmediately();
	}

	private static void exitImmediately() {
		pw.close();
		System.exit(0);
	}

	private static long readLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	private static double readDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	private static int readInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	private static String nextLine() throws IOException  {
		if(!br.ready()) {
			exitImmediately();
		}
		st = null;
		return br.readLine();
	}

	private static String nextToken() throws IOException  {
		while(st == null || !st.hasMoreTokens())  {
			if(!br.ready()) {
				exitImmediately();
			}
			st = new StringTokenizer(br.readLine().trim());
		}
		return st.nextToken();
	}
}