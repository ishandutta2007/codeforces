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
		p = new int[1000001];
		for(int i = 2; i < p.length; i++) {
			p[i] = i;
		}
		for(int i = 2; i * i < p.length; i++) {
			if(p[i] != i) continue;
			for(int j = i*i; j < p.length; j += i) {
				p[j] = i;
			}
		}
		seen = new boolean[1000001][3];
		for(int casenum = 1; casenum <= qq; casenum++) {
			int n = readInt();
			ret = n;
			solve(n, 2);
			pw.println(ret);
		}
		pw.close();
	}

	static int ret;
	static int[] p;
	static boolean[][] seen;

	public static void solve(int n, int d) {
		if(seen[n][d]) return;
		seen[n][d] = true;
		int now = n;
		while(now > 1) {
			int div = p[now];
			if(d == 2) {
				for(int a = Math.max(Math.max(div, 3), n - div + 1); a < n; a++) {
					solve(a, d-1);
				}
			}
			else {
				ret = Math.min(ret, Math.max(Math.max(div, 3), n - div + 1));
			}
			now /= div;
		}
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