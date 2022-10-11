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
			int[][] grid = new int[n][n];
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					grid[i][j] = readInt();
				}
			}
			boolean bad = false;
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					if(grid[i][j] != grid[j][i]) {
						bad = true;
					}
				}
			}
			if(bad) {
				pw.println("NO");
				continue;
			}
			ArrayList<KruskalEdge> edgeList = new ArrayList<KruskalEdge>();
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < i; j++) {
					if(grid[i][j] == 0) continue;
					edgeList.add(new KruskalEdge(i, j, grid[i][j]));
				}
			}
			Collections.sort(edgeList);
			LinkedList<Edge>[] edges = new LinkedList[n];
			parent = new int[n];
			for(int i = 0; i < n; i++) {
				edges[i] = new LinkedList<Edge>();
				parent[i] = i;
			}
			int add = 0;
			for(KruskalEdge out: edgeList) {
				if(find(out.a) == find(out.b)) continue;
				add++;
				edges[out.a].add(new Edge(out.b, out.w));
				edges[out.b].add(new Edge(out.a, out.w));
				merge(out.a, out.b);
				if(add == n-1) break;
			}
			if(add != n-1) {
				pw.println("NO");
				continue;
			}
			for(int i = 0; !bad && i < n; i++) {
				int[] dist = new int[n];
				Arrays.fill(dist, 1 << 30);
				dist[i] = 0;
				LinkedList<Integer> q = new LinkedList<Integer>();
				q.add(i);
				while(!q.isEmpty()) {
					int curr = q.removeFirst();
					if(dist[curr] != grid[i][curr]) {
						bad = true;
						break;
					}
					for(Edge out: edges[curr]) {
						if(dist[out.d] == 1 << 30) {
							dist[out.d] = dist[curr] + out.w;
							q.add(out.d);
						}
					}
				}
			}
			pw.println(bad ? "NO" : "YES");
		}
		exitImmediately();
	}
	
	static class Edge {
		public int d,w;
		public Edge(int a, int b) {
			d=a;
			w=b;
		}
	}
	
	static class KruskalEdge implements Comparable<KruskalEdge> {
		public int a,b,w;
		public KruskalEdge(int x, int y, int z) {
			a=x;
			b=y;
			w=z;
		}
		public int compareTo(KruskalEdge e) {
			return w - e.w;
		}
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