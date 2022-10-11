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
			int[] list = new int[n];
			for(int i = 0; i < n; i++) {
				list[i] = readInt();
			}
			Map<Integer, Integer> map = new HashMap<Integer, Integer>();
			for(int i = 1; i <= n; i++) {
				int l = i-1;
				int r = n-i;
				if(l <= r) {
					int diff = list[l] - i;
					if(diff >= 0) {
						if(!map.containsKey(diff)) {
							map.put(diff, 0);
						}
						map.put(diff, map.get(diff) + 1);
					}
				}
				if(r > l) {
					int diff = list[r] - i;
					if(diff >= 0) {
						if(!map.containsKey(diff)) {
							map.put(diff, 0);
						}
						map.put(diff, map.get(diff) + 1);
					}
				}
			}
			int ret = n;
			for(int out: map.keySet()) {
				ret = Math.min(ret, n - map.get(out));
			}
			pw.println(ret);
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