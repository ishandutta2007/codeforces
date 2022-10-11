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

	static int BUCKET_SIZE = (int)Math.sqrt(200000);
	
	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++) {
			int n = readInt();
			int k = readInt();
			BUCKET_SIZE = (int)Math.sqrt(n);
			int[] list = new int[n];
			for(int i = 0; i < n; i++) {
				list[i] = readInt();
			}
			Query[] queries = new Query[k];
			for(int i = 0; i < k; i++) {
				queries[i] = new Query(readInt()-1, readInt()-1, i);
			}
			Arrays.sort(queries);
			long[] ans = new long[k];
			int[] appear = new int[1000001];
			int left = -1;
			int right = -1;
			int lastBucket = -1;
			long curr = 0;
			for(Query currQ: queries) {
				if(currQ.bucket() != lastBucket) {
					Arrays.fill(appear, 0);
					curr = 0;
					for(int a = currQ.left; a <= currQ.right; a++) {
						curr -= appear[list[a]] * 1L * appear[list[a]] * 1L * list[a];
						appear[list[a]]++;
						curr += appear[list[a]] * 1L * appear[list[a]] * 1L * list[a];
					}
				}
				else {
					for(int a = currQ.left; a < left; a++) {
						curr -= appear[list[a]] * 1L * appear[list[a]] * 1L * list[a];
						appear[list[a]]++;
						curr += appear[list[a]] * 1L * appear[list[a]] * 1L * list[a];
					}
					for(int a = left; a < currQ.left; a++) {
						curr -= appear[list[a]] * 1L * appear[list[a]] * 1L * list[a];
						appear[list[a]]--;
						curr += appear[list[a]] * 1L * appear[list[a]] * 1L * list[a];
					}
					for(int a = right+1; a <= currQ.right; a++) {
						curr -= appear[list[a]] * 1L * appear[list[a]] * 1L * list[a];
						appear[list[a]]++;
						curr += appear[list[a]] * 1L * appear[list[a]] * 1L * list[a];
					}
					for(int a = currQ.right+1; a <= right; a++) {
						curr -= appear[list[a]] * 1L * appear[list[a]] * 1L * list[a];
						appear[list[a]]--;
						curr += appear[list[a]] * 1L * appear[list[a]] * 1L * list[a];
					}
				}
				lastBucket = currQ.bucket();
				left = currQ.left;
				right = currQ.right;
				ans[currQ.index] = curr;
			}
			for(long out: ans) {
				pw.println(out);
			}
		}
		exitImmediately();
	}

	static class Query implements Comparable<Query> {
		public int left, right, index;
		public Query(int a, int b, int c) {
			left = a;
			right = b;
			index = c;
		}
		public int bucket() {
			return left / BUCKET_SIZE;
		}
		public int compareTo(Query q) {
			if(bucket() != q.bucket()) return bucket() - q.bucket();
			return right - q.right;
		}
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