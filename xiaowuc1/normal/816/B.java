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
			int k = readInt();
			int qqq = readInt();
			int[] have = new int[200005];
			while(n-- > 0) {
				int a = readInt();
				int b = readInt();
				have[a]++;
				have[b+1]--;
			}
			for(int i = 1; i < have.length; i++) {
				have[i] += have[i-1];
			}
			int[] ret = new int[200005];
			for(int i = 0; i < have.length; i++) {
				if(have[i] >= k) {
					ret[i]++;
				}
			}
			for(int i = 1; i < ret.length; i++) {
				ret[i] += ret[i-1];
			}
			while(qqq-- > 0) {
				int a = readInt();
				int b = readInt();
				pw.println(ret[b] - ret[a-1]);
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