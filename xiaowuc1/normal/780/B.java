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
			int[] x = new int[n];
			int[] v = new int[n];
			for(int i = 0; i < n; i++) {
				x[i] = readInt();
			}
			for(int i = 0; i < n; i++) {
				v[i] = readInt();
			}
			double lhs = 1;
			double rhs = 1e9;
			for(int qqq = 0; qqq < 200; qqq++) {
				double ll = (2*lhs+rhs)/3;
				double rr = (2*rhs+lhs)/3;
				if(solve(ll, x, v) > solve(rr, x, v)) {
					lhs = ll;
				}
				else {
					rhs = rr;
				}
			}
			pw.println(solve(lhs, x, v));
		}
		exitImmediately();
	}

	public static double solve(double loc, int[] x, int[] v) {
		double ret = 0;
		for(int i = 0; i < x.length; i++) {
			ret = Math.max(ret, Math.abs(loc - x[i]) / v[i]);
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