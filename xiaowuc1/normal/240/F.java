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
	private static BufferedReader br;
	private static StringTokenizer st;
	private static PrintWriter pw;

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new FileReader("input.txt"));
		pw = new PrintWriter(new BufferedWriter(new FileWriter("output.txt")));
		int qq = 1;
		//int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++) {
			RangeTree[] trees = new RangeTree[26];
			int n = readInt();
			int k = readInt();
			for(int i = 0; i < 26; i++) {
				trees[i] = new RangeTree(n);
			}
			String s = br.readLine();
			for(int i = 0; i < n; i++) {
				trees[s.charAt(i) - 'a'].addOne(i, i);
			}
			outer: while(k-- > 0) {
				int left = readInt()-1;
				int right = readInt()-1;
				int length = right-left+1;
				int odds = 0;
				int[] queries = new int[26];
				for(int i = 0; i < 26; i++) {
					queries[i] = trees[i].query(left, right); 
					if(queries[i] % 2 == 1) {
						odds++;
						if(length%2 == 0 || odds > 1) {
							continue outer;
						}
					}
				}
				int leftStart = left;
				int rightEnd = right;
				for(int i = 0; i < 26; i++) {
					int numIn = queries[i];
					if(queries[i] == 0) continue;
					trees[i].delete(left, right);
					if(numIn % 2 == 1) {
						trees[i].addOne((left+right)/2, (left+right)/2);
					}
					numIn /= 2;
					trees[i].addOne(leftStart, leftStart + numIn - 1);
					trees[i].addOne(rightEnd - numIn + 1, rightEnd);
					leftStart += numIn;
					rightEnd -= numIn;
				}
			}
			for(int i = 0; i < n; i++) {
				for(int a = 0; a < 26; a++) {
					if(trees[a].query(i, i) == 1) {
						pw.print((char)('a' + a));
						break;
					}
				}
			}
			pw.println();
		}
		exitImmediately();
	}

	static class RangeTree {
		public int[] leaf;
		public int[] lazy;
		public int size;
		public boolean[] delete;

		public RangeTree(int sizeIn) {
			leaf = new int[4*sizeIn];
			lazy = new int[4*sizeIn];
			delete = new boolean[4*sizeIn];
			size = sizeIn;
		}

		private void delete(int index) {
			delete[index] = true;
			leaf[index] = 0;
			lazy[index] = 0;
		}

		public void pushDown(int index, int left, int right) {
			if(delete[index]) {
				delete[index] = false;
				if(left != right) {
					delete(2*index);
					delete(2*index+1);
				}
			}
			if(lazy[index] > 0) {
				leaf[index] += (right-left+1) * lazy[index];
				if(left != right) {
					lazy[2*index] += lazy[index];
					lazy[2*index+1] += lazy[index];
				}
				lazy[index] = 0;
			}
		}

		public void pullUp(int index, int left, int right) {
			if(left == right) throw new RuntimeException("NO");
			int mid = (left+right)/2;
			lazy[index] = 0;
			delete[index] = false;
			leaf[index] = leaf[2*index] + leaf[2*index+1];
			leaf[index] += (mid-left+1) * lazy[2*index];
			leaf[index] += (right-mid) * lazy[2*index+1];
		}

		public void delete(int left, int right) {
			delete(1, 0, size-1, left, right);
		}

		public void delete(int index, int treeL, int treeR, int left, int right) {
			if(treeL > right || treeR < left) return;
			pushDown(index, treeL, treeR);
			if(treeL >= left && treeR <= right) {
				delete(index);
				return;
			}
			int treeM = (treeL+treeR)/2;
			delete(2*index, treeL, treeM, left, right);
			delete(2*index+1, treeM+1, treeR, left, right);
			pullUp(index, treeL, treeR);
		}

		public void addOne(int left, int right) {
			addOne(1, 0, size-1, left, right);
		}

		public void addOne(int index, int treeL, int treeR, int left, int right) {
			if(treeL > right || treeR < left) return;
			pushDown(index, treeL, treeR);
			if(treeL == treeR) {
				leaf[index]++;
				return;
			}
			if(treeL >= left && treeR <= right) {
				lazy[index]++;
				return;
			}
			int treeM = (treeL+treeR)/2;
			addOne(2*index, treeL, treeM, left, right);
			addOne(2*index+1, treeM+1, treeR, left, right);
			pullUp(index, treeL, treeR);
		}

		public int query(int left, int right) {
			return query(1, 0, size-1, left, right);
		}
		public int query(int index, int treeL, int treeR, int left, int right) {
			if(treeL > right || treeR < left) return 0;
			pushDown(index, treeL, treeR);
			if(leaf[index] == 0 && lazy[index] == 0) return 0;
			if(treeL == treeR) {
				return leaf[index];
			}
			if(treeL >= left && treeR <= right) {
				return leaf[index];
			}
			int treeM = (treeL+treeR)/2;
			int ret = 0;
			ret += query(2*index, treeL, treeM, left, right);
			ret += query(2*index+1, treeM+1, treeR, left, right);
			pullUp(index, treeL, treeR);
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