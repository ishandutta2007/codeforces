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
			int a = readInt();
			int b = readInt();
			int c = readInt();
			int d = readInt();
			if(Math.abs(c-d) > 1) {
				pw.println(-1);
				continue;
			}
			ArrayList<Integer> list = new ArrayList<Integer>();
			String ret;
			if(c > d) {
				ret = obtain(a, b, c, d, 4);
			}
			else if(d > c) {
				ret = obtain(a, b, c, d, 7);
			}
			else {
				ret = obtain(a, b, c, d, 4);
				if(ret.equals("-1")) {
					ret = obtain(a, b, c, d, 7);
				}
			}
			pw.println(ret);
		}
		exitImmediately();
	}
	
	public static String obtain(int a, int b, int c, int d, int e) {
		ArrayList<Integer> list = new ArrayList<Integer>();
		list.add(e);
		while(c > 0 || d > 0) {
			if(list.get(list.size()-1) == 4) {
				if(c == 0) throw new RuntimeException();
				list.add(7);
				c--;
			}
			else {
				if(d == 0) throw new RuntimeException();
				list.add(4);
				d--;
			}
		}
		int numFour = list.get(0) == 4 ? (list.size()+1)/2 : (list.size()/2);
		int numSeven = list.size() - numFour;
		if(numFour > a || numSeven > b) {
			return "-1";
		}
		a -= numFour;
		b -= numSeven;
		int[] ret = new int[list.size()];
		Arrays.fill(ret, 1);
		for(int i = 0; i < list.size(); i++) {
			if(list.get(i) == 4) {
				ret[i] += a;
				break;
			}
		}
		for(int i = list.size()-1; i >= 0; i--) {
			if(list.get(i) == 7) {
				ret[i] += b;
				break;
			}
		}
		StringBuilder sb = new StringBuilder();
		for(int i = 0; i < ret.length; i++) {
			while(ret[i]-- > 0) {
				sb.append(list.get(i));
			}
		}
		return sb.toString();
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