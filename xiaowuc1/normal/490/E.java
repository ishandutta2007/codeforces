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

	static int[] pow;
	
	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		pow = new int[9];
		pow[0] = 1;
		for(int i = 1; i < pow.length; i++) {
			pow[i] = pow[i-1] * 10;
		}
		for(int casenum = 1; casenum <= qq; casenum++) {
			int n = readInt();
			String[] list = new String[n];
			for(int i = 0; i < n; i++) {
				list[i] = nextToken();
			}
			int last = 0;
			int[] ret = new int[n];
			boolean bad = false;
			for(int i = 0; !bad && i < n; i++) {
				ret[i] = getMin(list[i], 0, last);
				if(ret[i] == -1) {
					bad = true;
					break;
				}
				last = ret[i];
			}
			if(bad) {
				pw.println("NO");
			}
			else {
				pw.println("YES");
				for(int out: ret) {
					pw.println(out);
				}
			}
		}
		exitImmediately();
	}
	
	public static int getMin(String s, int currNum, int above) {
		if(s.length() == 0) {
			return currNum > above ? currNum : -1;
		}
		if(currNum + pow[s.length()] - 1 <= above) return -1;
		if(s.charAt(0) != '?') {
			return getMin(s.substring(1), currNum + (s.charAt(0) - '0') * pow[s.length()-1], above);
		}
		for(int i = currNum == 0 ? 1 : 0; i <= 9; i++) {
			int ret = getMin(s.substring(1), currNum + (i * pow[s.length()-1]), above);
			if(ret != -1) {
				return ret;
			}
		}
		return -1;
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