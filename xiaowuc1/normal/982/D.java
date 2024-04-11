import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

public class D {
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
			State[] l = new State[n];
			for(int i = 0; i < n; i++) {
				l[i] = new State(i, readInt());
			}
			Arrays.sort(l);
			int ret = -1;
			int loc = -1;
			include = new boolean[n];
			par = new int[n];
			sz = new int[n];
			for(int i = 0; i < n; i++) {
				par[i] = i;
			}
			Map<Integer, Integer> sizes = new HashMap<Integer, Integer>();
			int numComp = 0;
			for(State out: l) {
				numComp++;
				if(out.idx > 0 && include[out.idx-1]) {
					int old = find(out.idx-1);
					update(sizes, sz[old], -1);
					merge(out.idx, out.idx-1);
					numComp--;
				}
				if(out.idx + 1 < n && include[out.idx+1]) {
					int old = find(out.idx+1);
					update(sizes, sz[old], -1);
					merge(out.idx, out.idx+1);
					numComp--;
				}
				update(sizes, sz[find(out.idx)], 1);
				include[out.idx] = true;
				if(sizes.size() == 1 && numComp > loc) { 
					ret = out.h + 1;
					loc = numComp;
				}
			}
			pw.println(ret);
		}
		pw.close();
	}

	static boolean[] include;
	static int[] par;
	static int[] sz;
	public static int find(int x) {
		return par[x] == x ? x : (par[x] = find(par[x]));
	}
	public static void merge(int x, int y) {
		int fx = find(x);
		int fy = find(y);
		if(fx == fy) return;
		par[fx] = fy;
		sz[fy]++;
	}
	
	public static void update(Map<Integer, Integer> m, int k, int v) {
		m.put(k, m.getOrDefault(k, 0) + v);
		if(m.get(k) == 0) {
			m.remove(k);
		}
	}
	
	static class State implements Comparable<State> {
		public int idx;
		public int h;
		public State(int idx, int h) {
			super();
			this.idx = idx;
			this.h = h;
		}
		public int compareTo(State s) {
			return h - s.h;
		}
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