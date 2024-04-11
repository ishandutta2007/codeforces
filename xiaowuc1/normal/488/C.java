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
			int hp = readInt();
			int att = readInt();
			int def = readInt();
			int hpO = readInt();
			int attO = readInt();
			int defO = readInt();
			int hI = readInt();
			int aI = readInt();
			int dI = readInt();
			int ret = Integer.MAX_VALUE;
			for(int a = att; a <= 200; a++) {
				if(a <= defO) continue;
				for(int d = def; d <= 200; d++) {
					int cost = (a-att)*aI + (d-def)*dI;
					if(d < attO) {
						int myTurn = need(hpO, a - defO);
						int hpBuy = Math.max(0, myTurn * (attO - d) + 1 - hp);
						cost += hpBuy * hI;
					}
					ret = Math.min(ret, cost);
				}
			}
			pw.println(ret);
		}
		exitImmediately();
	}

	public static int need(int h, int a) {
		return (h+a-1)/a;
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