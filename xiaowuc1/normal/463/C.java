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
			int[][] grid = new int[n][n];
			long[] sum = new long[5000];
			long[] diff = new long[5000];
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					grid[i][j] = readInt();
					sum[i+j] += grid[i][j];
					diff[i-j+2000] += grid[i][j];
				}
			}
			int oddX = -1;
			int oddY = -1;
			long odd = -1;
			int evenX = -1;
			int evenY = -1;
			long even = -1;
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					long curr = sum[i+j] + diff[i-j+2000] - grid[i][j];
					if(i%2 == j%2) {
						if(curr > odd) {
							odd = curr;
							oddX = i;
							oddY = j;
						}
					}
					else {
						if(curr > even) {
							even = curr;
							evenX = i;
							evenY = j;
						}
					}
				}
			}
			pw.println(even + odd);
			pw.println(++oddX + " " + ++oddY + " " + ++evenX + " " + ++evenY);
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