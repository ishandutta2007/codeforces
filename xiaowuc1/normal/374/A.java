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

	static int n, m, x, y, a, b;

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++) {
			n = readInt();
			m = readInt();
			x = readInt();
			y = readInt();
			a = readInt();
			b = readInt();
			int ret = Integer.MAX_VALUE;
			ret = Math.min(ret, dist(1, 1));
			ret = Math.min(ret, dist(n, 1));
			ret = Math.min(ret, dist(1, m));
			ret = Math.min(ret, dist(n, m));
			if(ret == Integer.MAX_VALUE) {
				pw.println("Poor Inna and pony!");	
			}
			else {
				pw.println(ret);
			}
		}
		exitImmediately();
	}

	public static int dist(int goalX, int goalY) {
		int diffX = Math.abs(goalX - x);
		if(diffX % a != 0) return Integer.MAX_VALUE;
		int diffY = Math.abs(goalY - y);
		if(diffY % b != 0) return Integer.MAX_VALUE;
		int xMov = diffX / a;
		int yMov = diffY / b;
		if(xMov == 0 && yMov == 0) {
			return 0;
		}
		if(xMov % 2 != yMov % 2) return Integer.MAX_VALUE;
		boolean canXMov = x+a <= n || x-a >= 1;
		boolean canYMov = y+b <= m || y-b >= 1;
		if(!canXMov || !canYMov) return Integer.MAX_VALUE;
		return Math.max(xMov, yMov);
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