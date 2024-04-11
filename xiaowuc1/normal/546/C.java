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
			Queue<Integer> a = new LinkedList<Integer>();
			Queue<Integer> b = new LinkedList<Integer>();
			int aa = readInt();
			while(aa-- > 0) {
				a.add(readInt());
			}
			int bb = readInt();
			while(bb-- > 0) {
				b.add(readInt());
			}
			int iter = -1;
			final int MAX = 10000000;
			while(++iter <= MAX && !a.isEmpty() && !b.isEmpty()) {
				if(a.peek() > b.peek()) {
					a.add(b.poll());
					a.add(a.poll());
				}
				else {
					b.add(a.poll());
					b.add(b.poll());
				}
			}
			if(iter > MAX) {
				pw.println(-1);
			}
			else if(a.isEmpty()) {
				pw.println(iter + " 2");
			}
			else {
				pw.println(iter + " 1");
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