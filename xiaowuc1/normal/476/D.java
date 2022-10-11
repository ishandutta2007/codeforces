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
			int k = readInt();
			int[][] grid = new int[n][4];
			int curr = 1;
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < 3; j++) {
					grid[i][j] = curr;
					curr += 2;
				}
			}
			curr = 2;
			for(int i = 0; i < n; i++) {
				while(gcd(curr, grid[i][0]) > 1 || gcd(curr, grid[i][1]) > 1 || gcd(curr, grid[i][2]) > 1) {
					curr += 2;
				}
				grid[i][3] = curr;
				curr += 2;
			}
			int ans = 0;
			for(int[] out: grid) {
				ans = Math.max(out[2], Math.max(ans, out[3]));
			}
			pw.println(ans * 1L * k);
			for(int[] out: grid) {
				for(int out2: out) {
					pw.print(out2 * 1L * k);
					pw.print(' ');
				}
				pw.println();
			}
		}
		exitImmediately();
	}
	
	public static int gcd(int a, int b) {
		return a%b==0 ? b : gcd(b, a%b);
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