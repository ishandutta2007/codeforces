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

	static int[][][][] dp;
	static int[][] prefix;
	
	public static void main(String[] args) throws Exception {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			int m = readInt();
			int qqq = readInt();
			dp = new int[n][m][n][m];
			prefix = new int[n+1][m+1];
			for(int i = 1; i <= n; i++) {
				String s = nextToken();
				for(int j = 1; j <= m; j++) {
					prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
					if(s.charAt(j-1) == '1') {
						prefix[i][j]++;
					}
				}
			}
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < m; j++) {
					for(int k = 0; k < n; k++) {
						Arrays.fill(dp[i][j][k], -1);
					}
				}
			}
			while(qqq-- > 0) {
				int a = readInt()-1;
				int b = readInt()-1;
				int c = readInt()-1;
				int d = readInt()-1;
				pw.println(solve(a, b, c, d));
			}
		}
		exitImmediately();
	}

	public static int getSum(int a, int b, int c, int d) {
		return prefix[c+1][d+1] - prefix[a][d+1] - prefix[c+1][b] + prefix[a][b];
	}
	
	public static int solve(int a, int b, int c, int d) {
		if(a > c || b > d) return 0;
		if(dp[a][b][c][d] < 0) {
			dp[a][b][c][d] = 0;
			if(getSum(a,b,c,d) == 0) {
				int x = c-a+1;
				int y = d-b+1;
				dp[a][b][c][d] = (x*(x+1))/2 * (y*(y+1))/2;
			}
			else {
				int x = -1, y = -1;
				for(int i = a; x == -1 && i <= c; i++) {
					for(int j = b; x == -1 && j <= d; j++) {
						if(getSum(i, j, i, j) == 1) {
							x = i;
							y = j;
						}
					}
				}
				if(x == -1) throw new RuntimeException("OOPS");
				dp[a][b][c][d] = solve(a, b, c, y-1) + solve(a, y+1, c, d);
				dp[a][b][c][d] += solve(a, b, x-1, d) + solve(x+1, b, c, d);
				
				dp[a][b][c][d] -= solve(a, b, x-1, y-1) + solve(a, y+1, x-1, d);
				dp[a][b][c][d] -= solve(x+1, b, c, y-1) + solve(x+1, y+1, c, d);
			}
		}
		return dp[a][b][c][d];
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