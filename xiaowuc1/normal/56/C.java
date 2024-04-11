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
			LinkedList<String> list = new LinkedList<String>();
			int ret = 0;
			String s = nextToken();
			StringBuilder sb = new StringBuilder();
			for(int i = 0; i < s.length(); i++) {
				if(s.charAt(i) == '.') {
					String name = sb.toString();
					sb = new StringBuilder();
					for(String out: list) {
						if(out.equals(name)) {
							ret++;
						}
					}
					if(name.length() == 0) {
						list.removeLast();
					}
					continue;
				}
				if(s.charAt(i) == ':') {
					String name = sb.toString();
					sb = new StringBuilder();
					for(String out: list) {
						if(out.equals(name)) {
							ret++;
						}
					}
					list.addLast(name);
					continue;
				}
				if(s.charAt(i) == ',') continue;
				sb.append(s.charAt(i));
			}
			pw.println(ret);
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