import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

public class C {
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
			int n = readInt();
			int need = readInt();
			double[][] dp = new double[n+1][need+1];
			int[] f = new int[n];
			int[] s = new int[n];
			int[] p = new int[n];
			for(int i = 0; i < n; i++) {
				f[i] = readInt();
				s[i] = readInt();
				p[i] = readInt();
				Arrays.fill(dp[i], 3.9e7);
			}
			double min = 0;
			double max = 1e10;
			for(int qqq = 0; qqq < 200; qqq++) {
				double mid = (min+max)/2;
				for(int i = 0; i < n; i++) {
					Arrays.fill(dp[i], mid);
				}
				for(int i = n-1; i >= 0; i--) {
					for(int j = 0; j <= need; j++) {
						if(j + f[i] > need) {
							dp[i][j] = dp[0][0];
							continue;
						}
						double fast = (p[i] / 100.) * (f[i] + dp[i+1][j + f[i]]);
						double slow = (100. - p[i]) / 100 * (j + s[i] > need ? s[i] + dp[0][0] : s[i] + dp[i+1][j + s[i]]);
						dp[i][j] = Math.min(dp[0][0], fast + slow);
					}
				}
				if(dp[0][0] < mid) {
					max = mid;
				}
				else {
					min = mid;
				}
			}
			pw.println(min);
		}
		pw.close();
	}

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