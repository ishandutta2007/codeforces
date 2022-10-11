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
			int w = readInt();
			int h = readInt();
			int qqq = readInt();
			TreeSet<Integer> xs = new TreeSet<Integer>();
			xs.add(0);
			xs.add(w);
			TreeSet<Integer> ys = new TreeSet<Integer>();
			ys.add(0);
			ys.add(h);
			TreeMap<Integer, Integer> ws = new TreeMap<Integer, Integer>();
			TreeMap<Integer, Integer> hs = new TreeMap<Integer, Integer>();
			ws.put(w, 1);
			hs.put(h, 1);
			while(qqq-- > 0) {
				TreeMap<Integer, Integer> map;
				TreeSet<Integer> set;
				if(nextToken().equals("H")) {
					map = hs;
					set = ys;
				}
				else {
					map = ws;
					set = xs;
				}
				int type = readInt();
				set.add(type);
				int up = set.higher(type);
				int down = set.lower(type);
				int len = up-down;
				map.put(len, map.get(len) - 1);
				if(map.get(len) == 0) map.remove(len);
				if(!map.containsKey(up-type)) map.put(up-type, 0);
				map.put(up-type, 1 + map.get(up-type));
				if(!map.containsKey(type-down)) map.put(type-down, 0);
				map.put(type-down, 1 + map.get(type-down));
				pw.println(ws.lastKey() * 1L * hs.lastKey());
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