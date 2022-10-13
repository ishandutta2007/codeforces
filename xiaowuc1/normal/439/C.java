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
			int parts = readInt();
			int even = readInt();
			int odd = parts - even;
			ArrayList<Integer>[] ret = new ArrayList[parts];
			for(int i = 0; i < parts; i++) {
				ret[i] = new ArrayList<Integer>();
			}
			LinkedList<Integer> odds = new LinkedList<Integer>();
			LinkedList<Integer> evens = new LinkedList<Integer>();
			while(n-- > 0) {
				int curr = readInt();
				if(curr % 2 == 0) {
					evens.add(curr);
				}
				else {
					odds.add(curr);
				}
			}
			if(odds.size() < odd) {
				pw.println("NO");
				continue;
			}
			for(int i = 0; i < odd; i++) {
				ret[i].add(odds.removeFirst());
			}
			if(odds.size() % 2 == 1) {
				pw.println("NO");
				continue;
			}
			boolean bad = false;
			for(int i = odd; !bad && i < parts; i++) {
				if(odds.size() >= 2) {
					ret[i].add(odds.removeFirst());
					ret[i].add(odds.removeFirst());
				}
				else if(!evens.isEmpty()) {
					ret[i].add(evens.removeFirst());
				}
				else {
					bad = true;
					break;
				}
			}
			if(bad) {
				pw.println("NO");
				continue;
			}
			while(!odds.isEmpty()) {
				ret[0].add(odds.removeFirst());
			}
			while(!evens.isEmpty()) {
				ret[0].add(evens.removeFirst());
			}
			pw.println("YES");
			for(int i = 0; i < ret.length; i++) {
				pw.print(ret[i].size());
				for(int out: ret[i]) {
					pw.print(" " + out);
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