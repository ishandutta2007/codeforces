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
		outer: for(int casenum = 1; casenum <= qq; casenum++) {
			String s = nextToken();
			int last = s.charAt(s.length()-1)-'0';
			for(int i = 0; i < s.length(); i++) {
				int num = s.charAt(i) - '0';
				if(num%2==1) continue;
				if(last > num) {
					pw.println(s.substring(0, i) + last + s.substring(i+1, s.length()-1) + num);
					continue outer;
				}
			}
			for(int i = s.length()-1; i >= 0; i--) {
				int num = s.charAt(i) - '0';
				if(num%2==1) continue;
				pw.println(s.substring(0, i) + last + s.substring(i+1, s.length()-1) + num);
				continue outer;
			}
			pw.println(-1);
		}
		exitImmediately();
	}

	public static BigInteger fact(int n) {
		if(n == 0) return BigInteger.ONE;
		return BigInteger.valueOf(n).multiply(fact(n-1));
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