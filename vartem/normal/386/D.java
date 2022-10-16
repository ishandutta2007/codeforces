import java.io.*;
import java.util.*;

public class D {

	public void solve() {
		int n = in.nextInt();
		int[] a = new int[] { in.nextInt() - 1, in.nextInt() - 1, in.nextInt() - 1 };
		Arrays.sort(a);
		char[][] color = new char[n][];
		for (int i = 0; i < n; i++) {
			color[i] = in.nextToken().toCharArray();
		}

		int[] q = new int[3 * n * n * n];
		int[][][] dist = new int[n][n][n];
		int[][][] ch1 = new int[n][n][n], ch2 = new int[n][n][n];
		final int INF = Integer.MAX_VALUE / 2;
		for (int[][] i : dist) {
			for (int[] j : i) {
				Arrays.fill(j, INF);
			}
		}

		int head = 0, tail = 0;
		dist[a[0]][a[1]][a[2]] = 0;
		q[tail++] = a[0];
		q[tail++] = a[1];
		q[tail++] = a[2];

		int[] b = new int[3];
		int[] c = new int[3];
		while (head < tail) {
			a[0] = q[head++];
			a[1] = q[head++];
			a[2] = q[head++];
			int curDist = dist[a[0]][a[1]][a[2]];
			if (a[0] == 0 && a[1] == 1 && a[2] == 2) {
				out.println(curDist);
				c = a.clone();
				List<String> ans = new ArrayList<>();
				while (dist[c[0]][c[1]][c[2]] > 0) {
					int c1 = ch1[c[0]][c[1]][c[2]], c2 = ch2[c[0]][c[1]][c[2]];
					ans.add((c1 + 1) + " " + (c2 + 1));
					for (int i = 0; i < 3; i++) {
						if (c[i] == c2) {
							c[i] = c1;
							break;
						}
					}
					Arrays.sort(c);
				}
				Collections.reverse(ans);
				for (String s : ans) {
					out.println(s);
				}
				return;
			}

			for (int move = 0; move < 3; move++) {
				int tmp = 0;
				for (int i = 0; i < 3; i++) {
					if (i != move) {
						b[tmp++] = a[i];
					}
				}
				char col = color[b[0]][b[1]];
				for (int pos = 0; pos < n; pos++) {
					if (pos != a[0] && pos != a[1] && pos != a[2]) {
						if (color[a[move]][pos] == col) {
							c[0] = b[0];
							c[1] = b[1];
							c[2] = pos;
							Arrays.sort(c);
							if (dist[c[0]][c[1]][c[2]] == INF) {
								dist[c[0]][c[1]][c[2]] = curDist + 1;
								ch1[c[0]][c[1]][c[2]] = a[move];
								ch2[c[0]][c[1]][c[2]] = pos;
								q[tail++] = c[0];
								q[tail++] = c[1];
								q[tail++] = c[2];
							}
						}
					}
				}
			}
		}

		out.println(-1);
	}

	FastScanner in;
	PrintWriter out;

	public void run() {
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
		new D().run();
	}
}