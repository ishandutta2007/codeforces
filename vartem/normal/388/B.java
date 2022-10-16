import java.io.*;
import java.util.*;

public class BOK {
	
	List<List<Integer>> graph;
	
	int addV() {
		int v = graph.size();
		graph.add(new ArrayList<Integer>());
		return v;
	}
	
	void addEdge(int from, int to) {
		graph.get(from).add(to);
		graph.get(to).add(from);
	}
	
	public void solve(int initK) {
		int k = initK;
		if (k == 1) {
			out.println(2);
			out.println("NY");
			out.println("YN");
			return;
		}
		graph = new ArrayList<>();
		graph.add(new ArrayList<Integer>());
		graph.add(new ArrayList<Integer>());
		
		int len = 0;
		int last = 0;
		int bit = 31 - Integer.numberOfLeadingZeros(k);
		for (int b = bit - 1; b >= 0; b--) {
			int v1 = addV(), v2 = addV(), v3 = addV();
			len += 2;

			addEdge(last, v1);
			addEdge(last, v2);
			addEdge(v2, v3);
			addEdge(v1, v3);

			if ((k & (1 << b)) != 0) {
				int tmp = 0;
				for (int i = 0; i < len - 1; i++) {
					int newV = addV();
					addEdge(tmp, newV);
					tmp = newV;
				}
				addEdge(tmp, v3);
			}

			last = v3;
		}
		addEdge(last, 1);
		int n = graph.size();

		boolean[][] a = new boolean[n][n];
		for (int i = 0; i < n; i++) {
			for (int j : graph.get(i)) {
				a[i][j] = true;
			}
		}
		out.println(n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				out.print(a[i][j] ? 'Y' : "N");
			}
			out.println();
		}
	}
	
	public int solve(boolean[][] a) {
		int n = a.length;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) {
					if (a[i][j]) {
						return -1;
					}
				} else {
					if (a[i][j] != a[j][i]) {
						return -1;
					}
				}
			}
		}
		int[] count = new int[n];
		int[] dist = new int[n];
		Arrays.fill(dist, Integer.MAX_VALUE / 2);
		dist[0] = 0;
		count[0] = 1;
		Queue<Integer> q = new ArrayDeque<>();
		q.add(0);
		while (!q.isEmpty()) {
			int i = q.poll();
			for (int j = 0; j < n; j++) {
				if (a[i][j]) {
					if (dist[j] > dist[i] + 1) {
						dist[j] = dist[i] + 1;
						count[j] = count[i];
						q.add(j);
					} else if (dist[j] == dist[i] + 1) {
						count[j] += count[i];
					}
				}
			}
		}
		return count[1];
	}

	FastScanner in;
	PrintWriter out;

	public void run() {
		try {
			in = new FastScanner();
			out = new PrintWriter(System.out);
			solve(in.nextInt());
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

		public FastScanner(String name) {
			try {
				br = new BufferedReader(new FileReader(name));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		public String nextToken() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(nextToken());
		}

		public long nextLong() {
			return Long.parseLong(nextToken());
		}

		public double nextDouble() {
			return Double.parseDouble(nextToken());
		}
	}

	public static void main(String[] args) {
		new BOK().run();
	}
}