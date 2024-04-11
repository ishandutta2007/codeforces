import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

/*
br = new BufferedReader(new FileReader("input.txt"));
pw = new PrintWriter(new BufferedWriter(new FileWriter("output.txt")));
br = new BufferedReader(new InputStreamReader(System.in));
pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
 */

public class B {
	private static BufferedReader br;
	private static StringTokenizer st;
	private static PrintWriter pw;
	
	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			final int MOD = 1000000007;
			int[][] combo = new int[n+10][n+10];
			for(int i = 0; i < combo.length; i++) {
				combo[i][0] = combo[i][i] = 1;
			}
			for(int i = 1; i < combo.length; i++) {
				for(int j = 1; j < i; j++) {
					combo[i][j] = combo[i-1][j-1] + combo[i-1][j];
					if(combo[i][j] >= MOD) {
						combo[i][j] -= MOD;
					}
				}
			}
			int[] b = new int[n+5];
			b[0] = 1;
			b[1] = 1;
			for(int i = 1; i+1 < b.length; i++) {
				int ret = 0;
				for(int k = 0; k <= i; k++) {
					long temp = combo[i][k];
					temp *= b[k];
					temp %= MOD;
					ret += temp;
					if(ret >= MOD) ret -= MOD;
				}
				b[i+1] = ret;
			}
			pw.println((b[n+1] - b[n] + MOD) % MOD);
		}
		pw.close();
	}

	private static void exitImmediately()	{
		pw.close();
		System.exit(0);
	}

	private static long readLong() throws IOException	{
		return Long.parseLong(nextToken());
	}

	private static double readDouble() throws IOException	{
		return Double.parseDouble(nextToken());
	}

	private static int readInt() throws IOException	{
		return Integer.parseInt(nextToken());
	}

	private static String nextToken() throws IOException	{
		while(st == null || !st.hasMoreTokens())	{
			if(!br.ready())	{
				exitImmediately();
			}
			st = new StringTokenizer(br.readLine().trim());
		}
		return st.nextToken();
	}
}