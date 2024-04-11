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
			String s = nextToken();
			boolean[] lhs = new boolean[s.length()+1];
			boolean[] rhs = new boolean[s.length()+1];
			int a = readInt();
			int b = readInt();
			int curr = 0;
			for(int i = 0; i < s.length(); i++) {
				curr *= 10;
				curr += s.charAt(i) - '0';
				curr %= a;
				if(curr == 0) {
					lhs[i+1] = true;
				}
			}
			curr = 0;
			int pow = 1;
			for(int i = 0; i < s.length(); i++) {
				curr += pow * (s.charAt(s.length()-1-i) - '0');
				curr %= b;
				pow *= 10;
				pow %= b;
				if(curr == 0) {
					rhs[i+1] = true;
				}
			}
			boolean done = false;
			for(int i = 1; !done && i < s.length(); i++) {
				if(lhs[i] && rhs[s.length()-i] && s.charAt(i) != '0') {
					done = true;
					pw.println("YES");
					pw.println(s.substring(0, i));
					pw.println(s.substring(i));
				}
			}
			if(!done) {
				pw.println("NO");
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