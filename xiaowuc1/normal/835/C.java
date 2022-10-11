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
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			int qqq = readInt();
			int k = readInt();
			int[][][] dp = new int[k+1][101][101];
			while(n-- > 0) {
				int x = readInt();
				int y = readInt();
				int start = readInt();
				for(int i = 0; i <= k; i++) {
					dp[i][x][y] += (i+start)%(k+1);
				}
			}
			for(int[][] internal: dp) {
				for(int i = 1; i <= 100; i++) {
					for(int j = 1; j <= 100; j++) {
						internal[i][j] += internal[i][j-1] + internal[i-1][j] - internal[i-1][j-1];
					}
				}
			}
			while(qqq-- > 0) {
				int t = readInt()%(k+1);
				int x1 = readInt();
				int y1 = readInt();
				int x2 = readInt();
				int y2 = readInt();
				pw.println(dp[t][x2][y2] - dp[t][x1-1][y2] - dp[t][x2][y1-1] + dp[t][x1-1][y1-1]);
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
		String s = br.readLine();
		if(s == null) {
			exitImmediately();
		}
		st = null;
		return s;
	}

	private static String nextToken() throws IOException  {
		while(st == null || !st.hasMoreTokens())  {
			st = new StringTokenizer(nextLine().trim());
		}
		return st.nextToken();
	}
}