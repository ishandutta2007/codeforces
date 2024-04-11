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
			int[] list = new int[n];
			for(int i = 0; i < n; i++) {
				list[i] = readInt();
			}
			ArrayList<Integer> swaps = new ArrayList<Integer>();
			for(int i = 0; i < n-1; i++) {
				if(list[i] > list[i+1]) {
					swaps.add(i);
				}
			}
			if(swaps.isEmpty()) {
				pw.println("yes");
				pw.println("1 1");
				continue;
			}
			int l = swaps.get(0);
			int r = swaps.get(swaps.size()-1)+1;
			int a = l;
			int b = r;
			while(a < b) {
				int c = list[a];
				list[a] = list[b];
				list[b] = c;
				a++;
				b--;
			}
			boolean ret = true;
			for(int i = 0; i < n-1; i++) {
				if(list[i] > list[i+1]) {
					ret = false;
				}
			}
			if(ret) {
				pw.println("yes");
				pw.println((l+1) + " " + (r+1));
			}
			else {
				pw.println("no");
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