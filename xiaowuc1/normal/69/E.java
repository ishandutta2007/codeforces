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
			TreeSet<Integer> ret = new TreeSet<Integer>();
			Map<Integer, Integer> appear = new HashMap<Integer, Integer>();
			int[] list = new int[n];
			for(int i = 0; i < n; i++) {
				list[i] = readInt();
			}
			for(int i = 0; i < n; i++) {
				if(!appear.containsKey(list[i])) {
					appear.put(list[i], 0);
				}
				int val;
				appear.put(list[i], val = appear.get(list[i]) + 1);
				if(val == 1) {
					ret.add(list[i]);
				}
				else {
					ret.remove(list[i]);
				}
				if(i >= k) {
					appear.put(list[i-k], val = appear.get(list[i-k]) - 1);
					if(val == 1) {
						ret.add(list[i-k]);
					}
					else {
						ret.remove(list[i-k]);
					}
				}
				if(i >= k-1) {
					if(ret.isEmpty()) pw.println("Nothing");
					else pw.println(ret.last());
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