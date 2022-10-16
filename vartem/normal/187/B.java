import java.io.*;
import java.util.*;

public class B {

	final String filename = new String("B").toLowerCase();

	class Query implements Comparable<Query> {
		int from, to;
		int k;
		int id;

		public Query(int from, int to, int k, int id) {
			this.from = from;
			this.to = to;
			this.k = k;
			this.id = id;
		}

		@Override
		public int compareTo(Query o) {
			return k - o.k;
		}
	}

	int n, m;
	final int inf = Integer.MAX_VALUE / 2;

	void update(int[][] curDist, int[][] fastest) {
		int[][] newCurDist = new int[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				newCurDist[i][j] = curDist[i][j];
				for (int k = 0; k < n; k++) {
					newCurDist[i][j] = Math.min(newCurDist[i][j], curDist[i][k]
							+ fastest[k][j]);
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				curDist[i][j] = newCurDist[i][j];
			}
		}
	}

	void solve() throws Exception {
		n = nextInt();
		m = nextInt();
		int r = nextInt();
		int[][][] dist = new int[m][n][n];
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					dist[i][j][k] = nextInt();
				}
			}
		}

		for (int IT = 0; IT < m; IT++) {
			int[][] a = dist[IT];
			for (int k = 0; k < n; k++) {
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						a[i][j] = Math.min(a[i][j], a[i][k] + a[k][j]);
					}
				}
			}
		}
		int[][] fastest = new int[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				fastest[i][j] = inf;
				for (int c = 0; c < m; c++) {
					fastest[i][j] = Math.min(fastest[i][j], dist[c][i][j]);
				}
			}
		}

		int[][] curDist = new int[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				curDist[i][j] = fastest[i][j];
			}
		}

		int curK = 0;
		Query[] qs = new Query[r];
		for (int i = 0; i < r; i++) {
			qs[i] = new Query(nextInt() - 1, nextInt() - 1, Math.min(nextInt(),
					100), i);
		}
		Arrays.sort(qs);
		int[] ans = new int[r];
		for (Query q : qs) {
			while (curK < q.k) {
				update(curDist, fastest);
				curK++;
			}
			ans[q.id] = curDist[q.from][q.to];
		}
		for (int i : ans) {
			 out.println(i);
		}
	}

	void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			// in = new BufferedReader(new FileReader("output.txt"));
			// out = new PrintWriter("output.txt");
			long time = System.currentTimeMillis();
			solve();
			System.err.println(System.currentTimeMillis() - time);

			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	BufferedReader in;
	StringTokenizer st;
	PrintWriter out;

	String nextToken() throws Exception {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}

	int nextInt() throws Exception {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws Exception {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws Exception {
		return Double.parseDouble(nextToken());
	}

	public static void main(String[] args) {
		new B().run();
	}

}