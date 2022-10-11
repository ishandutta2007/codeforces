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
			int m = readInt();
			LinkedList<Edge>[] edges = new LinkedList[n];
			for(int i = 0; i < n; i++) {
				edges[i] = new LinkedList<Edge>();
			}
			while(m-- > 0) {
				int a = readInt()-1;
				int b = readInt()-1;
				edges[a].add(new Edge(b, true));
				edges[b].add(new Edge(a, false));
			}
			boolean[] seen = new boolean[n];
			int ret = 0;
			for(int i = 0; i < n; i++) {
				if(seen[i] || edges[i].isEmpty()) continue;
				LinkedList<Integer> q = new LinkedList<Integer>();
				Map<Integer, Integer> p = new HashMap<Integer, Integer>();
				q.add(i);
				seen[i] = true;
				p.put(i, 0);
				while(!q.isEmpty()) {
					int curr = q.removeFirst();
					for(Edge out: edges[curr]) {
						if(!p.containsKey(out.to)) {
							p.put(out.to, 0);
						}
						if(out.real) {
							p.put(out.to, p.get(out.to) + 1);
						}
						if(!seen[out.to]) {
							seen[out.to] = true;
							q.add(out.to);
						}
					}
				}
				int add = 0;
				for(int out: p.keySet()) {
					if(p.get(out) == 0) {
						q.add(out);
					}
				}
				while(!q.isEmpty()) {
					int curr = q.removeFirst();
					add++;
					for(Edge out: edges[curr]) {
						if(out.real) {
							int next = p.get(out.to) - 1;
							if(next == 0) {
								q.add(out.to);
							}
							p.put(out.to, next);
						}
					}
				}
				if(add == p.size()) {
					ret += p.size()-1;
				}
				else {
					ret += p.size();
				}
			}
			pw.println(ret);
		}
		exitImmediately();
	}

	static class Edge {
		public int to;
		public boolean real;
		public Edge(int to, boolean real) {
			super();
			this.to = to;
			this.real = real;
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