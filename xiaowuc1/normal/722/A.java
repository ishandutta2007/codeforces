import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

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

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			String k = nextToken();
			String ret = null;
			int error = 123;
			for(int h = 0; h <= 23; h++) {
				for(int m = 0; m < 60; m++) {
					if(!valid(h, m, n)) continue;
					String cand = String.format("%02d:%02d", h, m);
					int errors = 0;
					for(int a = 0; a < cand.length(); a++) {
						if(cand.charAt(a) != k.charAt(a)) {
							errors++;
						}
					}
					if(errors < error) {
						error = errors;
						ret = cand;
					}
				}
			}
			pw.println(ret);
		}
		pw.close();
	}

	public static boolean valid(int h, int m, int n) {
		if(m < 0 || m > 59) return false;
		if(n == 12) return h >= 1 && h <= 12;
		if(n == 24) return h >= 0 && h < 24;
		return false;
	}
	
	private static void exitImmediately()	{
		pw.close();
		System.exit(0);
	}

	private static long readLong() throws IOException	{
		return Long.parseLong(nextToken());
	}

	private static double readDouble() throws IOException	{
		return Double.parseDouble(nextToken());
	}

	private static int readInt() throws IOException	{
		return Integer.parseInt(nextToken());
	}

	private static String nextToken() throws IOException	{
		while(st == null || !st.hasMoreTokens())	{
			if(!br.ready())	{
				exitImmediately();
			}
			st = new StringTokenizer(br.readLine().trim());
		}
		return st.nextToken();
	}
}