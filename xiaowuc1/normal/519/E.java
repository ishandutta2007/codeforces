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

	static int[] dist;
	static int[][] parent;
	static int[] inTree;

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++) {
			int n = readInt();
			LinkedList<Integer>[] edges = new LinkedList[n];
			for(int i = 0; i < n; i++) {
				edges[i] = new LinkedList<Integer>();
			}
			for(int x = 1; x < n; x++) {
				int a = readInt()-1;
				int b = readInt()-1;
				edges[a].add(b);
				edges[b].add(a);
			}
			dist = new int[n];
			parent = new int[n][17]; 
			inTree = new int[n];
			Arrays.fill(inTree, 1);
			Arrays.fill(dist, 1 << 30);
			dist[0] = 0;
			LinkedList<Integer> q = new LinkedList<Integer>();
			q.add(0);
			parent[0][0] = -1;
			Stack<Integer> temp = new Stack<Integer>();
			while(!q.isEmpty()) {
				int curr = q.removeFirst();
				temp.push(curr);
				for(int out: edges[curr]) {
					if(dist[out] == 1 << 30) {
						parent[out][0] = curr;
						dist[out] = 1 + dist[curr];
						q.add(out);
					}
				}
			}
			while(!temp.isEmpty()) {
				int curr = temp.pop();
				if(curr != 0) {
					inTree[parent[curr][0]] += inTree[curr];
				}
			}
			for(int level = 1; level < 17; level++) {
				for(int i = 0; i < n; i++) {
					int test = parent[i][level-1];
					if(test == -1) {
						parent[i][level] = -1;
					}
					else {
						parent[i][level] = parent[test][level-1];
					}
				}
			}
			int qqq = readInt();
			while(qqq-- > 0) {
				pw.println(solve(readInt()-1, readInt()-1));
			}
		}
		exitImmediately();
	}

	public static int lca(int a, int b) {
		if(dist[a] > dist[b]) return lca(b, a);
		for(int k = 16; k >= 0; k--) {
			while(dist[b] - (1<<k) >= dist[a]) {
				b = parent[b][k];
			}
		}
		for(int k = 16; k > 0; k--) {
			while(parent[a][k] != parent[b][k]) {
				a = parent[a][k];
				b = parent[b][k];
			}
		}
		while(a != b) {
			a = parent[a][0];
			b = parent[b][0];
		}
		return a;
	}

	public static int wantParent(int p, int d) {
		for(int k = 16; k >= 0; k--) {
			while(dist[p] - (1 << k) >= d) {
				p = parent[p][k];
			}
		}
		return p;
	}
	
	public static int solve(int a, int b) {
		if(a == b) return dist.length;
		if(dist[a]%2 != dist[b]%2) return 0;
		if(dist[a] > dist[b]) {
			return solve(b, a);
		}
		int lca = lca(a, b);
		if(dist[a] == dist[b]) {
			return dist.length - inTree[wantParent(a, dist[lca]+1)] - inTree[wantParent(b, dist[lca]+1)];
		}
		int avg = (dist[a] + dist[b] - 2 * dist[lca]) / 2;
		int x = wantParent(b, dist[b] - avg);
		int y = wantParent(b, dist[b] - avg+1);
		return inTree[x] - inTree[y];
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