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

	static long[] list;
	static long[] prefix;
	
	public static void main(String[] args) throws Exception {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			list = new long[n];
			prefix = new long[n+1];
			for(int i = 0; i < n; i++) {
				list[i] = -readLong();
			}
			for(int a = 0; a < 100; a++) {
				int x = (int)(Math.random() * n);
				int y = (int)(Math.random() * n);
				long t = list[x];
				list[x] = list[y];
				list[y] = t;
			}
			Arrays.sort(list);
			for(int i = 0; i < n; i++) {
				list[i] = -list[i];
				prefix[i+1] = prefix[i] + list[i];
			}
			int qqq = readInt();
			long[] dp = new long[n+1];
			StringBuilder sb = new StringBuilder();
			while(qqq-- > 0) {
				int curr = Math.min(n, readInt());
				if(dp[curr] == 0) {
					int lastStart = 1;
					long intervalSize = curr;
					int depth = 1;
					while(lastStart < n) {
						int end = (int)Math.min(n, lastStart + intervalSize);
						dp[curr] += depth * (prefix[end] - prefix[lastStart]);
						lastStart = end;
						intervalSize *= curr;
						depth++;
					}
				}
				sb.append(dp[curr] + " ");
			}
			pw.println(sb.toString().trim());
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