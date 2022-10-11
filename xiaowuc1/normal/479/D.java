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
			int l = readInt();
			int a = readInt();
			int b = readInt();
			int[] list = new int[n];
			for(int i = 0; i < n; i++) {
				list[i] = readInt();
			}
			boolean hasA = false;
			boolean hasB = false;
			for(int i = 0; i < n; i++) {
				hasA |= has(list, list[i] + a);
				hasB |= has(list, list[i] + b);
			}
			if(hasA && hasB) {
				pw.println(0);
				continue;
			}
			else if(!hasA && hasB) {
				pw.println(1);
				pw.println(a);
				continue;
			}
			else if(hasA && !hasB) {
				pw.println(1);
				pw.println(b);
				continue;
			}
			boolean one = false;
			for(int i = 0; !one && i < list.length; i++) {
				if(has(list, list[i] + a + b)){
					one = true;
					pw.println(1);
					pw.println(list[i] + a);
				}
			}
			if(one) continue;
			for(int i = 0; !one && i < list.length; i++) {
				if(has(list, list[i] + b - a) && list[i] + b <= l){
					one = true;
					pw.println(1);
					pw.println(list[i] + b);
				}
			}
			if(one) continue;
			for(int i = 0; !one && i < list.length; i++) {
				if(has(list, list[i] + a - b) && list[i] + a <= l){
					one = true;
					pw.println(1);
					pw.println(list[i] + a);
				}
			}
			if(one) continue;
			for(int i = 0; !one && i < list.length; i++) {
				if(has(list, list[i] - b + a) && list[i] - b >= 0){
					one = true;
					pw.println(1);
					pw.println(list[i] - b);
				}
			}
			if(one) continue;
			for(int i = 0; !one && i < list.length; i++) {
				if(has(list, list[i] - a + b) && list[i] - a >= 0){
					one = true;
					pw.println(1);
					pw.println(list[i] - a);
				}
			}
			if(one) continue;
			
			pw.println(2);
			pw.println(a + " " + b);
		}
		exitImmediately();
	}

	public static boolean has(int[] list, int x) {
		return Arrays.binarySearch(list, x) >= 0;
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