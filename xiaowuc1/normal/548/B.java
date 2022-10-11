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
			int r = readInt();
			int c = readInt();
			int qqq = readInt();
			int[][] grid = new int[r][c];
			int[] best = new int[r];
			for(int i = 0; i < r; i++) {
				for(int j = 0; j < c; j++) {
					grid[i][j] = readInt();
				}
				best[i] = compute(grid[i]);
			}
			while(qqq-- > 0) {
				int a = readInt()-1;
				int b = readInt()-1;
				grid[a][b] ^= 1;
				best[a] = compute(grid[a]);
				int ret = 0;
				for(int out: best) {
					ret = Math.max(ret, out);
				}
				pw.println(ret);
			}
		}
		exitImmediately();
	}

	public static int compute(int[] list) {
		int ret = 0;
		for(int i = 0; i < list.length;) {
			if(list[i] == 0) {
				i++;
				continue;
			}
			int j = i+1;
			while(j < list.length && list[j] == 1) {
				j++;
			}
			ret = Math.max(ret, j-i);
			i = j;
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