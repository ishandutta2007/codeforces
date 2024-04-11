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
			boolean[][][][] can = new boolean[r][c][r][c];
			String row = nextToken();
			String col = nextToken();
			for(int i = 0; i < r; i++) {
				for(int j = 0; j < c; j++) {
					if(row.charAt(i) == '>' && j+1 < c) {
						can[i][j][i][j+1] = true;
					}
					if(row.charAt(i) == '<' && j > 0) {
						can[i][j][i][j-1] = true;
					}
					if(col.charAt(j) == '^' && i > 0) {
						can[i][j][i-1][j] = true;
					}
					if(col.charAt(j) == 'v' && i+1 < r) {
						can[i][j][i+1][j] = true;
					}
				}
			}
			for(int a = 0; a < r; a++) {
				for(int b = 0; b < c; b++) {
					for(int i = 0; i < r; i++) {
						for(int j = 0; j < c; j++) {
							for(int k = 0; k < r; k++) {
								for(int l = 0; l < c; l++) {
									can[i][j][k][l] |= can[i][j][a][b] && can[a][b][k][l];
								}
							}
						}
					}
				}
			}
			boolean bad = false;
			for(int i = 0; i < r; i++) {
				for(int j = 0; j < c; j++) {
					for(int k = 0; k < r; k++) {
						for(int l = 0; l < c; l++) {
							bad |= !can[i][j][k][l];
						}
					}
				}
			}
			if(bad) {
				pw.println("NO");
			}
			else {
				pw.println("YES");
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