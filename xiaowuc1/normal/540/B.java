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
			int n = readInt();
			int k = readInt();
			int[] list = new int[n];
			int p = readInt();
			int x = readInt(); // sum <= x
			int y = readInt(); // median >= y
			for(int i = 0; i < k; i++) { 
				list[i] = readInt();
			}
			Arrays.sort(list);
			ArrayList<Integer> ret = new ArrayList<Integer>();
			while(list[0] == 0) {
				if(list[n/2] < y) {
					list[0] = y;
					ret.add(y);
				}
				else {
					list[0] = 1;
					ret.add(1);
				}
				Arrays.sort(list);
			}
			if(list[n/2] < y) {
				pw.println(-1);
				continue;
			}
			int sum = 0;
			for(int out: list) {
				sum += out;
			}
			if(sum > x) {
				pw.println(-1);
				continue;
			}
			for(int out: ret) {
				pw.print(out + " ");
			}
			pw.println();
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