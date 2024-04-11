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

	static String s;
	static int[] match;

	static long[][][] dp;

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++) {
			s = nextToken();
			match = new int[s.length()];
			Arrays.fill(match, -1);
			Stack<Integer> temp = new Stack<Integer>();
			for(int i = 0; i < s.length(); i++) {
				if(s.charAt(i) == '(') {
					temp.push(i);
				}
				else {
					match[temp.pop()] = i;
				}
			}
			dp = new long[s.length()][s.length()][4];
			for(int i = 0; i < dp.length; i++) {
				for(int j = 0; j < dp[i].length; j++) {
					Arrays.fill(dp[i][j], -1);
				}
			}
			pw.println(solve(0, s.length()-1, 0));
		}
		exitImmediately();
	}

	static final int MOD = 1000000007;

	public static long solve(int left, int right, int mask) {
		// mask 0 means neither
		// mask 1 means left
		// mask 2 means right
		// mask 3 means both
		if(left >= right) return 1;
		if(dp[left][right][mask] >= 0) return dp[left][right][mask];
		long ret = 0;
		if(match[left] == right) {
			// color left
			if((mask&1) > 0) {
				ret += solve(left+1, right-1, 1);
			}
			else {
				ret += 2 * solve(left+1, right-1, 1);
			}
			// color right
			if((mask&2) > 0) {
				ret += solve(left+1, right-1, 2);
			}
			else {
				ret += 2 * solve(left+1, right-1, 2);
			}
		}
		else {
			int newLeft = left+1;
			int newRight = match[left]-1;
			int otherLeft = newRight+2;
			int otherRight = right;
			// color newLeft
			if((mask&1) > 0) {
				ret += solve(newLeft, newRight, 1) * solve(otherLeft, otherRight, mask & 2);
			}
			else {
				ret += 2 * solve(newLeft, newRight, 1) * solve(otherLeft, otherRight, mask & 2);
			}
			// color newRight
			ret += 2 * solve(newLeft, newRight, 2) * solve(otherLeft, otherRight, (mask & 2) | 1);
		}
		return dp[left][right][mask] = ret % MOD;
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