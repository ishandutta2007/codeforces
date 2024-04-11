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
			int p = readInt();
			p--;
			if(p > n-1-p) {
				p = n-p-1;
			}
			
			String s = nextToken();
			
			int rightThenLeft = 0;
			int rightThenLeftI = p;
			for(int i = p+1; i < n-1-i; i++) {
				if(s.charAt(i) != s.charAt(s.length()-1-i)) {
					rightThenLeft += i-rightThenLeftI;
					rightThenLeft += dist(s.charAt(i), s.charAt(s.length()-1-i));
					rightThenLeftI = i;
				}
			}
			for(int i = p; i >= 0; i--) {
				if(s.charAt(i) != s.charAt(s.length()-1-i)) {
					rightThenLeft += rightThenLeftI-i;
					rightThenLeft += dist(s.charAt(i), s.charAt(s.length()-1-i));
					rightThenLeftI = i;
				}
			}
			
			
			int leftThenRight = 0;
			int leftThenRightI = p;
			for(int i = p; i >= 0; i--) {
				if(s.charAt(i) != s.charAt(s.length()-1-i)) {
					leftThenRight += leftThenRightI-i;
					leftThenRight += dist(s.charAt(i), s.charAt(s.length()-1-i));
					leftThenRightI = i;
				}
			}
			for(int i = p+1; i < n-1-i; i++) {
				if(s.charAt(i) != s.charAt(s.length()-1-i)) {
					leftThenRight += i-leftThenRightI;
					leftThenRight += dist(s.charAt(i), s.charAt(s.length()-1-i));
					leftThenRightI = i;
				}
			}
			
			pw.println(Math.min(leftThenRight, rightThenLeft));
			
		}
		exitImmediately();
	}

	public static int dist(char a, char b) {
		int dist = Math.abs(a - b);
		return Math.min(dist, 26 - dist);
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