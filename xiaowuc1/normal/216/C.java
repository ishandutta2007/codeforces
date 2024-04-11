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

	public static void main(String[] args) throws Exception {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			int m = readInt();
			int k = readInt();
			int[] ret = new int[n+m+1];
			ArrayList<Integer> ans = new ArrayList<Integer>();
			ans.add(0);
			for(int i = 0; i < n; i++) {
				ret[i]++;
			}
			int lastVal = n-1;
			int start = 0;
			while(start < n+m) {
				if(start == lastVal) {
					ans.add(start);
					for(int a = 0; a < n && start + a < ret.length; a++) {
						ret[start+a]++;
					}
					lastVal = start + n - 1;
					continue;
				}
				if(ret[start] >= k) {
					start++;
					continue;
				}
				ans.add(start);
				for(int a = 0; a < n && start + a < ret.length; a++) {
					ret[start+a]++;
				}
				lastVal = start + n - 1;
			}
			pw.println(ans.size());
			for(int out: ans) {
				pw.print(++out + " ");
			}
			pw.println();
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