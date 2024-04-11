import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

public class B {
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
			long[] amt = new long[n];
			long[] pref = new long[n+1];
			for(int i = 0; i < n; i++) {
				amt[i] = readLong();
			}
			for(int i = 0; i < n; i++) {
				pref[i+1] = pref[i] + readLong();
			}
			int[] numDone = new int[n+1];
			long[] extra = new long[n+1];
			for(int i = 0; i < n; i++) {
				int lhs = i;
				int rhs = n;
				while(lhs != rhs) {
					int mid = (lhs+rhs+1)/2;
					if(pref[mid] - pref[i] <= amt[i]) {
						lhs = mid;
					}
					else {
						rhs = mid-1;
					}
				}
				numDone[i]++;
				numDone[lhs]--;
				long add = amt[i] - (pref[lhs] - pref[i]);
				extra[lhs] += add;
			}
			int num = 0;
			for(int i = 0; i < n; i++) {
				num += numDone[i];
				pw.print(num * (pref[i+1] - pref[i]) + extra[i]);
				if(i < n-1) pw.print(" ");
				else pw.println();
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