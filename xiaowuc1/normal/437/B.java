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
			int s = readInt();
			int n = readInt();
			ArrayList<Integer> list = new ArrayList<Integer>();
			for(int i = 1; i <= n; i++) {
				list.add(i);
			}
			Collections.sort(list, new Comp());
			ArrayList<Integer> ret = new ArrayList<Integer>();
			for(int out: list) {
				if(score(out) <= s) {
					s -= score(out);
					ret.add(out);
				}
			}
			if(s != 0) {
				pw.println(-1);
			}
			else {
				pw.println(ret.size());
				for(int out: ret) {
					pw.print(out + " ");
				}
				pw.println();
			}
		}
		exitImmediately();
	}

	static class Comp implements Comparator<Integer> {
		public int compare(Integer a, Integer b) {
			return score(b) - score(a);
		}
	}
	
	public static int score(int n) {
		return n - (n & (n - 1));
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