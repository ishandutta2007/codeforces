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
			int m = readInt();
			boolean[][][] connected = new boolean[m][n][n];
			for(int a = 0; a < m; a++) {
				for(int i = 0; i < n; i++) {
					connected[a][i][i] = true;
				}
			}
			for(int a = 0; a < m; a++) {
				int x = readInt()-1;
				int y = readInt()-1;
				int c = readInt()-1;
				connected[c][x][y] = connected[c][y][x] = true;
			}
			for(int x = 0; x < connected.length; x++) {
				for(int k = 0; k < n; k++) {
					for(int i = 0; i < n; i++) {
						for(int j = 0; j < n; j++) {
							connected[x][i][j] |= connected[x][i][k] && connected[x][k][j];
						}
					}
				}
			}
			int qqq = readInt();
			while(qqq-- > 0) {
				int x = readInt()-1;
				int y = readInt()-1;
				int ret = 0;
				for(int i = 0; i < m; i++) {
					if(connected[i][x][y]) {
						ret++;
					}
				}
				pw.println(ret);
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