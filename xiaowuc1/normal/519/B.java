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
			int[][] grid = new int[3][];
			for(int i = 0; i < grid.length; i++) {
				grid[i] = new int[n-i];
				for(int j = 0; j < grid[i].length; j++) {
					grid[i][j] = readInt();
				}
			}
			pw.println(get(grid[0], grid[1]));
			pw.println(get(grid[1], grid[2]));
		}
		exitImmediately();
	}
	
	public static int get(int[] a, int[] b) {
		PriorityQueue<Integer> q1 = new PriorityQueue<Integer>();
		for(int out: a) q1.add(out);
		PriorityQueue<Integer> q2 = new PriorityQueue<Integer>();
		for(int out: b) q2.add(out);
		while(!q2.isEmpty()) {
			int x = q1.poll();
			int y = q2.poll();
			if(x != y) return x;
		}
		return q1.poll();
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