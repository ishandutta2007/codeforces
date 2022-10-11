import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.security.*;
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
	
	public static void main(String[] args) throws Exception {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			Set<String> set = new HashSet<String>();
			for(int i = 0; i < n; i++) {
				set.add(nextToken().toLowerCase());
			}
			String orig = nextToken();
			char ch = nextToken().charAt(0);
			boolean[] rep = new boolean[orig.length()];
			for(int i = 0; i < orig.length(); i++) {
				for(int j = i+1; j <= orig.length(); j++) {
					if(set.contains(orig.substring(i, j).toLowerCase())) {
						for(int k = i; k < j; k++) {
							rep[k] = true;
						}
					}
				}
			}
			for(int i = 0; i < orig.length(); i++) {
				boolean upper = Character.isUpperCase(orig.charAt(i));
				char curr = Character.toLowerCase(orig.charAt(i));
				if(!rep[i]) {
					pw.print(force(curr, upper));
				}
				else {
					if(curr != ch) {
						pw.print(force(ch, upper));
					}
					else if(curr == 'a') {
						pw.print(force('b', upper));
					}
					else {
						pw.print(force('a', upper));
					}
				}
			}
			pw.println();
		}
		exitImmediately();
	}
	
	public static char force(char ch, boolean upper) {
		if(upper) {
			return Character.toUpperCase(ch);
		}
		else {
			return Character.toLowerCase(ch);
		}
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