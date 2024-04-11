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
			int[] score = new int[n];
			int[] pref = new int[n];
			int curr = 1;
			for(int i = 0; i < n; i++) {
				list[i] = readInt();
			}
			bad = new HashSet<Integer>();
			dp = new HashMap<Integer, Integer>();
			while(m-- > 0) {
				bad.add(readInt());
			}
			int ret = 0;
			for(int i = 0; i < n; i++) {
				ret += score[i] = compute(list[i]);
				if(i == 0) pref[i] = list[i];
				else pref[i] = gcd(pref[i-1], list[i]);
			}
			for(int i = n-1; i >= 0; i--) {
				int div = pref[i] / curr;
				if(compute(div) < 0) {
					ret -= (i+1) * compute(div);
					curr = pref[i];
				}
			}
			pw.println(ret);
		}
		exitImmediately();
	}
	
	public static int gcd(int a, int b) {
		if(a==0 || b==0) return Math.max(a, b);
		return gcd(b, a%b);
	}
	
	static Set<Integer> bad = new HashSet<Integer>();
	static Map<Integer, Integer> dp = new HashMap<Integer, Integer>();
	public static int compute(final int key) {
		if(!dp.containsKey(key)) {
			int s = 0;
			int temp = key;
			for(int i = 2; i * i <= temp; i++) {
				while(temp%i == 0) {
					if(bad.contains(i)) {
						s--;
					}
					else {
						s++;
					}
					temp /= i;
				}
			}
			if(temp > 1) {
				if(bad.contains(temp)) {
					s--;
				}
				else {
					s++;
				}
			}
			dp.put(key, s);
		}
		return dp.get(key);
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