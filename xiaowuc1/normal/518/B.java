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
			int[] a = count(nextToken());
			int[] b = count(nextToken());
			int x = 0;
			int y = 0;
			for(int i = 0; i < 256; i++) {
				int t = Math.min(a[i], b[i]);
				a[i] -= t;
				b[i] -= t;
				x += t;
			}
			for(int i = 0; i < 256; i++) {
				for(int j = 0; j < 256; j++) {
					if(Character.toUpperCase(i) != Character.toUpperCase(j)) continue;
					int t = Math.min(a[i], b[j]);
					a[i] -= t;
					b[j] -= t;
					y += t;
				}
			}
			pw.println(x + " " + y);
		}
		exitImmediately();
	}

	public static int[] count(String s) {
		int[] ret = new int[256];
		for(int i = 0; i < s.length(); i++) {
			ret[s.charAt(i)]++;
		}
		return ret;
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