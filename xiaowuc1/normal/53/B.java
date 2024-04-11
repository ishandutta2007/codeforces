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
			long a = readLong();
			long b = readLong();
			long aRet = 1;
			long bRet = 1;
			for(long x = 1; x <= a; x *= 2) {
				long yMin = (4*x+4)/5;
				long yMax = 5*x/4;
				long yCand = -1;
				if(b < yMin) {
					continue;
				}
				else if(b >= yMin && b <= yMax) {
					yCand = b;
				}
				else if(b > yMax) {
					yCand = yMax;
				}
				else {
					throw new RuntimeException();
				}
				if(x * yCand > aRet * bRet || (x*yCand == aRet * bRet && x > aRet)) {
					aRet = x;
					bRet = yCand;
				}
			}
			for(long y = 1; y <= b; y *= 2) {
				long xMin = (4*y+4)/5;
				long xMax = 5*y/4;
				long xCand = -1;
				if(a < xMin) {
					continue;
				}
				else if(a >= xMin && a <= xMax) {
					xCand = a;
				}
				else if(a > xMax) {
					xCand = xMax;
				}
				else {
					throw new RuntimeException();
				}
				if(xCand * y > aRet * bRet || (xCand*y == aRet * bRet && xCand > aRet)) {
					aRet = xCand;
					bRet = y;
				}
			}
			pw.println(aRet + " " + bRet);
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