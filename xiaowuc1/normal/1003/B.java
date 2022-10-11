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
			int a = readInt();
			int b = readInt();
			int x = readInt();
			if(a >= b) {
				int[] amt = new int[x+1];
				for(int i = 0; i < amt.length; i++) {
					amt[i] = 1;
					if(i%2 == 0) {
						a--;
					}
					else {
						b--;
					}
				}
				while(a-- > 0) {
					amt[0]++;
				}
				while(b-- > 0) {
					amt[1]++;
				}
				StringBuilder sb = new StringBuilder();
				for(int i = 0; i < amt.length; i++) {
					while(amt[i]-- > 0) {
						sb.append(i%2);
					}
				}
				pw.println(sb);
			}
			else {
				int[] amt = new int[x+1];
				for(int i = 0; i < amt.length; i++) {
					amt[i] = 1;
					if(i%2 == 0) {
						b--;
					}
					else {
						a--;
					}
				}
				while(b-- > 0) {
					amt[0]++;
				}
				while(a-- > 0) {
					amt[1]++;
				}
				StringBuilder sb = new StringBuilder();
				for(int i = 0; i < amt.length; i++) {
					while(amt[i]-- > 0) {
						sb.append((i+1)%2);
					}
				}
				pw.println(sb);
			}
		}
		exitImmediately();
	}

	private static void exitImmediately() {
		pw.close();
		System.exit(0);
	}

	private static long readLong() throws IOException {
		return Long.parseLong(readToken());
	}

	private static double readDouble() throws IOException {
		return Double.parseDouble(readToken());
	}

	private static int readInt() throws IOException {
		return Integer.parseInt(readToken());
	}

	private static String readLine() throws IOException  {
		String s = br.readLine();
		if(s == null) {
			exitImmediately();
		}
		st = null;
		return s;
	}

	private static String readToken() throws IOException  {
		while(st == null || !st.hasMoreTokens())  {
			st = new StringTokenizer(readLine().trim());
		}
		return st.nextToken();
	}
}