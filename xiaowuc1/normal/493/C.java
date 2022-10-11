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
			LinkedList<Integer> a = new LinkedList<Integer>();
			for(int i = 0; i < n; i++) {
				a.add(readInt());
			}
			int m = readInt();
			LinkedList<Integer> b = new LinkedList<Integer>();
			for(int i = 0; i < m; i++) {
				b.add(readInt());
			}
			Collections.sort(a);
			Collections.sort(b);
			int aRet = 3 * a.size();
			int bRet = 3 * b.size();
			int aCurr = 3 * a.size();
			int bCurr = 3 * b.size();
			while(!a.isEmpty() || !b.isEmpty()) {
				int min = Math.min(get(a), get(b));
				while(!a.isEmpty() && a.peekFirst() == min) {
					aCurr--;
					a.removeFirst();
				}
				while(!b.isEmpty() && b.peekFirst() == min) {
					bCurr--;
					b.removeFirst();
				}
				if(aCurr - bCurr > aRet - bRet) {
					aRet = aCurr;
					bRet = bCurr;
				}
			}
			pw.println(aRet + ":" + bRet);
		}
		exitImmediately();
	}
	
	public static int get(LinkedList<Integer> a) {
		return a.size() > 0 ? a.getFirst() : Integer.MAX_VALUE;
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