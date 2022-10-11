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
			int k = readInt();
			int[] l = new int[n];
			for(int i = 0; i < n; i++) {
				l[i] = i;
			}
			long ret = 0;
			for(int i = 0; i < n-1-i && k > 0; i++, k--) {
				int ii = n-1-i;
				l[i] ^= l[ii];
				l[ii] ^= l[i];
				l[i] ^= l[ii];
			}
			BIT bit = new BIT(n);
			for(int i = 0; i < n; i++) {
				ret += i - bit.query(l[i]);
				bit.update(l[i], 1);
			}
			pw.println(ret);
		}
		pw.close();
	}

	static class BIT {
		public int[] leaf;
		public BIT(int n) {
			leaf = new int[n+5];
		}
		public void update(int index, int val) {
			index += 2;
			while(index < leaf.length) {
				leaf[index] += val;
				index += index & -index;
			}
		}
		public int query(int index) {
			index += 2;
			int ret = 0;
			while(index > 0) {
				ret += leaf[index];
				index -= index & -index;
			}
			return ret;
		}
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