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
			int[] w = new int[n];
			int[] h = new int[n];
			TreeMap<Integer, Integer> map = new TreeMap<Integer, Integer>();
			int wSum = 0;
			for(int i = 0; i < n; i++) {
				w[i] = readInt();
				h[i] = readInt();
				update(map, h[i], 1);
				wSum += w[i];
			}
			for(int i = 0; i < n; i++) {
				update(map, h[i], -1);
				pw.print((wSum-w[i]) * map.lastKey() + " ");
				update(map, h[i], 1);
			}
			pw.println();
		}
		exitImmediately();
	}

	public static void update(Map<Integer, Integer> m, int k, int d) {
		if(!m.containsKey(k)) {
			m.put(k, 0);
		}
		m.put(k, m.get(k) + d);
		if(m.get(k) == 0) m.remove(k);
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