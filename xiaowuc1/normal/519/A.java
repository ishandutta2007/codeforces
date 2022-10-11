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
			int score = 0;
			for(int i = 0; i < 8; i++) {
				String s = nextToken();
				for(int j = 0; j < 8; j++) {
					if(s.charAt(j) == '.') continue;
					if(s.charAt(j) == 'Q') score += 9;
					if(s.charAt(j) == 'q') score -= 9;
					if(s.charAt(j) == 'R') score += 5;
					if(s.charAt(j) == 'r') score -= 5;
					if(s.charAt(j) == 'B') score += 3;
					if(s.charAt(j) == 'b') score -= 3;
					if(s.charAt(j) == 'N') score += 3;
					if(s.charAt(j) == 'n') score -= 3;
					if(s.charAt(j) == 'P') score += 1;
					if(s.charAt(j) == 'p') score -= 1;
				}
			}
			if(score == 0) {
				pw.println("Draw");
			}
			if(score > 0) {
				pw.println("White");
			}
			if(score < 0) {
				pw.println("Black");
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