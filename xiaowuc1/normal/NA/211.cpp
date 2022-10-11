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
			int m = readInt();
			int k = readInt();
			LinkedList<Edge>[] edges = new LinkedList[n];
			for(int i = 0; i < n; i++) {
				edges[i] = new LinkedList<>();
			}
			while(m-- > 0) {
				int a = readInt()-1;
				int b = readInt()-1;
				int w = readInt();
				edges[a].add(new Edge(a, b, w));
				edges[b].add(new Edge(b, a, w));
			}
			Edge[] direct = new Edge[k];
			for(int i = 0; i < k; i++) {
				direct[i] = new Edge(0, readInt()-1, readInt());
			}
			Arrays.sort(direct);
			int ret = 0;
			int lastEdge = 0;
			long[] dp = new long[n];
			Arrays.fill(dp, 1L << 60);
			dp[0] = 0;
			PriorityQueue<Vertex> q = new PriorityQueue<Vertex>();
			q.add(new Vertex(0, 0));
			while(lastEdge < direct.length || !q.isEmpty()) {
				while(!q.isEmpty()) {
					while(lastEdge < direct.length && direct[lastEdge].w <= q.peek().w) {
						if(direct[lastEdge].w < dp[direct[lastEdge].to]) {
							dp[direct[lastEdge].to] = direct[lastEdge].w;
							q.add(new Vertex(direct[lastEdge].to, dp[direct[lastEdge].to]));
						}
						else {
							ret++;
						}
						lastEdge++;
					}
					Vertex curr = q.poll();
					if(dp[curr.v] != curr.w) continue;
					for(Edge out: edges[curr.v]) {
						if(dp[out.to] > curr.w + out.w) {
							dp[out.to] = curr.w + out.w;
							q.add(new Vertex(out.to, dp[out.to]));
						}
					}
				}
				if(lastEdge < direct.length) {
					if(direct[lastEdge].w < dp[direct[lastEdge].to]) {
						dp[direct[lastEdge].to] = direct[lastEdge].w;
						q.add(new Vertex(direct[lastEdge].to, dp[direct[lastEdge].to]));
					}
					else {
						ret++;
					}
				}
				lastEdge++;
			}
			pw.println(ret);
		}
		exitImmediately();
	}

	static class Vertex implements Comparable<Vertex> {
		public int v;
		public long w;
		public Vertex(int v, long w) {
			super();
			this.v = v;
			this.w = w;
		}
		public int compareTo(Vertex curr) {
			return Long.compare(w, curr.w);
		}
	}

	static class Edge implements Comparable<Edge> {
		public int from, to, w;

		public Edge(int a, int b, int w) {
			super();
			this.from = a;
			this.to = b;
			this.w = w;
		}
		public int compareTo(Edge e) {
			return w - e.w;
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