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
		outer: for(int casenum = 1; casenum <= qq; casenum++) {
			int n = readInt();
			int[] list = new int[n];
			for(int i = 0; i < n; i++) {
				list[i] = readInt();
			}
			int[] minL = new int[n];
			int[] maxL = new int[n];
			minL[0] = maxL[0] = list[0];
			for(int i = 1; i < n; i++) {
				minL[i] = Math.min(minL[i-1], list[i]);
				maxL[i] = Math.max(maxL[i-1], list[i]);
			}
			int[] minR = new int[n];
			int[] maxR = new int[n];
			minR[n-1] = maxR[n-1] = list[n-1];
			for(int i = n-2; i >= 0; i--) {
				minR[i] = Math.min(minR[i+1], list[i]);
				maxR[i] = Math.max(maxR[i+1], list[i]);
			}
			for(int i = 1; i < n-1; i++) {
				if(minL[i-1] < list[i] && minR[i+1] < list[i]) {
					pw.println(3);
					int a = i-1;
					int b = i+1;
					while(list[a] >= list[i]) a--;
					while(list[b] >= list[i]) b++;
					pw.println((a+1) + " " + (i+1) + " " + (b+1));
					continue outer;
				}
				if(maxL[i-1] > list[i] && maxR[i+1] > list[i]) {
					pw.println(3);
					int a = i-1;
					int b = i+1;
					while(list[a] <= list[i]) a--;
					while(list[b] <= list[i]) b++;
					pw.println((a+1) + " " + (i+1) + " " + (b+1));
					continue outer;
				}
			}
			pw.println(0);
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