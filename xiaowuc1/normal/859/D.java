import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

public class D {
	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter pw;

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++) {
			int k = readInt();
			int n = 1 << k;
			p = new double[n][n];
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					p[i][j] = readDouble() / 100.;
				}
			}
			win = new double[n][k+1];
			for(int i = 0; i < n; i++) {
				win[i][0] = 1;
			}
			for(int round = 1; round <= k; round++) {
				for(int start = 0; start < n; start += 1 << round) {
					int num = 1 << (round-1);
					int lhs = start;
					int rhs = start + num;
					for(int a = lhs; a < lhs + num; a++) {
						for(int b = rhs; b < rhs + num; b++) {
							win[a][round] += win[a][round-1] * win[b][round-1] * p[a][b];
							win[b][round] += win[a][round-1] * win[b][round-1] * p[b][a];
						}
					}
				}
			}
			dp = new double[n][k+1];
			for(int i = 0; i < n; i++) {
				Arrays.fill(dp[i], -1);
			}
			double ret = 0;
			for(int i = 0; i < n; i++) {
				ret = Math.max(ret, solve(i, k));
			}
			pw.println(ret);
		}
		pw.close();
	}

	public static double solve(int indexWin, int roundsWon) {
		if(dp[indexWin][roundsWon] >= 0) {
			return dp[indexWin][roundsWon];
		}
		if(roundsWon == 0) return 0;
		int num = 1 << (roundsWon-1);
		int bracket = 0;
		while(bracket + 2*num <= indexWin) {
			bracket += 2*num;
		}
		int lhs = bracket;
		int rhs = bracket + num;
		dp[indexWin][roundsWon] = (1 << (roundsWon-1)) * win[indexWin][roundsWon] + solve(indexWin, roundsWon-1);
		if(indexWin >= lhs && indexWin < rhs) {
			double t = 0;
			for(int a = rhs; a < rhs+num; a++) {
				t = Math.max(t, solve(a, roundsWon-1));
			}
			dp[indexWin][roundsWon] += t;
		}
		else {
			double t = 0;
			for(int a = lhs; a < lhs+num; a++) {
				t = Math.max(t, solve(a, roundsWon-1));
			}
			dp[indexWin][roundsWon] += t;
		}
		return dp[indexWin][roundsWon];
	}
	
	static double[][] dp;
	static double[][] win;
	static double[][] p;
	
	public static void exitImmediately() {
		pw.close();
		System.exit(0);
	}

	public static int readInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	public static double readDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	public static long readLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	public static String nextLine() throws IOException {
		st = null;
		if(!br.ready()) {
			exitImmediately();
		}
		return br.readLine();
	}

	public static String nextToken() throws IOException {
		while(st == null || !st.hasMoreTokens()) {
			if(!br.ready()) {
				exitImmediately();
			}
			st = new StringTokenizer(br.readLine());
		}
		return st.nextToken();
	}
}