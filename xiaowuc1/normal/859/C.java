import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

public class C {
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
			int n = readInt();
			l = new int[n];
			p = new int[n+1];
			int s = 0;
			for(int i = 0; i < n; i++) {
				s += l[i] = readInt();
				p[i+1] = p[i] + l[i];
			}
			alice = new int[n+1];
			bob = new int[n+1];
			Arrays.fill(alice, -1);
			Arrays.fill(bob, -1);
			alice[n] = 0;
			bob[n] = 0;
			int ret = bob(0);
			pw.println((s-ret) + " " + ret);
		}
		pw.close();
	}

	public static int bob(int n) {
		if(bob[n] >= 0) return bob[n];
		bob[n] = l[n] + (p[p.length-1] - p[n+1] - alice(n+1));
		bob[n] = Math.max(bob[n], bob(n+1));
		return bob[n];
	}
	
	public static int alice(int n) {
		if(alice[n] >= 0) return alice[n];
		alice[n] = l[n] + (p[p.length-1] - p[n+1] - bob(n+1));
		alice[n] = Math.max(alice[n], alice(n+1));
		return alice[n];
	}
	
	static int[] p;
	static int[] l;
	static int[] alice;
	static int[] bob;
	
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