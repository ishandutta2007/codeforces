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
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			int[] amt = new int[20001];
			while(n-- > 0) {
				amt[readInt()+10000]++;
			}
			long ret = 0;
			for(int a = 10001; a < amt.length; a++) {
				ret += amt[a]*(a-10000L);
			}
			if(ret%2 == 0) {
				int smallNegOdd = 9999;
				while(smallNegOdd > 0 && amt[smallNegOdd] == 0) smallNegOdd -= 2;
				int smallPosOdd = 10001;
				while(smallPosOdd < amt.length && amt[smallPosOdd] == 0) smallPosOdd += 2;
				if(smallNegOdd < 0) {
					ret -= (smallPosOdd-10000);
				}
				else if(smallPosOdd >= amt.length) {
					ret += (smallNegOdd-10000);
				}
				else {
					ret -= Math.min(smallPosOdd - 10000, 10000 - smallNegOdd);
				}
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
		String s = br.readLine();
		if(s == null) {
			exitImmediately();
		}
		st = null;
		return s;
	}

	private static String nextToken() throws IOException  {
		while(st == null || !st.hasMoreTokens())  {
			st = new StringTokenizer(nextLine().trim());
		}
		return st.nextToken();
	}
}