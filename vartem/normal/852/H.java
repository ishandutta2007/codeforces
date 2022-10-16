import java.util.*;
import java.io.*;

public class H {

	class Point {
		int x, y;
		int id1, id2;

		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}

		int q() {
			if (x == 0 && y == 0) {
				return 0;
			} else if (x > 0 || (x == 0 && y > 0)) {
				return 1;
			} else {
				return 2;
			}
		}
		@Override
		public String toString() {
			return "Point [x=" + x + ", y=" + y + ", id1=" + id1 + ", id2=" + id2 + "]";
		}
	}

	long vectMul(Point a, Point b) {
		return 1L * a.x * b.y - 1L * a.y * b.x;
	}

	long vectMul(Point a, Point b, Point c) {
		return 1L * (b.x - a.x) * (c.y - a.y) - 1L * (b.y - a.y) * (c.x - a.x);
	}

	void solve() {
		int n = in.nextInt();
		int k = in.nextInt();
		Point[] a = new Point[n];
		for (int i = 0; i < n; i++) {
			a[i] = new Point(in.nextInt(), in.nextInt());
		}
		Arrays.sort(a, (p1, p2) -> {
			if (p1.x != p2.x) {
				return p1.x - p2.x;
			}
			return p1.y - p2.y;
		});

		long result = 0;
		long[][] dp = new long[n][k + 1];
		long[][] cost = new long[n][n];
		long INF = Long.MIN_VALUE / 3;
		Point[] buf = new Point[n];
		for (int i = 0; i < buf.length; i++) {
			buf[i] = new Point(0, 0);
		}
		Point[] vecs = new Point[n * (n - 1)];
		for (int i = 0, tmp = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i != j) {
					vecs[tmp] = new Point(a[j].x - a[i].x, a[j].y - a[i].y);
					vecs[tmp].id1 = i;
					vecs[tmp].id2 = j;
					tmp++;
				}
			}
		}
		Arrays.sort(vecs, (p1, p2) -> {
			int q1 = p1.q(), q2 = p2.q();
			if (q1 != q2) {
				return q1 - q2;
			}
			return -Long.signum(vectMul(p1, p2));
		});
		for (int start = 0; start < n; start++) {
			for (int i = n - 1; i >= start; i--) {
				a[i].x -= a[start].x;
				a[i].y -= a[start].y;
			}
			for (int i = 0; i < n; i++) {
				Arrays.fill(dp[i], INF);
				Arrays.fill(cost[i], INF);
			}
			dp[start][0] = 0;

			int size = 0;
			for (int i = start + 1; i < n; i++) {
				buf[size].x = a[i].x;
				buf[size].y = a[i].y;
				buf[size].id1 = i;
				size++;
			}
			Arrays.sort(buf, 0, size, (p1, p2) -> {
				long v = vectMul(p1, p2);
				return -Long.signum(v);
			});

			for (int i = 0; i < size; i++) {
				for (int j = i + 1; j < size; j++) {
					int p1 = buf[i].id1, p2 = buf[j].id1;
					boolean ok = true;
					for (int t = i + 1; t < j; t++) {
						if (vectMul(buf[i], buf[j], buf[t]) > 0) {
							ok = false;
							break;
						}
					}
					if (ok) {
						cost[p1][p2] = vectMul(buf[i], buf[j]);
					}
				}
			}
			for (int i = 0; i < size; i++) {
				cost[start][buf[i].id1] = cost[buf[i].id1][start] = 0;
			}

			for (Point vec : vecs) {
				int p1 = vec.id1, p2 = vec.id2;
				long cst = cost[p1][p2];
				if (cst != INF) {
					long[] dp1 = dp[p1], dp2 = dp[p2];
					for (int i = 0; i < k; i++) {
						dp2[i + 1] = Math.max(dp2[i + 1], dp1[i] + cst);
					}
				}
			}
			result = Math.max(result, dp[start][k]);
		}

		out.printf("%d.%02d\n", result / 2, 50 * (result % 2));
	}

	FastScanner in;
	PrintWriter out;

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

		public FastScanner(String s) {
			try {
				br = new BufferedReader(new FileReader(s));
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		public String nextToken() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
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
		new H().run();
	}
}