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
			ArrayList<Integer> a = new ArrayList<Integer>();
			ArrayList<Integer> b = new ArrayList<Integer>();
			boolean last = true;
			while(n-- > 0) {
				int curr = readInt();
				if(curr > 0) {
					a.add(curr);
					last = false;
				}
				else {
					b.add(-curr);
					last = true;
				}
			}
			if(compare(a, b) < 0) {
				pw.println("second");
			}
			else if(compare(a, b) > 0){
				pw.println("first");
			}
			else if(last) {
				pw.println("second");
			}
			else {
				pw.println("first");
			}
		}
		exitImmediately();
	}

	public static long sum(ArrayList<Integer> list) {
		long ret = 0;
		for(int out: list) {
			ret += out;
		}
		return ret;
	}
	
	public static int compare(ArrayList<Integer> a, ArrayList<Integer> b) {
		long aa = sum(a);
		long bb = sum(b);
		if(aa < bb) return -1;
		if(aa > bb) return 1;
		for(int i = 0; i < Math.min(a.size(), b.size()); i++) {
			if(a.get(i).intValue() != b.get(i).intValue()) {
				return a.get(i) - b.get(i);
			}
		}
		return a.size() - b.size();
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