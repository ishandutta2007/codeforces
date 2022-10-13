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

	static int n, p;
	
	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++) {
			n = readInt();
			p = readInt();
			String str = nextToken();
			boolean done = false;
			for(int length = str.length()-1; !done && length >= 0; length--) {
				String start = str.substring(0, length);
				int offend = str.charAt(length) - 'a';
				for(int i = offend+1; !done && i < p; i++) {
					char ch = (char)('a'+i);
					String guess = start + ch;
					if(!valid(guess)) continue;
					if(dfs(guess)) {
						done = true;
					}
				}
			}
			if(!done) {
				pw.println("NO");
			}
		}
		exitImmediately();
	}

	public static boolean dfs(String s) {
		if(s.length() == n) {
			pw.println(s);
			return true;
		}
		for(int i = 0; i < p; i++) {
			String next = s + (char)('a' + i);
			if(!valid(next)) continue;
			if(dfs(next)) {
				return true;
			}
		}
		return false;
	}
	
	public static boolean valid(String s) {
		if(s.length() >= 2 && s.charAt(s.length()-2) == s.charAt(s.length()-1)) return false;
		if(s.length() >= 3 && s.charAt(s.length()-3) == s.charAt(s.length()-1)) return false;
		return true;
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