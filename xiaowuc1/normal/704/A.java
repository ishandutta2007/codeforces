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
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			int qqq = readInt();
			ArrayList<Integer>[] dp = new ArrayList[n];
			for(int i = 0; i < n; i++) {
				dp[i] = new ArrayList<Integer>();
			}
			int num = 0;
			int orig = qqq;
			int ret = 0;
			boolean[] seen = new boolean[qqq+1];
			int last = 0;
			while(qqq-- > 0) {
				int type = readInt();
				if(type == 1) {
					int id = readInt()-1;
					dp[id].add(++num);
					ret++;
				}
				else if(type == 2) {
					int id = readInt()-1;
					for(int out: dp[id]) {
						if(!seen[out]) {
							seen[out] = true;
							ret--;
						}
					}
					dp[id].clear();
				}
				else {
					int thresh = readInt();
					while(last+1 <= num && last+1 <= thresh) {
						last++;
						if(!seen[last]) {
							seen[last] = true;
							ret--;
						}
					}
				}
				pw.println(ret);
			}
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
		String s = br.readLine();
		if(s == null) {
			exitImmediately();
		}
		st = null;
		return s;
	}

	private static String nextToken() throws IOException  {
		while(st == null || !st.hasMoreTokens())  {
			st = new StringTokenizer(nextLine().trim());
		}
		return st.nextToken();
	}
}