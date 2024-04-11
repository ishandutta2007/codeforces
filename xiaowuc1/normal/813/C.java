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
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			int loc = readInt()-1;
			edges = new LinkedList[n];
			for(int i = 0; i < n; i++) {
				edges[i] = new LinkedList<>();
			}
			for(int i = 1; i < n; i++) {
				int a = readInt()-1;
				int b = readInt()-1;
				edges[a].add(b);
				edges[b].add(a);
			}
			genLCA();
			int ret = 2;
			for(int i = 0; i < n; i++) {
				int connect = getLCA(i, loc);
				if(getDist(loc, connect) < getDist(0, connect)) {
					ret = Math.max(ret, 2 * getDist(0, i));
				}
			}
			pw.println(ret);
		}
		exitImmediately();
	}

	static int[][] lca;
	static final int LCA_DEPTH = 18;
	static LinkedList<Integer>[] edges;
	static int[] depth;
	
	public static int getDist(int a, int b) {
		int d = getLCA(a, b);
		return depth[a] + depth[b] - 2 * depth[d];
	}
	
	public static int getLCA(int a, int b) {
		for(int d = LCA_DEPTH-1; d >= 0; d--) {
			if(depth[a] - (1<<d) >= depth[b]) {
				a = lca[d][a];
			}
			if(depth[b] - (1<<d) >= depth[a]) {
				b = lca[d][b];
			}
		}
		for(int d = LCA_DEPTH-1; d >= 0; d--) {
			if(lca[d][a] != lca[d][b]) {
				a = lca[d][a];
				b = lca[d][b];
			}
		}
		while(a != b) {
			a = lca[0][a];
			b = lca[0][b];
		}
		return a;
	}
	
	public static void genLCA() {
		boolean[] seen = new boolean[edges.length];
		seen[0] = true;
		LinkedList<Integer> q = new LinkedList<>();
		q.add(0);
		lca = new int[LCA_DEPTH][edges.length];
		depth = new int[edges.length];
		while(!q.isEmpty()) {
			int curr = q.removeFirst();
			for(int out: edges[curr]) {
				if(!seen[out]) {
					seen[out] = true;
					depth[out] = depth[curr] + 1;
					lca[0][out] = curr;
					q.add(out);
				}
			}
		}
		for(int d = 1; d < LCA_DEPTH; d++) {
			for(int i = 0; i < edges.length; i++) {
				lca[d][i] = lca[d-1][lca[d-1][i]];
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
		String s = br.readLine();
		if(s == null) {
			exitImmediately();
		}
		st = null;
		return s;
	}

	private static String nextToken() throws IOException  {
		while(st == null || !st.hasMoreTokens())  {
			st = new StringTokenizer(nextLine().trim());
		}
		return st.nextToken();
	}
}