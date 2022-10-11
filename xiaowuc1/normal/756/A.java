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
			int[] to = new int[n];
			int numCycles = 0;
			for(int i = 0; i < n; i++) {
				to[i] = readInt()-1;
			}
			int odd = 0;
			for(int i = 0; i < n; i++) {
				odd += readInt();
			}
			if(n == 1) {
				if(odd == 0) {
					pw.println(1);
				}
				else {
					pw.println(0);
				}
				continue;
			}
			boolean[] seen = new boolean[n];
			for(int i = 0; i < n; i++) {
				if(seen[i]) {
					continue;
				}
				numCycles++;
				seen[i] = true;
				int curr = to[i];
				while(!seen[curr]) {
					seen[curr] = true;
					curr = to[curr];
				}
			}
			odd %= 2;
			odd = 1 - odd;
			int ret = 0;
			if(numCycles > 1) {
				ret = numCycles;
			}
			if(odd == 1) {
				ret++;
			}
			pw.println(ret);
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