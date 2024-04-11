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
			int[] list = new int[n];
			for(int i = 0; i < n; i++) {
				list[i] = readInt();
			}
			boolean[][] grid = new boolean[n][n];
			for(int i = 0; i < n; i++) {
				String s = nextToken();
				for(int j = 0; j < n; j++) {
					grid[i][j] = s.charAt(j) == '1';
				}
			}
			for(int k = 0; k < n; k++) {
				for(int i = 0; i < n; i++) {
					for(int j = 0; j < n; j++) {
						grid[i][j] |= grid[i][k] && grid[k][j];
					}
				}
			}
			while(true) {
				boolean improve = false;
				for(int i = 0; i < n; i++) {
					for(int j = i+1; j < n; j++) {
						if(list[i] > list[j] && grid[i][j]) {
							int a = list[i];
							list[i] = list[j];
							list[j] = a;
							improve = true;
						}
					}
				}
				if(!improve) {
					break;
				}
			}
			for(int out: list) {
				pw.print(out + " ");
			}
			pw.println();
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