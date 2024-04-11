import java.io.*;
import java.util.*;

public class D {

	FastScanner in;
	PrintWriter out;
	final String fileName = "D".toLowerCase();

	class DSU {
		int[] rank, parent;
		int comps;

		public DSU(int n) {
			rank = new int[n];
			parent = new int[n];
			for (int i = 0; i < n; i++) {
				parent[i] = i;
			}
			comps = n;
		}
		
		
		public DSU(DSU other) {
			this.rank = other.rank.clone();
			this.parent = other.parent.clone();
			this.comps = other.comps;
		}
		
		int get(int v) {
			if (v == parent[v]) {
				return v;
			}
			return parent[v] = get(parent[v]);
		}
		
		void union(int a, int b) {
			a = get(a);
			b = get(b);
			if (a == b) {
				return;
			}
			comps--;
			
			if (rank[a] == rank[b]) {
				rank[a]++;
			}
			
			if (rank[a] > rank[b]) {
				parent[b] = a;
			} else {
				parent[a] = b;
			}
		}
	}
	
	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		
		int[] x = new int[m], y = new int[m];
		
		for (int i = 0; i < m; i++) {
			x[i] = in.nextInt() - 1;
			y[i] = in.nextInt() - 1;
		}
		
		DSU[] pref = new DSU[m + 1], suf = new DSU[m + 1];
		
		pref[0] = new DSU(n);
		for (int i = 1; i <= m; i++) {
			pref[i] = new DSU(pref[i - 1]);
			pref[i].union(x[i - 1], y[i - 1]);
		}
		
		suf[m] = new DSU(n);
		for (int i = m - 1; i >= 0; i--) {
			suf[i] = new DSU(suf[i + 1]);
			suf[i].union(x[i], y[i]);
		}

		
		int k = in.nextInt();
		for (int i = 0; i < k; i++) {
			int l = in.nextInt();
			int r = in.nextInt();
			DSU dsu = new DSU(pref[l - 1]);
			DSU dsu2 = suf[r];
			
			for (int j = 0; j < n; j++) {
				int from = j;
				int to = dsu2.get(from);
				dsu.union(from, to);
			}
			
			out.println(dsu.comps);
		}
	}

	void run() {
		try {
			in = new FastScanner();
			out = new PrintWriter(System.out);
			solve();
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		String next() {
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
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}

	public static void main(String[] args) {
		new D().run();
	}
}