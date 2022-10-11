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
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++) {
			int n = readInt();
			int qqq = readInt();
			int[] list = new int[n];
			for(int i = 0; i < n; i++) {
				list[i] = readInt();
			}
			RangeTree tree = new RangeTree(list);
			list = null;
			while(qqq-- > 0) {
				int type = readInt();
				if(type == 1) {
					int l = readInt()-1;
					int r = readInt()-1;
					pw.println(tree.query(l, r));
				}
				else if(type == 2) {
					int l = readInt()-1;
					int r = readInt()-1;
					int x = readInt();
					tree.mod(l, r, x);
				}
				else if(type == 3) {
					int index = readInt()-1;
					int next = readInt();
					tree.update(index, next);
				}
			}
		}
		exitImmediately();
	}

	static class RangeTree {
		public long[] sum;
		public long[] max;
		public int size;
		public RangeTree(int[] list) {
			size = list.length;
			sum = new long[4*list.length];
			max = new long[4*list.length];
			init(1, 0, list.length-1, list);
		}
		public void init(int index, int left, int right, int[] list) {
			if(left == right) {
				sum[index] = max[index] = list[left];
			}
			else {
				int mid = (left+right)/2;
				init(2*index, left, mid, list);
				init(2*index+1, mid+1, right, list);
				sum[index] = sum[2*index] + sum[2*index+1];
				max[index] = Math.max(max[2*index], max[2*index+1]);
			}
		}
		public void update(int index, int val) {
			update(1, 0, size-1, index, val);
		}
		public void update(int index, int left, int right, int up, int val) {
			if(up < left || up > right) return;
			if(left == right) {
				sum[index] = max[index] = val;
			}
			else {
				int mid = (left+right)/2;
				update(2*index, left, mid, up, val);
				update(2*index+1, mid+1, right, up, val);
				sum[index] = sum[2*index] + sum[2*index+1];
				max[index] = Math.max(max[2*index], max[2*index+1]);
			}
		}
		public void mod(int left, int right, int mod) {
			mod(1, 0, size-1, left, right, mod);
		}
		public void mod(int index, int left, int right, int actualL, int actualR, int mod) {
			if(right < actualL || left > actualR) return;
			if(max[index] < mod) return;
			if(left == right) {
				max[index] %= mod;
				sum[index] %= mod;
			}
			else {
				int mid = (left+right)/2;
				mod(2*index, left, mid, actualL, actualR, mod);
				mod(2*index+1, mid+1, right, actualL, actualR, mod);
				sum[index] = sum[2*index] + sum[2*index+1];
				max[index] = Math.max(max[2*index], max[2*index+1]);
			}
		}
		public long query(int left, int right) {
			return query(1, 0, size-1, left, right); 
		}
		public long query(int index, int left, int right, int actualL, int actualR) {
			if(right < actualL || left > actualR) return 0;
			if(left >= actualL && right <= actualR) {
				return sum[index];
			}
			else {
				int mid = (left+right)/2;
				long ret = 0;
				ret += query(2*index, left, mid, actualL, actualR);
				ret += query(2*index+1, mid+1, right, actualL, actualR);
				return ret;
			}
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