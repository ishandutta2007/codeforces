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
		int qq = 1;
		//int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++) {
			int n = readInt();
			int m = readInt();
			int mod = readInt();
			int[] count = new int[n];
			Arrays.fill(count, 2);
			for(int i = 0; i < m; i++) {
				String s = nextToken();
				for(int j = 0; j < n; j++) {
					if(s.charAt(j) == '1') {
						count[j]--;
					}
				}
			}
			int ones = 0;
			int twos = 0;
			for(int out: count) {
				if(out == 1) ones++;
				if(out == 2) twos++;
			}
			long[][] dp = new long[n+1][n+1];
			dp[ones][twos] = 1;
			int numsExpect = 2 * n - 2 * m;
			while(m++ < n) {
				for(int j = 0; j <= n; j++) {
					int i = numsExpect - 2 * j;
					if(i < 0 || i > n) continue;
					if(dp[i][j] == 0) continue;
					if(i >= 2) {
						dp[i-2][j] += dp[i][j] * i * (i-1) / 2;
						dp[i-2][j] %= mod;
					}
					if(i >= 1 && j >= 1) {
						dp[i][j-1] += dp[i][j] * i * j;
						dp[i][j-1] %= mod;
					}
					if(j >= 2) {
						dp[i+2][j-2] += dp[i][j] * j * (j-1) / 2;
						dp[i+2][j-2] %= mod;
					}
				}
				numsExpect -= 2;
			}
			pw.println(dp[0][0]);
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