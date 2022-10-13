import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

public class D {
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
			k = Math.min(k, n-k);
			RangeTree tree = new RangeTree(n);
			long ret = 1;
			int i = 0;
			for(int iter = 0; iter < n; iter++){
				ret++;
				if(i == n-1) {
					int a = 0;
					int b = k-2;
					ret += tree.query(a, b);
				}
				else if(i+k-1 < n) {
					int a = i+1;
					int b = i+k-1;
					ret += tree.query(a, b);
				}
				else {
					ret += tree.query(i+1, n-1);
					ret += tree.query(0, (i+k-1)%n);
				}
				pw.print(ret);
				pw.print(" ");
				tree.update(i);
				tree.update((i+k)%n);
				i += k;
				i %= n;
			}
			pw.println();
		}
		pw.close();
	}

	static class RangeTree {
		int[] leaf;
		int size;
		public RangeTree(int x) {
			leaf = new int[4*x];
			size = x;
		}
		public void update(int index) {
			update(1, 0, size-1, index);
		}
		private void update(int index, int l, int r, int i) {
			if(i < l || i > r) return;
			if(l == r) {
				leaf[index]++;
			}
			else {
				int m = (l+r)/2;
				update(2*index, l, m, i);
				update(2*index+1, m+1, r, i);
				leaf[index] = leaf[2*index] + leaf[2*index+1];
			}
		}
		public int query(int l, int r) {
			return query(1, 0, size-1, l, r);
		}
		public int query(int index, int l, int r, int lhs, int rhs) {
			if(lhs > r || rhs < l) return 0;
			if(l >= lhs && r <= rhs) {
				return leaf[index];
			}
			int ret = 0;
			int m = (l+r)/2;
			ret += query(2*index, l, m, lhs, rhs);
			ret += query(2*index+1, m+1, r, lhs, rhs);
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