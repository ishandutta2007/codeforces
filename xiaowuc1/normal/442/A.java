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

public class A {
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
			boolean[][] grid = new boolean[5][5];
			while(n-- > 0) {
				String s = nextToken();
				int r = -1;
				switch(s.charAt(0)) {
				case 'G':
					r = 0;
					break;
				case 'R':
					r = 1;
					break;
				case 'B':
					r = 2;
					break;
				case 'W':
					r = 3;
					break;
				case 'Y':
					r = 4;
					break;
				}
				int c = s.charAt(1) - '1';
				grid[r][c] = true;
			}
			int ret = 10;
			for(int rowMask = 0; rowMask < 32; rowMask++) {
				for(int colMask = 0; colMask < 32; colMask++) {
					if(Integer.bitCount(rowMask) + Integer.bitCount(colMask) >= ret) continue;
					boolean[][] current = new boolean[5][5];
					for(int i = 0; i < 5; i++) {
						for(int j = 0; j < 5; j++) {
							current[i][j] = grid[i][j];
						}
					}
					for(int i = 0; i < 5; i++) {
						for(int j = 0; j < 5; j++) {
							if((rowMask&(1<<i)) != 0 && (colMask&(1<<j)) != 0) {
								current[i][j] = false;
							}
						}
					}
					while(true) {
						boolean falsed = false;
						for(int i = 0; i < 5; i++) {
							if((rowMask&(1<<i)) == 0) continue;
							int seen = 0;
							for(int j = 0; j < 5; j++) {
								if(current[i][j]) {
									seen++;
								}
							}
							if(seen == 1) {
								falsed = true;
								for(int j = 0; j < 5; j++) {
									current[i][j] = false;
								}
							}
						}
						for(int j = 0; j < 5; j++) {
							if((colMask&(1<<j)) == 0) continue;
							int seen = 0;
							for(int i = 0; i < 5; i++) {
								if(current[i][j]) {
									seen++;
								}
							}
							if(seen == 1) {
								falsed = true;
								for(int i = 0; i < 5; i++) {
									current[i][j] = false;
								}
							}
						}
						if(!falsed) {
							break;
						}
					}
					int seen = 0;
					for(boolean[] out: current) {
						for(boolean out2: out) {
							if(out2) {
								seen++;
							}
						}
					}
					if(seen <= 1) {
						ret = Integer.bitCount(rowMask) + Integer.bitCount(colMask);
					}
				}
			}
			pw.println(ret);
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