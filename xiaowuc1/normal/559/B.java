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

	static int[][][] dp;
	static String a, b;
	
	public static void main(String[] args) throws Exception {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			a = nextToken();
			b = nextToken();
			dp = new int[2][26][a.length()+1];
			for(int i = 0; i < a.length(); i++) {
				for(int j = 0; j < 26; j++) {
					dp[0][j][i+1] = dp[0][j][i];
					dp[1][j][i+1] = dp[1][j][i];
				}
				dp[0][a.charAt(i)-'a'][i+1]++;
				dp[1][b.charAt(i)-'a'][i+1]++;
			}
			pw.println(equiv(0, 0, a.length()) ? "YES" : "NO");
		}	
		exitImmediately();
	}

	public static boolean equiv(int aIndex, int bIndex, int len) {
		if(len % 2 == 1) {
			for(int i = 0; i < len; i++) {
				if(a.charAt(aIndex+i) != b.charAt(bIndex+i)) {
					return false;
				}
			}
			return true;
		}
		for(int i = 0; i < 26; i++) {
			if(dp[0][i][aIndex+len] - dp[0][i][aIndex] != dp[1][i][bIndex+len] - dp[1][i][bIndex]) {
				return false;
			}
		}
		return (equiv(aIndex, bIndex, len/2) && equiv(aIndex + len/2, bIndex + len/2, len/2)) || (equiv(aIndex, bIndex + len/2, len/2) && equiv(aIndex + len/2, bIndex, len/2)); 
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