import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.security.*;
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

	public static void main(String[] args) throws Exception {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			int qqq = readInt();
			RangeTree tree = new RangeTree(n);
			int[] list = new int[n];
			LinkedList<Integer>[] edges = new LinkedList[n];
			for(int i = 0; i < n; i++) {
				list[i] = readInt();
				edges[i] = new LinkedList<Integer>();
			}
			for(int a = 0; a < n-1; a++) {
				int x = readInt()-1;
				int y = readInt()-1;
				edges[x].add(y);
				edges[y].add(x);
			}
			ArrayList<Integer> even = new ArrayList<Integer>();
			ArrayList<Integer> odd = new ArrayList<Integer>();
			int[] d = new int[n];
			Arrays.fill(d, 1 << 25);
			d[0] = 0;
			LinkedList<Integer> q = new LinkedList<Integer>();
			LinkedList<Integer> rev = new LinkedList<Integer>();
			q.add(0);
			while(!q.isEmpty()) {
				int curr = q.removeFirst();
				rev.addFirst(curr);
				if(d[curr]%2 == 0) {
					even.add(curr);
				}
				else {
					odd.add(curr);
				}
				for(int out: edges[curr]) {
					if(d[out] == 1 << 25) {
						d[out] = 1 + d[curr];
						q.addFirst(out);
					}
				}
			}
			int[] sameLow = new int[n];
			int[] sameHigh = new int[n];
			int[] otherLow = new int[n];
			int[] otherHigh = new int[n];
			Arrays.fill(otherLow, Integer.MAX_VALUE);
			Arrays.fill(otherHigh, -1);
			int index = 0;
			int[] from = new int[n];
			for(int out: even) {
				sameLow[out] = index;
				sameHigh[out] = index;
				from[out] = index++; 
			}
			for(int out: odd) {
				sameLow[out] = index;
				sameHigh[out] = index;
				from[out] = index++;
			}
			for(int i = 0; i < n; i++) {
				tree.update(from[i], from[i], list[i]);
			}
			while(!rev.isEmpty()) {
				int curr = rev.removeFirst();
				for(int out: edges[curr]) {
					if(d[out] < d[curr]) continue;
					sameLow[curr] = Math.min(sameLow[curr], otherLow[out]);
					sameHigh[curr] = Math.max(sameHigh[curr], otherHigh[out]);
					
					otherLow[curr] = Math.min(otherLow[curr], sameLow[out]);
					otherHigh[curr] = Math.max(otherHigh[curr], sameHigh[out]);
				}
			}
			while(qqq-- > 0) {
				int type = readInt();
				if(type == 1) {
					int node = readInt()-1;
					int scale = readInt();
					tree.update(sameLow[node], sameHigh[node], scale);
					if(otherHigh[node] >= 0) {
						tree.update(otherLow[node], otherHigh[node], -scale);
					}
				}
				else {
					int node = readInt()-1;
					node = from[node];
					pw.println(tree.query(node));
				}
			}
		}
		exitImmediately();
	}

	static class RangeTree {
		public long[] leaf;
		public long[] lazy;
		public int size;
		public RangeTree(int s) {
			size = s;
			leaf = new long[4*size];
			lazy = new long[4*size];
		}
		public void update(int l, int r, long d) {
			update(1, 0, size-1, l, r, d);
		}
		private void pushDown(int index, int left, int right) {
			if(left == right) return;
			lazy[2*index] += lazy[index];
			lazy[2*index+1] += lazy[index];
			lazy[index] = 0;
		}
		private void pullUp(int index, int left, int right) {
			if(lazy[index] != 0) throw new RuntimeException("NO");
			int mid = (left+right)/2;
			leaf[index] = score(2*index, left, mid) + score(2*index+1, mid+1, right);
		}
		private long score(int index, int l, int r) {
			return leaf[index] + (r-l+1) * lazy[index];
		}
		private void update(int index, int l, int r, int left, int right, long d) {
			if(r < left || l > right) return;
			if(l >= left && r <= right) {
				lazy[index] += d;
				return;
			}
			pushDown(index, l, r);
			int m = (l+r)/2;
			update(2*index, l, m, left, right, d);
			update(2*index+1, m+1, r, left, right, d);
			pullUp(index, l, r);
		}
		public long query(int index) {
			return query(1, 0, size-1, index);
		}
		public long query(int index, int l, int r, int i) {
			if(i < l || i > r) return 0;
			if(l == r) {
				return leaf[index] + lazy[index];
			}
			pushDown(index, l, r);
			int m = (l+r)/2;
			long ret = 0;
			ret += query(2*index, l, m, i);
			ret += query(2*index+1, m+1, r, i);
			pullUp(index, l, r);
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