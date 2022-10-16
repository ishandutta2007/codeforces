import java.io.*;
import java.util.*;

public class B {

	final String filename = new String("B").toLowerCase();

	void solve() throws Exception {
		int n = nextInt();
		int m = nextInt();
		char[][] field = new char[n][m];
		for (int i = 0; i < n; i++) {
			field[i] = nextToken().toCharArray();
		}

		int inf = Integer.MAX_VALUE / 2;
		int[] dist = new int[n + m];
		Arrays.fill(dist, inf);
		dist[0] = 0;
		Queue<Integer> q = new ArrayDeque<Integer>();
		q.add(0);
		while (!q.isEmpty()) {
			int cur = q.poll();
			if (cur == n - 1) {
				out.println(dist[cur]);
				return;
			}
			if (cur < n) {
				for (int j = 0; j < m; j++) {
					if (field[cur][j] == '#') {
						if (dist[n + j] == inf) {
							dist[n + j] = dist[cur] + 1;
							q.add(n + j);
						}
					}
				}
			} else {
				int col = cur - n;
				for (int i = 0; i < n; i++) {
					if (field[i][col] == '#') {
						if (dist[i] == inf) {
							dist[i] = dist[cur] + 1;
							q.add(i);
						}
					}
				}
			}
		}
		out.println(-1);
	}

	void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			// in = new BufferedReader(new FileReader("input.txt"));
			// out = new PrintWriter("output.txt");

			solve();

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