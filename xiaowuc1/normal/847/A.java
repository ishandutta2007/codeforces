import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

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
			int[] left = new int[n];
			int[] right = new int[n];
			int zeros = 0;
			for(int i = 0; i < n; i++) {
				left[i] = readInt()-1;
				right[i] = readInt()-1;
				if(left[i] < 0) {
					zeros++;
				}
			}
			while(zeros-- > 1) {
				int someList = 0;
				while(right[someList] >= 0) {
					someList = right[someList];
				}
				for(int i = 1; i < n; i++) {
					int curr = i;
					while(right[curr] >= 0) {
						curr = right[curr];
					}
					if(curr == someList) continue;
					curr = i;
					while(left[curr] >= 0) {
						curr = left[curr];
					}
					left[curr] = someList;
					right[someList] = curr;
					break;
				}
			}
			for(int i = 0; i < n; i++) {
				pw.println(++left[i] + " " + ++right[i]);
			}
		}
		pw.close();
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