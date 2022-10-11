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
			String ret = null;
			ArrayList<String> list = new ArrayList<String>();
			list.add(nextToken());
			list.add(nextToken());
			list.add(nextToken());
			list.add(nextToken());
			list.add(nextToken());
			list.add(nextToken());
			for(int qqq = 0; qqq < 10000; qqq++) {
				Collections.shuffle(list);
				String ans = solve(list.get(0), list.get(1), list.get(2), list.get(3), list.get(4), list.get(5));
				if(ans != null && (ret == null || ans.compareTo(ret) < 0)) {
					ret = ans;
				}
			}
			if(ret == null) {
				ret = "Impossible\n";
			}
			pw.print(ret);
		}
		exitImmediately();
	}

	public static String solve(String r1, String r2, String r3, String c1, String c2, String c3) {
		if(r1.length() + r3.length() != r2.length()+1) return null;
		if(c1.length() + c3.length() != c2.length()+1) return null;
		if(r1.charAt(0) != c1.charAt(0)) return null;
		if(r1.charAt(r1.length()-1) != c2.charAt(0)) return null;
		if(r2.charAt(0) != c1.charAt(c1.length()-1)) return null;
		if(r2.charAt(r1.length()-1) != c2.charAt(c1.length()-1)) return null;
		if(r2.charAt(r2.length()-1) != c3.charAt(0)) return null;
		if(r3.charAt(0) != c2.charAt(c2.length()-1)) return null;
		if(r3.charAt(r3.length()-1) != c3.charAt(c3.length()-1)) return null;
		StringBuilder sb = new StringBuilder();
		for(int i = 0; i < c2.length(); i++) {
			for(int j = 0; j < r2.length(); j++) {
				if(i == 0) {
					if(j < r1.length()) {
						sb.append(r1.charAt(j));
					}
					else {
						sb.append('.');
					}
				}
				else if(i == c1.length()-1) {
					sb.append(r2.charAt(j));
				}
				else if(i == c2.length()-1) {
					if(j >= r1.length() - 1) {
						sb.append(r3.charAt(j - (r1.length() - 1)));
					}
					else {
						sb.append(".");
					}
				}
				else if(j == 0) {
					if(i < c1.length()) {
						sb.append(c1.charAt(i));
					}
					else {
						sb.append(".");
					}
				}
				else if(j == r1.length()-1) {
					sb.append(c2.charAt(i));
				}
				else if(j == r2.length()-1) {
					if(i >= c1.length()-1) {
						sb.append(c3.charAt(i - (c1.length()-1)));
					}
					else {
						sb.append(".");
					}
				}
				else {
					sb.append(".");
				}
			}
			sb.append("\n");
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