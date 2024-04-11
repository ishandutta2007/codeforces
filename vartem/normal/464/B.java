import java.io.*;
import java.util.*;

public class B {

	FastScanner in;
	PrintWriter out;

	class Point {
		int x, y, z;

		public Point(int x, int y, int z) {
			super();
			this.x = x;
			this.y = y;
			this.z = z;
		}

		long dist(Point other) {
			long dx = x - other.x, dy = y - other.y, dz = z - other.z;
			return dx * dx + dy * dy + dz * dz;
		}

		@Override
		public String toString() {
			return "Point [x=" + x + ", y=" + y + ", z=" + z + "]";
		}

	}

	void solve() {
		Point[] a = new Point[8];
		for (int i = 0; i < 8; i++) {
			a[i] = new Point(in.nextInt(), in.nextInt(), in.nextInt());
		}

		Point[][] perms = new Point[8][];
		for (int i = 0; i < perms.length; i++) {
			perms[i] = permute(a[i]);
		}

		for (int first = 1; first < 8; first++) {
			for (int second = first + 1; second < 8; second++) {
				for (int third = second + 1; third < 8; third++) {
					for (Point p1 : perms[first]) {
						for (Point p2 : perms[second]) {
							for (Point p3 : perms[third]) {
								long d1 = a[0].dist(p1), d2 = a[0].dist(p2), d3 = a[0]
										.dist(p3);
								if (d1 == d2 && d1 == d3 && d1 > 0 && p1.dist(p2) == 2 * d1 && p1.dist(p3) == 2 * d1 && p2.dist(p3) == 2 * d1) {
									if (check(a, p1, p2, p3)) {
										return;
									}
								}
							}
						}
					}
				}
			}
		}
		out.println("NO");
	}

	private boolean check(Point[] a, Point p1, Point p2, Point p3) {
		Point[] need = new Point[8];

		for (int mask = 0; mask < 8; mask++) {
			need[mask] = new Point(a[0].x, a[0].y, a[0].z);
			if ((mask & 1) != 0) {
				need[mask].x += p1.x - a[0].x;
				need[mask].y += p1.y - a[0].y;
				need[mask].z += p1.z - a[0].z;
			}
			if ((mask & 2) != 0) {
				need[mask].x += p2.x - a[0].x;
				need[mask].y += p2.y - a[0].y;
				need[mask].z += p2.z - a[0].z;
			}
			if ((mask & 4) != 0) {
				need[mask].x += p3.x - a[0].x;
				need[mask].y += p3.y - a[0].y;
				need[mask].z += p3.z - a[0].z;
			}
		}

		boolean[] used = new boolean[8];
		for (int i = 0; i < 8; i++) {
			int x = -1;
			for (int j = 0; j < 8; j++) {
				if (!used[j] && match(a[i], need[j])) {
					x = j;
					break;
				}
			}
			if (x == -1) {
				return false;
			}
			used[x] = true;
		}

		Arrays.fill(used, false);
		out.println("YES");
		for (int i = 0; i < 8; i++) {
			int x = -1;
			for (int j = 0; j < 8; j++) {
				if (!used[j] && match(a[i], need[j])) {
					x = j;
				}
			}
			if (x == -1) {
				return false;
			}

			out.println(need[x].x + " " + need[x].y + " " + need[x].z);
			used[x] = true;
		}

		return true;
	}

	int[] tmp1 = new int[3], tmp2 = new int[3];

	private boolean match(Point a, Point b) {
		tmp1[0] = a.x;
		tmp1[1] = a.y;
		tmp1[2] = a.z;
		tmp2[0] = b.x;
		tmp2[1] = b.y;
		tmp2[2] = b.z;
		Arrays.sort(tmp1);
		Arrays.sort(tmp2);
		for (int i = 0; i < 3; i++) {
			if (tmp1[i] != tmp2[i]) {
				return false;
			}
		}
		return true;
	}

	private Point[] permute(Point a) {
		return new Point[] { new Point(a.x, a.y, a.z),
				new Point(a.x, a.z, a.y), new Point(a.y, a.x, a.z),
				new Point(a.y, a.z, a.x), new Point(a.z, a.x, a.y),
				new Point(a.z, a.y, a.x), };
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

		public FastScanner(String s) {
			try {
				br = new BufferedReader(new FileReader(s));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		String nextToken() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
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
		new B().run();
	}
}