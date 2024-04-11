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
			long a = readLong();
			long b = readLong();
			long c = readLong();
			long d = readLong();
			int leftPow = threes(a) + threes(b);
			int rightPow = threes(c) + threes(d);
			int ret = Math.abs(leftPow - rightPow);
			while(leftPow > rightPow) {
				if(a%3 == 0) {
					a /= 3;
					a *= 2;
					leftPow--;
				}
				else {
					b /= 3;
					b *= 2;
					leftPow--;
				}
			}
			while(rightPow - leftPow > 0) {
				if(c%3==0) {
					c /= 3;
					c *= 2;
					rightPow--;
				}
				else {
					d /= 3;
					d *= 2;
					rightPow--;
				}
			}
			leftPow = twos(a) + twos(b);
			rightPow = twos(c) + twos(d);
			ret += Math.abs(leftPow - rightPow);
			while(leftPow > rightPow) {
				if(a%2 == 0) {
					a /= 2;
					leftPow--;
				}
				else {
					b /= 2;
					leftPow--;
				}
			}
			while(rightPow - leftPow > 0) {
				if(c%2==0) {
					c /= 2;
					rightPow--;
				}
				else {
					d /= 2;
					rightPow--;
				}
			}
			if(a*b != c*d) {
				pw.println(-1);
			}
			else {
				pw.println(ret);
				pw.println(a + " " + b);
				pw.println(c + " " + d);
			}
		}
		exitImmediately();
	}

	public static int twos(long n) {
		int r = 0;
		while(n % 2 == 0) {
			r++;
			n /= 2;
		}
		return r;
	}
	
	public static int threes(long n) {
		int r = 0;
		while(n % 3 == 0) {
			r++;
			n /= 3;
		}
		return r;
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