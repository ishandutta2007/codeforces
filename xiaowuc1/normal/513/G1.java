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

	static char[][] grid;
	static boolean[][] seen;
	static boolean[][] processed;
	
	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++) {
			int n = readInt();
			int k = readInt();
			int[] list = new int[n];
			for(int i = 0; i < n; i++) {
				list[i] = readInt();
			}
			num = 0;
			denom = 0;
			dfs(list, k);
			pw.println(1.0*num/denom);
		}
		exitImmediately();
	}

	public static void dfs(int[] list, int k) {
		if(k==0) {
			count(list);
			return;
		}
		for(int i = 0; i < list.length; i++) {
			for(int j = i; j < list.length; j++) {
				dfs(reverse(list, i, j), k-1);
			}
		}
	}
	
	public static int[] reverse(int[] list, int a, int b) {
		int[] ret = new int[list.length];
		for(int i = 0; i < ret.length; i++) {
			ret[i] = list[i];
		}
		int y = b;
		for(int x = a; x <= b; x++) {
			ret[x] = list[y--];
		}
		return ret;
	}
	
	public static void count(int[] list) {
		denom++;
		for(int i = 0; i < list.length; i++) {
			for(int j = i+1; j < list.length; j++) {
				if(list[i] > list[j]) {
					num++;
				}
			}
		}
	}
	
	static long num = 0;
	static long denom = 0;
	
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