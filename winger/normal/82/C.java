
import java.io.*;
import java.util.*;

public class Solution implements Runnable {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;
	private ArrayList<Edge>[] edges;
	private int[] p;
	private int[] c;

	static class Edge {
		int u, v, c;
		
		Edge(int u, int v, int c) {
			this.u = u;
			this.v = v;
			this.c = c;
		}
	}

	public void solve() throws IOException {
		int n = nextInt();
		final int[] a = new int[n];
		edges = new ArrayList[n];
		for (int i = 0; i < n; ++i) {
			edges[i] = new ArrayList<Edge>();
			a[i] = nextInt();
		}
		for (int i = 0; i < n - 1; ++i) {
			int u = nextInt() - 1;
			int v = nextInt() - 1;
			int c = nextInt();
			edges[u].add(new Edge(u, v, c));
			edges[v].add(new Edge(v, u, c));
		}
		p = new int[n];
		c = new int[n];
		p[0] = -1;
		dfs(0, null);
		Integer[] ind = new Integer[n];
		int[] pos = new int[n];
		for (int i = 0; i < n; ++i) {
			ind[i] = pos[i] = i;
		}
		Arrays.sort(ind, new Comparator<Integer>(){
			public int compare(Integer o1, Integer o2) {
				return a[o1] - a[o2];
			}
		});
		int[] ans = new int[n];
		while (true) {
			boolean ok = true;
			int[] cap = c.clone();
			for (int i : ind) {
				if (pos[i] != 0) {
					ans[i]++;
					if (cap[pos[i]] > 0) {
						cap[pos[i]]--;
						pos[i] = p[pos[i]];
					}
					ok = false;
				}
			}
			if (ok) {
				break;
			}
		}
		for (int i : ans) {
			out.print(i + " ");
		}
		out.println();
	}

	private void dfs(int i, Edge e) {
		if (e != null) {
			p[i] = e.u;
			c[i] = e.c;
		}
		for (Edge e1 : edges[i]) {
			if (e == null || e1.v != e.u) {
				dfs(e1.v, e1);
			}
		}
	}

	public void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			eat("");
			
			solve();
			
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			failed = true;
		}
	}
	
	void eat(String s) {
		st = new StringTokenizer(s);
	}
	
	String next() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null) {
				return null;
			}
			eat(line);
		}
		return st.nextToken();
	}
	
	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	
	long nextLong() throws IOException {
		return Long.parseLong(next());
	}
	
	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}
	
	static boolean failed = false;
	
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		Thread th = new Thread(new Solution());
		th.start();
		try {
			th.join();
		} catch (InterruptedException iex) {
		}
		if (failed) {
			throw new RuntimeException();
		}
	}
	
}