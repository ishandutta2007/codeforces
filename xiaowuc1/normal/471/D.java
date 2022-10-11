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
			int m = readInt();
			if(m == 1) {
				pw.println(n);
				break;
			}
			int[] a = generate(get(n));
			int[] b = generate(get(m));
			final long HASH = 1000000007;
			long expect = 0;
			long pow = 1;
			for(int i = 1; i < b.length; i++) {
				pow *= HASH;
			}
			for(int out: b) {
				expect *= HASH;
				expect += out;
			}
			int ret = 0;
			long curr = 0;
			for(int i = 0; i < a.length; i++) {
				if(i >= b.length) {
					curr -= pow * a[i-b.length];
				}
				curr *= HASH;
				curr += a[i];
				if(i+1 >= b.length && curr == expect) {
					boolean good = true;
					for(int qqq = 0; qqq < 5; qqq++) {
						int dec = (int)(Math.random() * b.length);
						if(b[b.length-1-dec] != a[i - dec]) {
							good = false;
						}
					}
					if(good) {
						ret++;
					}
				}
			}
			pw.println(ret);
		}
		exitImmediately();
	}

	public static int[] get(int n) throws IOException {
		int[] ret = new int[n];
		for(int i = 0; i < n; i++) {
			ret[i] = readInt();
		}
		return ret;
	}

	public static int[] generate(int[] list) {
		int[] ret = new int[list.length-1];
		for(int i = 0; i < ret.length; i++) {
			ret[i] = list[i+1] - list[i];
		}
		return ret;
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