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

	static int[][][][] dp;
	static int[][] prefix;
	
	public static void main(String[] args) throws Exception {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			int m = readInt();
			int[] list = new int[n];
			int[] sayDid = new int[n+1];
			int[] sayDidNot = new int[n+1];
			int pos = 0;
			int neg = 0;
			for(int i = 0; i < n; i++) {
				list[i] = readInt();
				if(list[i] > 0) {
					pos++;
					sayDid[list[i]]++;
				}
				else {
					neg++;
					sayDidNot[-list[i]]++;
				}
			}
			Set<Integer> did = new HashSet<Integer>();
			for(int i = 1; i <= n; i++) {
				int truth = sayDid[i] + (neg - sayDidNot[i]);
				if(truth == m) {
					did.add(i);
				}
			}
			for(int i = 0; i < n; i++) {
				if(list[i] > 0) {
					if(did.contains(list[i])) {
						if(did.size() == 1) {
							pw.println("Truth");
						}
						else {
							pw.println("Not defined");
						}
					}
					else {
						pw.println("Lie");
					}
				}
				else {
					if(!did.contains(-list[i])) {
						pw.println("Truth");
					}
					else if(did.size() == 1) {
						pw.println("Lie");
					}
					else {
						pw.println("Not defined");
					}
				}
			}
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