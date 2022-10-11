import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

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
			long[] l = new long[n];
			for(int i = 0; i < n; i++) {
				l[i] = readLong();
			}
			long[] fromLHS = new long[n];
			long[] atLHS = new long[n];
			atLHS[0] = l[0];
			for(int i = 1; i < n; i++) {
				atLHS[i] = Math.max(atLHS[i-1] + 1, l[i]);
				fromLHS[i] = fromLHS[i-1] + atLHS[i] - l[i];
			}
			long[] fromRHS = new long[n];
			long[] atRHS = new long[n];
			atRHS[n-1] = l[n-1];
			for(int i = n-2; i >= 0; i--) {
				atRHS[i] = Math.max(atRHS[i+1] + 1, l[i]);
				fromRHS[i] = fromRHS[i+1] + atRHS[i] - l[i];
			}
			long ret = Math.min(fromRHS[0], fromLHS[n-1]);
			for(int i = 1; i < n-1; i++) {
				ret = Math.min(ret, fromLHS[i-1] + fromRHS[i+1] + Math.max(atLHS[i], atRHS[i]) - l[i]);
			}
			pw.println(ret);
		}
		pw.close();
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