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
			char[][] grid = new char[][]
					{
					"+------------------------+".toCharArray(),
					"|#.#.#.#.#.#.#.#.#.#.#.|D|)".toCharArray(),
					"|#.#.#.#.#.#.#.#.#.#.#.|.|".toCharArray(),
					"|#.......................|".toCharArray(),
					"|#.#.#.#.#.#.#.#.#.#.#.|.|)".toCharArray(),
					"+------------------------+".toCharArray(),
					};
			int n = readInt();
			if(n >= 1) {
				grid[1][1] = 'O';
			}
			if(n >= 2) {
				grid[2][1] = 'O';
			}
			if(n >= 3) {
				grid[3][1] = 'O';
			}
			if(n >= 4) {
				grid[4][1] = 'O';
			}
			for(int i = 5; i <= n; i += 3) {
				grid[1][2*(i/3)+1] = 'O';
			}
			for(int i = 6; i <= n; i += 3) {
				grid[2][2*(i/3)-1] = 'O';
			}
			for(int i = 3; i <= Math.min(3,n); i += 4) {
				grid[3][2*(i/4)+1] = 'O';
			}
			for(int i = 7; i <= n; i += 3) {
				grid[4][2*(i/3)-1] = 'O';
			}
			for(char[] out: grid) {
				pw.println(new String(out));
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