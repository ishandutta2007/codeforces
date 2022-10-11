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
			long a = readInt();
			long b = readInt();
			long max = lcm(a, b);
			long curr = 0;
			long l = 0;
			long r = 0;
			long aa = a;
			long bb = b;
			while(curr < max) {
				if(aa == bb) {
					if(a > b) {
						l += aa - curr;
					}
					else {
						r += aa - curr;
					}
					curr = aa;
					aa += a;
					bb += b;
				}
				else if(aa < bb) {
					l += aa - curr;
					curr = aa;
					aa += a;
				}
				else {
					r += bb - curr;
					curr = bb;
					bb += b;
				}
			}
			if(l == r) {
				pw.println("Equal");
			}
			if(l > r) {
				pw.println("Dasha");
			}
			if(l < r) {
				pw.println("Masha");
			}
		}
		exitImmediately();
	}

	public static long lcm(long a, long b) {
		return a / gcd(a,b) * b;
	}
	
	public static long gcd(long a, long b) {
		return a%b==0 ? b : gcd(b, a%b);
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