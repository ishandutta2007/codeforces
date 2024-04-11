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
			int[] prev = new int[1000005];
			int[] next = new int[1000005];
			boolean[] processed = new boolean[1000005];
			boolean[] seen = new boolean[1000005];
			Arrays.fill(prev, -1);
			Arrays.fill(next, -1);
			int[] ret = new int[n];
			
			while(n-- > 0) {
				int a = readInt();
				int b = readInt();
				next[a] = b;
				prev[b] = a;
				seen[a] = true;
				seen[b] = true;
			}
			
			for(int i = 1; i < seen.length; i++) {
				if(!seen[i] || processed[i]) continue;
				int curr = i;
				while(prev[curr] > 0) {
					curr = prev[curr];
				}
				int start = 0;
				if(prev[curr] == 0) {
					start = 1;
				}
				while(curr > 0) {
					ret[start] = curr;
					processed[curr] = true;
					start += 2;
					curr = next[curr];
				}
			}
			
			for(int out: ret) {
				pw.print(out + " ");
			}
			pw.println();
		}
		exitImmediately();
	}
	
	public static int get(LinkedList<Integer> a) {
		return a.size() > 0 ? a.getFirst() : Integer.MAX_VALUE;
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