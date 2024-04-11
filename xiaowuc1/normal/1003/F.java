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
		for(int casenum = 1; casenum <= qq; casenum++) {
			int n = readInt();
			String[] l = new String[n];
			int[] pref = new int[n+1];
			for(int i = 0; i < n; i++) {
				l[i] = readToken();
				pref[i+1] = pref[i] + l[i].length();
			}
			boolean[][] g = new boolean[n][n];
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					g[i][j] = l[i].length() == l[j].length() && l[i].equals(l[j]);
				}
			}
			int[][] gMatch = new int[2*n+1][n+1];
			for(int j = 0; j < n; j++) {
				for(int i = 0; i < n; i++) {
					gMatch[i-j+n][j+1] = gMatch[i-j+n][j];
					if(g[i][j]) {
						gMatch[i-j+n][j+1]++;
					}
				}
			}
			int ret = pref[n] + n-1;
			for(int i = 0; i < n; i++) {
				for(int s = 1; i + s <= n; s++) {
					int savings = pref[i+s] - pref[i] - 1;
					int numOccur = 1;
					int next = i+s;
					while(next + s <= n) {
						int row = i - next + n;
						int startCol = next;
						int endCol = startCol + s;
						if(gMatch[row][endCol] - gMatch[row][startCol] == s) {
							numOccur++;
							next += s;
						}
						else {
							next++;
						}
					}
					if(numOccur >= 2) {
						ret = Math.min(ret, pref[n] + n-1 - numOccur*savings);
					}
				}
			}
			pw.println(ret);
		}
		exitImmediately();
	}

	private static void exitImmediately() {
		pw.close();
		System.exit(0);
	}

	private static long readLong() throws IOException {
		return Long.parseLong(readToken());
	}

	private static double readDouble() throws IOException {
		return Double.parseDouble(readToken());
	}

	private static int readInt() throws IOException {
		return Integer.parseInt(readToken());
	}

	private static String readLine() throws IOException  {
		String s = br.readLine();
		if(s == null) {
			exitImmediately();
		}
		st = null;
		return s;
	}

	private static String readToken() throws IOException  {
		while(st == null || !st.hasMoreTokens())  {
			st = new StringTokenizer(readLine().trim());
		}
		return st.nextToken();
	}
}