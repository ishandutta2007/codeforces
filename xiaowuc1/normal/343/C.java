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
			int m = readInt();
			long[] heads = new long[n];
			long[] tracks = new long[m];
			for(int i = 0; i < n; i++) {
				heads[i] = readLong();
			}
			for(int i = 0; i < m; i++) {
				tracks[i] = readLong();
			}
			long min = 0;
			long max = 20000000000L;
			while(min != max) {
				long mid = (min+max)/2;
				int firstNotDone = 0;
				boolean fail = false;
				for(int i = 0; i < n && firstNotDone < m; i++) {
					if(heads[i] - tracks[firstNotDone] > mid) {
						fail = true;
						break;
					}
					if(heads[i] > tracks[firstNotDone]) { 
						// must come back
						long x = heads[i] - tracks[firstNotDone];
						long d = (mid - x) / 2;
						firstNotDone = Math.max(firstFail(tracks, heads[i] + d), firstFail(tracks, heads[i] + mid - 2*x));
					}
					else {
						firstNotDone = firstFail(tracks, heads[i] + mid);	
					}
				}
				if(fail || firstNotDone < m) {
					min = mid+1;
				}
				else {
					max = mid;
				}
			}
			pw.println(min);
		}
		exitImmediately();
	}

	public static int firstFail(long[] list, long c) {
		if(c >= list[list.length-1]) return list.length;
		int min = 0;
		int max = list.length-1;
		while(min != max) {
			int mid = (min+max)/2;
			if(list[mid] > c) {
				max = mid;
			}
			else {
				min = mid+1;
			}
		}
		return min;
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