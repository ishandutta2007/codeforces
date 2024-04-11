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
			int depth = 0;
			ArrayList<Integer> ret = new ArrayList<Integer>();
			boolean bad = false;
			for(int i = 0; i < s.length(); i++) {
				if(s.charAt(i) == '(') {
					depth++;
				}
				else {
					if(depth == 0) {
						bad = true;
						break;
					}
					if(s.charAt(i) == '#') {
						ret.add(1);
					}
					depth--;
				}
			}
			if(bad) {
				pw.println(-1);
				continue;
			}
			ret.set(ret.size()-1, ret.get(ret.size()-1) + depth);
			depth = 0;
			int index = 0;
			for(int i = 0; i < s.length(); i++) {
				if(s.charAt(i) == '(') {
					depth++;
				}
				else {
					if(depth == 0) {
						bad = true;
						break;
					}
					if(s.charAt(i) == '#') {
						depth -= ret.get(index++);
					}
					else {
						depth--;
					}
					if(depth < 0) {
						bad = true;
						break;
					}
				}
			}
			bad |= depth != 0;
			if(bad) {
				pw.println(-1);
				continue;
			}
			for(int out: ret) {
				pw.println(out);
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