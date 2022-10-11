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
			int n = readInt();
			int k = readInt();
			if(n == 1) {
				if(k == 0) {
					pw.println(1);
				}
				else {
					pw.println(-1);
				}
				continue;
			}
			if(n/2 > k) {
				pw.println(-1);
				continue;
			}
			int[] ret = new int[n];
			int leftover = k - (n/2) + 1;
			ret[0] = leftover;
			ret[1] = 2 * leftover;
			Set<Integer> set = new HashSet<Integer>();
			set.add(leftover);
			set.add(2*leftover);
			int curr = 1;
			for(int i = 2; i < ret.length; i++) {
				while(set.contains(curr)) {
					curr += 2;
				}
				ret[i] = curr;
				set.add(curr);
			}
			for(int out: ret) {
				pw.print(out + " ");
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