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
		int qq = 1;
		//int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		boolean[] comp = new boolean[20000000];
		comp[0] = comp[1] = true;
		for(int i = 2; i * i < comp.length; i++) {
			if(!comp[i]) {
				for(int j = i*i; j < comp.length; j += i) {
					comp[j] = true;
				}
			}
		}
		outer: for(int casenum = 1; casenum <= qq; casenum++) {
			int n = readInt();
			if(n == 2) {
				printAnswer(n, new HashSet<Integer>());
				continue;
			}
			int totalSum = n*(n+1)/2;
			for(int i = 1; i <= n; i++) {
				if(!comp[i] && !comp[totalSum-i]) {
					Set<Integer> set = new HashSet<Integer>();
					set.add(i);
					printAnswer(n, set);
					continue outer;
				}
				for(int j = 1; j < i; j++) {
					if(!comp[i+j] && !comp[totalSum-i-j]) {
						Set<Integer> set = new HashSet<Integer>();
						set.add(i);
						set.add(j);
						printAnswer(n, set);
						continue outer;
					}
				}
			}
			for(int i = 1; i <= n; i++) {
				for(int j = 1; j < i; j++) {
					if(!comp[i] && !comp[j] && !comp[totalSum-i-j]) {
						printAnswer(n, new int[]{i, j});
						continue outer;
					}
				}
			}
			pw.println(-1);
		}
		exitImmediately();
	}

	public static void printAnswer(int n, int[] set) {
		StringBuilder sb = new StringBuilder();
		for(int i = 1; i <= n; i++) {
			if(set[0] == i) {
				sb.append("2 ");
			}
			else if(set[1] == i) {
				sb.append("3 ");
			}
			else {
				sb.append("1 ");
			}
		}
		pw.println(sb.toString().trim());
	}
	
	public static void printAnswer(int n, Set<Integer> set) {
		StringBuilder sb = new StringBuilder();
		for(int i = 1; i <= n; i++) {
			if(!set.contains(i)) {
				sb.append("1 ");
			}
			else {
				sb.append("2 ");
			}
		}
		pw.println(sb.toString().trim());
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