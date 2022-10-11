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
			int n = readInt();
			boolean[] can = new boolean[n];
			String s = nextLine();
			for(int i = 0; i < n; i++) {
				can[i] = s.charAt(i) == '0';
			}
			boolean good = true;
			for(int i = 0; i+1 < n; i++) {
				if(!can[i] && !can[i+1]) {
					good = false;
				}
			}
			for(int i = 0; i < n; i++) {
				if(!can[i]) continue;
				if(i > 0 && !can[i-1]) continue;
				if(i+1 < n && !can[i+1]) continue;
				good = false;
			}
			pw.println(good ? "Yes" : "No");
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