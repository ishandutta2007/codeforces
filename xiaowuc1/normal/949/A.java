import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

public class A {
	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter pw;

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++) {
			ArrayList<ArrayList<Integer>> good = new ArrayList<ArrayList<Integer>>();
			ArrayList<ArrayList<Integer>> bad = new ArrayList<ArrayList<Integer>>();
			String s = nextToken();
			boolean done = false;
			for(int i = 0; !done && i < s.length(); i++) {
				if(s.charAt(i) == '0') {
					if(!bad.isEmpty()) {
						ArrayList<Integer> now = bad.remove(bad.size()-1);
						now.add(i+1);
						good.add(now);
					}
					else {
						ArrayList<Integer> now = new ArrayList<Integer>();
						now.add(i+1);
						good.add(now);
					}
				}
				else {
					if(good.isEmpty()) {
						done = true;
						pw.println(-1);
					}
					else {
						ArrayList<Integer> now = good.remove(good.size()-1);
						now.add(i+1);
						bad.add(now);
					}
				}
			}
			if(done) continue;
			if(!bad.isEmpty()) {
				pw.println(-1);
			}
			else {
				pw.println(good.size());
				for(ArrayList<Integer> out: good) {
					pw.print(out.size());
					for(int out2: out) {
						pw.print(" ");
						pw.print(out2);
					}
					pw.println();
				}
			}
		}
		pw.close();
	}

	public static void exitImmediately() {
		pw.close();
		System.exit(0);
	}

	public static int readInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	public static double readDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	public static long readLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	public static String nextLine() throws IOException {
		st = null;
		if(!br.ready()) {
			exitImmediately();
		}
		return br.readLine();
	}

	public static String nextToken() throws IOException {
		while(st == null || !st.hasMoreTokens()) {
			if(!br.ready()) {
				exitImmediately();
			}
			st = new StringTokenizer(br.readLine());
		}
		return st.nextToken();
	}
}