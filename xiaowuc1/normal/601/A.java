import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.security.*;
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

	public static void main(String[] args) throws Exception {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			int m = readInt();
			int[][] a = new int[n][n];
			int[][] b = new int[n][n];
			for(int i = 0; i < n; i++) {
				Arrays.fill(a[i], 1 << 25);
				Arrays.fill(b[i], 1 << 25);
				a[i][i] = 0;
				b[i][i] = 0;
			}
			while(m-- > 0) {
				int x = readInt()-1;
				int y = readInt()-1;
				a[x][y] = 1;
				a[y][x] = 1;
			}
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					if(i == j) continue;
					if(a[i][j] == 1 << 25) b[i][j] = 1;
				}
			}
			for(int k = 0; k < n; k++) {
				for(int i = 0; i < n; i++) {
					for(int j = 0; j < n; j++) {
						a[i][j] = Math.min(a[i][j], a[i][k] + a[k][j]);
						b[i][j] = Math.min(b[i][j], b[i][k] + b[k][j]);
					}
				}
			}
			int ret = Math.max(a[0][n-1], b[0][n-1]);
			if(ret == 1 << 25) ret = -1;
			pw.println(ret);
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