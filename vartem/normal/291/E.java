import java.io.*;
import java.util.*;

public class E {

	FastScanner in;
	PrintWriter out;

	class Edge {
		int to;
		String t;

		public Edge(int to, String t) {
			super();
			this.to = to;
			this.t = t;
		}
	}

	List<Edge>[] graph;
	final int ALPH = 26;

	void solve() {
		int n = in.nextInt();
		graph = new List[n];
		for (int i = 0; i < n; i++) {
			graph[i] = new ArrayList<>();
		}

		for (int i = 1; i < n; i++) {
			int parent = in.nextInt() - 1;
			graph[parent].add(new Edge(i, in.nextToken()));
		}

		String t = in.nextToken();
		int[][] next = getNext(t);
		
		dfs(0, next, 0);
		out.println(ans);
	}
	
	private void dfs(int v, int[][] next, int pos) {
		for (Edge e : graph[v]) {
			int state = pos;
			String s = e.t;
			for (int i = 0; i < s.length(); i++) {
				state = next[s.charAt(i) - 'a'][state];
				if (state == pref.length) {
					ans++;
					state = pref[state - 1];
				}
			}
			dfs(e.to, next, state);
		}
	}

	int ans = 0;
	int[] pref;

	private int[][] getNext(String t) {
		int n = t.length();
		pref = new int[n];
		for (int i = 1; i < n; i++) {
			int k = pref[i - 1];
			while (k > 0 && t.charAt(i) != t.charAt(k)) {
				k = pref[k - 1];
			}
			if (t.charAt(i) == t.charAt(k)) {
				k++;
			}
			pref[i] = k;
		}

		int[][] next = new int[ALPH][n];

		for (int newC = 0; newC < ALPH; newC++) {
			char c = (char) ('a' + newC);
			for (int i = 0; i < n; i++) {
				if (i == 0){ 
					if (t.charAt(0) == c) {
						next[newC][i] = 1;
					} else {
						next[newC][i] = 0;
					}
					continue;
				}
				
				if (t.charAt(i) == c) {
					next[newC][i] = i + 1;
				} else {
					next[newC][i] = next[newC][pref[i - 1]];
				}
			}
		}
		return next;
	}

	void run() {
		in = new FastScanner();
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		String nextToken() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(nextToken());
		}

		long nextLong() {
			return Long.parseLong(nextToken());
		}

		double nextDouble() {
			return Double.parseDouble(nextToken());
		}
	}

	public static void main(String[] args) {
		new E().run();
	}
}