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

	static int[] list;
	
	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++) {
			int n = readInt();
			list = new int[n];
			for(int i = 0; i < n; i++) {
				list[i] = readInt();
			}
			pw.println(solve(0, n-1, 0));
		}
		exitImmediately();
	}

	public static int solve(int l, int r, int min) {
		if(l == r) return 1;
		int worst = l;
		for(int i = l+1; i <= r; i++) {
			if(list[i] < list[worst]) {
				worst = i;
			}
		}
		int ret = r-l+1;
		int curr = list[worst] - min;
		for(int i = l; i <= r && curr < ret;) {
			if(list[i] == list[worst]) {
				i++;
				continue;
			}
			int j = i+1;
			while(j <= r && list[j] != list[worst]) {
				j++;
			}
			curr += solve(i, j-1, list[worst]);
			i = j;
		}
		return Math.min(ret, curr);
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