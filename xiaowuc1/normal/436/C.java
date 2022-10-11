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
			int r = readInt();
			int c = readInt();
			int n = readInt();
			int w = readInt();
			char[][][] grids = new char[n][r][c];
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < r; j++) {
					String s = nextToken();
					for(int k = 0; k < c; k++) {
						grids[i][j][k] = s.charAt(k);
					}
				}
			}
			PriorityQueue<KruskalEdge> q = new PriorityQueue<KruskalEdge>();
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < i; j++) {
					int diff = 0;
					for(int k = 0; k < r; k++) {
						for(int l = 0; l < c; l++) {
							if(grids[i][k][l] != grids[j][k][l]) {
								diff++;
							}
						}
					}
					if(diff * w < r*c) {
						q.add(new KruskalEdge(i, j, diff * w));
					}
				}
			}
			parent = new int[n];
			for(int i = 0; i < n; i++) {
				parent[i] = i;
			}
			int ret = (n)*r*c;
			LinkedList<Integer>[] ans = new LinkedList[n];
			for(int i = 0; i < n; i++) {
				ans[i] = new LinkedList<Integer>();
			}
			while(!q.isEmpty()) {
				KruskalEdge curr = q.poll();
				if(find(curr.v) != find(curr.u)) {
					merge(curr.u, curr.v);
					ret -= (r*c - curr.amt);
					ans[curr.u].add(curr.v);
					ans[curr.v].add(curr.u);
				}
			}
			pw.println(ret);
			boolean[] seen = new boolean[n];
			for(int i = 0; i < n; i++) {
				if(seen[i]) continue;
				seen[i] = true;
				pw.println((i+1) + " 0");
				LinkedList<Integer> qqq = new LinkedList<Integer>();
				qqq.add(i);
				while(!qqq.isEmpty()) {
					int curr = qqq.removeFirst();
					for(int out: ans[curr]) {
						if(seen[out]) continue;
						pw.println((out+1) + " " + (curr+1));
						seen[out] = true;
						qqq.add(out);
					}
				}
			}
		}
		exitImmediately();
	}

	static int[] parent;
	public static int find(int x) {
		if(parent[x] == x) return x;
		parent[x] = find(parent[x]);
		return parent[x];
	}

	public static void merge(int x, int y) {
		parent[find(x)] = find(y);
	}

	static class KruskalEdge implements Comparable<KruskalEdge> {
		public int u,v;
		public int amt;
		public KruskalEdge(int a, int b, int c) {
			u=a;
			v=b;
			amt=c;
		}
		public int compareTo(KruskalEdge k) {
			return amt - k.amt;
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