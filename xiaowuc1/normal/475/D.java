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
			Map<Integer, Long> ret = new HashMap<Integer, Long>();
			Map<Integer, Integer> curr = new HashMap<Integer, Integer>();
			incA(curr, list[0], 1);
			for(int i = 1; i <= n; i++) {
				for(int out: curr.keySet()) {
					incB(ret, out, curr.get(out));
				}
				if(i == n) continue;
				Map<Integer, Integer> next = new HashMap<Integer, Integer>();
				incA(next, list[i], 1);
				for(int out: curr.keySet()) {
					incA(next, gcd(list[i], out), curr.get(out));
				}
				curr = next;
			}
			int qqq = readInt();
			while(qqq-- > 0) {
				int key = readInt();
				if(!ret.containsKey(key)) {
					pw.println(0);
				}
				else {
					pw.println(ret.get(key));
				}
			}
		}
		exitImmediately();
	}

	public static void incA(Map<Integer, Integer> map, Integer key, Integer value) {
		if(!map.containsKey(key)) {
			map.put(key, 0);
		}
		map.put(key, map.get(key) + value);
	}

	public static void incB(Map<Integer, Long> map, Integer key, Integer value) {
		if(!map.containsKey(key)) {
			map.put(key, 0L);
		}
		map.put(key, map.get(key) + value);
	}

	public static int gcd(int a, int b)	{
		return a%b==0 ? b : gcd(b, a%b);
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