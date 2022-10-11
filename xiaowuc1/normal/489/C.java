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
			int len = readInt();
			int sum = readInt();
			if(sum == 0) {
				if(len == 1) {
					pw.println("0 0");
				}
				else {
					pw.println("-1 -1");
				}
				continue;
			}
			else if(9 * len < sum) {
				pw.println("-1 -1");
				continue;
			}
			pw.println(genSmall(len, sum) + " " + genBig(len, sum));
		}
		exitImmediately();
	}

	public static String genSmall(int len, int sum) {
		String ret = "";
		int next = Math.max(1, sum - 9 * (len-1)); 
		ret += next;
		sum -= next;
		len--;
		while(len > 0) {
			next = Math.max(0, sum - 9 * (len-1)); 
			ret += next;
			sum -= next;
			len--;
		}
		return ret;
	}
	
	public static String genBig(int len, int sum) {
		String ret = "";
		while(ret.length() < len) {
			int next = Math.min(9, sum);
			sum -= next;
			ret += next;
		}
		return ret;
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