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
			int[] count = new int[1501];
			for(int i = 0; i < n; i++) {
				count[readInt()]++;
			}
			boolean done = false;
			for(int max = 3; !done && max <= 1500; max+=3) {
				int min = max/3;
				for(int a = min; !done && a <= min+max-a; a++) {
					Map<Integer, Integer> us = new HashMap<Integer, Integer>();
					inc(us, min);
					inc(us, max);
					inc(us, a);
					inc(us, min+max-a);
					int numNeedToAdd = 0;
					for(int out: us.keySet()) {
						numNeedToAdd += Math.max(0, us.get(out) - count[out]);
					}
					if(numNeedToAdd <= 4-n) {
						done = true;
						pw.println("YES");
						for(int x = 0; x < count.length; x++) {
							if(count[x] > 0) {
								us.put(x, us.get(x) - count[x]);
							}
						}
						for(int out: us.keySet()) {
							int num = us.get(out);
							while(num-- > 0) {
								pw.println(out);
							}
						}
					}
				}
			}
			if(!done) {
				pw.println("NO");
			}
		}
		exitImmediately();
	}

	public static void inc(Map<Integer, Integer> map, int key) {
		if(!map.containsKey(key)) {
			map.put(key, 0);
		}
		map.put(key, 1 + map.get(key));
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