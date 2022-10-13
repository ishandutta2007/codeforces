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
			int[] a = new int[]{readInt(), readInt()};
			int[] b = new int[]{readInt(), readInt()};
			int[] c = new int[]{readInt(), readInt()};
			boolean ret = false;
			ret |= solve(a[0], a[1], b[0], b[1], c[0], c[1]);
			ret |= solve(a[0], a[1], b[0], b[1], c[1], c[0]);
			ret |= solve(a[0], a[1], b[1], b[0], c[0], c[1]);
			ret |= solve(a[0], a[1], b[1], b[0], c[1], c[0]);
			pw.println(ret ? "YES" : "NO");
		}
		exitImmediately();
	}

	public static boolean solve(int x, int y, int x1, int y1, int x2, int y2) {
		if(Math.max(x1, x2) > x) return false;
		if(Math.max(y1, y2) > y) return false;
		if(x1 + x2 <= x) return true;
		if(y1 + y2 <= y) return true;
		return false;
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