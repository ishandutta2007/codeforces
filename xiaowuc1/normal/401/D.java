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
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++) {
			String str = nextToken();
			int m = readInt();
			long[][] dp = new long[1<<str.length()][m];
			ArrayList<Integer>[] order = new ArrayList[10];
			for(int i = 0; i < order.length; i++) {
				order[i] = new ArrayList<Integer>();
			}
			for(int i = 0; i < str.length(); i++) {
				order[str.charAt(i) - '0'].add(i);
			}
			for(int a = 1; a <= 9; a++) {
				if(order[a].isEmpty()) continue;
				int first = order[a].get(0);
				dp[1 << first][a%m]++;
			}
			for(int mask = 1; mask < dp.length; mask++) {
				for(int a = 0; a < m; a++) {
					if(dp[mask][a] == 0) continue;
					for(int b = 0; b < 10; b++) {
						for(int out: order[b]) {
							if((mask&(1<<out)) != 0) continue;
							dp[mask | (1 << out)][(10*a + b) % m] += dp[mask][a];
							break;
						}
					}
				}
			}
			pw.println(dp[dp.length-1][0]);
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