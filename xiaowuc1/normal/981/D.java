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
			int n = readInt();
			int k = readInt();
			long[] l = new long[n];
			for(int i = 0; i < n; i++) {
				l[i] = readLong();
			}
			long ret = 0;
			for(int a = 60; a >= 0; a--) {
				long[] dp = new long[n+1];
				dp[0] = ret | (1L << a);
				for(int qqq = 0; qqq < k; qqq++) {
					long[] next = new long[n+1];
					for(int i = 0; i < n; i++) {
						long curr = 0;
						for(int j = i; j < n; j++) {
							curr += l[j];
							next[j+1] = Math.max(next[j+1], dp[i] & curr);
						}
					}
					dp = next;
				}
				if(dp[n] == (ret | (1L << a))) {
					ret |= (1L << a);
				}
			}
			pw.println(ret);
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