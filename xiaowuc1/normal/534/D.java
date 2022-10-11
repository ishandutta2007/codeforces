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
			LinkedList<Integer>[] lists = new LinkedList[n];
			for(int i = 0; i < n; i++) {
				lists[i] = new LinkedList<Integer>();
			}
			for(int i = 1; i <= n; i++) {
				lists[readInt()].add(i);
			}
			ArrayList<Integer> ret = new ArrayList<Integer>();
			int curr = 0;
			boolean bad = false;
			while(n-- > 0) {
				while(!bad && lists[curr].isEmpty()) {
					if(curr - 3 < 0) {
						bad = true;
					}
					curr -= 3;
				}
				if(bad) break;
				ret.add(lists[curr++].removeFirst());
			}
			if(bad) {
				pw.println("Impossible");
			}
			else {
				pw.println("Possible");
				for(int out: ret) {
					pw.print(out + " ");
				}
				pw.println();
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