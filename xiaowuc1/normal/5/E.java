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
			int from = 0;
			for(int i = 0; i < n; i++) {
				list[i] = readInt();
				if(list[i] > list[from]) {
					from = i;
				}
			}
			int[] height = new int[n+1];
			for(int i = 0; i <= n; i++) {
				height[i] = list[(from+i)%n];
			}
			int[] l = new int[n+1];
			int[] r = new int[n+1];
			int[] count = new int[n+1];
			for(int i = n - 1; i >= 0; i--) {
			    r[i] = i + 1;
			    while(r[i] < n && height[i] > height[r[i]]) {
			    	r[i] = r[r[i]];
			    }
			    if(r[i] < n && height[i] == height[r[i]]) {
			    	count[i] = count[r[i]] + 1;
			        r[i] = r[r[i]];
			    }
			}
			for(int i = 1; i <= n; i++) {
				l[i] = i-1;
				while(l[i] > 0 && height[i] > height[l[i]]) {
					l[i] = l[l[i]];
				}
				if(l[i] > 0 && height[i] == height[l[i]]) {
					l[i] = l[l[i]];
				}
			}
			long ret = 0;
			for(int out: count) {
				ret += out;
			}
			for(int i = 0; i <= n; i++) {
				if(height[i] == height[0]) continue;
				ret += 2;
				if(l[i] == 0 && r[i] == n) ret--;
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