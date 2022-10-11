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
	private static StringTokenizer st;
	private static PrintWriter pw;

	public static void main(String[] args) throws IOException {
		InputReader br = new InputReader(System.in);
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		outer: for(int casenum = 1; casenum <= qq; casenum++) {
			int n = br.readInt();
			int d = br.readInt();
			long[] list = new long[n];
			direct = new int[n];
			long[] sorted = new long[n];
			HashMap<Long, Integer> locs = new HashMap<Long, Integer>();
			for(int i = 0; i < n; i++) {
				sorted[i] = list[i] = br.readLong();
			}
			Arrays.sort(sorted);
			RangeTree tree = new RangeTree(n);
			int[] parent = new int[n];
			int[] dp = new int[n];
			Arrays.fill(dp, 1);
			Arrays.fill(parent, -1);

			long[] lows = new long[n+1];
			long[] highs = new long[n+1];
			Arrays.fill(lows, Long.MAX_VALUE);

			long small = sorted[0];
			long big = sorted[n-1];
			int bestIndex = 0;
			for(int i = 0; i < n; i++) {
				if(small <= list[i] - d) {
					int lowIndex = floor(sorted, list[i] - d);
					int update = 1 + tree.query(0, lowIndex);
					if(update > dp[i]) {
						dp[i] = update;
						parent[i] = locs.get(lows[update-1]);
					}
				}
				if(big >= list[i] + d) {
					int highIndex = ceiling(sorted, list[i] + d);
					int update = 1 + tree.query(highIndex, n - 1);
					if(update > dp[i]) {
						dp[i] = update;
						parent[i] = locs.get(highs[update-1]);
					}
				}
				tree.update(Arrays.binarySearch(sorted, list[i]), dp[i]);
				lows[dp[i]] = Math.min(lows[dp[i]], list[i]);
				highs[dp[i]] = Math.max(highs[dp[i]], list[i]);
				locs.put(list[i], i);
				if(dp[i] > dp[bestIndex]) {
					bestIndex = i;
				}
			}
			pw.println(dp[bestIndex]);
			LinkedList<Integer> ret = new LinkedList<Integer>();
			ret.add(bestIndex);
			while(dp[bestIndex] > 1) {
				bestIndex = parent[bestIndex];
				ret.addFirst(bestIndex);
			}
			for(int out: ret) {
				pw.print(++out);
				pw.print(" ");
			}
			pw.println();
		}
		exitImmediately();
	}

	public static int floor(long[] list, long v) {
		int l = 0;
		int r = list.length-1;
		while(l != r) {
			int m = (l+r+1)/2;
			if(list[m] > v) {
				r = m-1;
			}
			else {
				l = m;
			}
		}
		return l;
	}
	
	public static int ceiling(long[] list, long v) {
		int l = 0;
		int r = list.length-1;
		while(l != r) {
			int m = (l+r)/2;
			if(list[m] < v) {
				l = m+1;
			}
			else {
				r = m;
			}
		}
		return l;
	}
	
	static int[] direct;
	
	static class RangeTree {
		public int[] leaf;
		public int size;
		public RangeTree(int in) {
			size = in;
			leaf = new int[4*in];
			populateDirect(1, 0, size-1);
		}
		public void populateDirect(int index, int l, int r) {
			if(l == r) {
				direct[l] = index;
			}
			else {
				int m = (l+r)/2;
				populateDirect(2*index, l, m);
				populateDirect(2*index+1, m+1, r);
			}
		}
		public void update(int index, int val) {
			int curr = direct[index];
			if(leaf[curr] >= val) return;
			leaf[curr] = val;
			while(curr > 1) {
				int parent = curr / 2;
				if(leaf[curr] <= leaf[parent]) return;
				leaf[parent] = leaf[curr];
				curr = parent;
			}
		}
		public int query(int l, int r) {
			return query(1, 0, size-1, l, r);
		}
		public int query(int treeIndex, int tL, int tR, int l, int r) {
			if(tL >= l && tR <= r) {
				return leaf[treeIndex];
			}
			int tM = (tL+tR)/2;
			int ret = 0;
			if(tM >= l) {
				ret = Math.max(ret, query(2*treeIndex, tL, tM, l, r));
			}
			if(tM+1 <= r) {
				ret = Math.max(ret, query(2*treeIndex+1, tM+1, tR, l, r));
			}
			return ret;
		}
	}

	private static void exitImmediately() {
		pw.close();
		System.exit(0);
	}

	static class InputReader {

		private InputStream stream;
		private byte[] buf = new byte[1024];
		private int curChar;
		private int numChars;

		public InputReader(InputStream stream) {
			this.stream = stream;
		}

		public int read() {
			if (numChars == -1) {
				exitImmediately();
				throw new InputMismatchException();
			}
			if (curChar >= numChars) {
				curChar = 0;
				try {
					numChars = stream.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (numChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}

		public int readInt() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			int res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public long readLong() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			long res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public String readString() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isSpaceChar(c));
			return res.toString();
		}

		public boolean isSpaceChar(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		public String next() {
			return readString();
		}
	}
}