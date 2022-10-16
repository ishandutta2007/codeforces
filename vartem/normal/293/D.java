import java.io.*;
import java.util.*;

public class D {

	FastScanner in;
	PrintWriter out;
	final String fileName = "D".toLowerCase();

	class Point {
		int x, y;

		public Point(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}

		public Point(Point a, Point b) {
			this.x = b.x - a.x;
			this.y = b.y - a.y;
		}

		public void transpose() {
			int tmp = x;
			x = y;
			y = tmp;
		}

		@Override
		public String toString() {
			return "Point [x=" + x + ", y=" + y + "]";
		}

	}

	void solve() {
		int n = in.nextInt();
		Point[] a = new Point[n];
		for (int i = 0; i < n; i++) {
			a[i] = new Point(in.nextInt() + 3000000, in.nextInt() + 3000000);
		}

		checkOrder(a);
		int[] xs = getMinMax(a);
		int[] getCountX = getCount(xs, a);
		for (Point p : a) {
			p.transpose();
		}
		
		checkOrder(a);
		int[] ys = getMinMax(a);
		int[] getCountY = getCount(ys, a);
		
		 double ans = getAns(getCountX);
		 ans += getAns(getCountY);

		 out.println(ans / 2);
	}

	private double getAns(int[] a) {
		double all = 0;
		for (int i : a) {
			all += i;
		}
		double weightedSum = 0;
		double sqSum = 0;
		
		double sq2 = 0;
		int n = a.length;
		for (int i = 0; i < n; i++) {
			weightedSum += (double) a[i] * i;
			sqSum += (double) i * i * a[i];
			sq2 += (double) i * i * a[i];
		}
		
		double ans1 = 0;
		double ans2 = 0;
		
		ans2 = sqSum / all;
		ans1 = (weightedSum * weightedSum - sq2);
		
		double ans = 2 * ans2 - ans1 / all / (all - 1) * 2.0;
		return ans;
	}

	private void checkOrder(Point[] a) {
		int n = a.length;
		for (int i = 0; i < n; i++) {
			Point b = a[i];
			Point c = a[(i + 1) % n];
			Point d = a[(i + 2) % n];
			long v = vectMul(b, c, d);
			if (v == 0) {
				continue;
			} else if (v > 0) {
				return;
			} else {
				reverse(a);
				return;
			}
		}
	}

	private long vectMul(Point b, Point c, Point d) {
		return ((long) c.x - b.x) * ((long) d.y - c.y) - ((long) c.y - b.y)
				* ((long) d.x - c.x);
	}

	private void reverse(Point[] a) {
		for (int i = 0, j = a.length - 1; i < j; i++, j--) {
			Point tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}

	}

	private int[] getCount(int[] xs, Point[] p) {
		int min = xs[0], max = xs[1];
		int[] result = new int[max - min + 1];
		boolean[] wasUp = new boolean[max - min + 1], wasDown = new boolean[max - min + 1];
		int n = p.length;

		for (int i = 0; i < n; i++) {
			Point a = p[i];
			Point b = p[(i + 1) % n];
			if (a.x == b.x) {
				if (a.y < b.y) {
					if (!wasDown[a.x - min]) {
						result[a.x - min] -= a.y - 1;
						wasDown[a.x - min] = true;
					}
				} else {
					if (!wasUp[a.x - min]) {
						result[a.x - min] += a.y;
						wasUp[a.x - min] = true;
					}
				}
			} else if (a.x < b.x) {
				for (int j = a.x; j <= b.x; j++) {
					int y = getDownY(a, b, j);
					if (!wasDown[j - min]) {
						result[j - min] -= y;
						wasDown[j - min] = true;
					}
				}

			} else {
				for (int j = a.x; j >= b.x; j--) {
					int y = getUpY(a, b, j);
					if (!wasUp[j - min]) {
						result[j - min] += y;
						wasUp[j - min] = true;
					}
				}

			}
		}
		return result;
	}

	private int getUpY(Point a, Point b, int j) {
		double y = a.y + (j - (double) a.x) * ((double) b.y - a.y)
				/ ((double) b.x - a.x);
		int t = (int) Math.floor(y);
		return t;
	}

	private int getDownY(Point a, Point b, int j) {
		double y = a.y + (j - (double) a.x) * ((double) b.y - a.y)
				/ ((double) b.x - a.x);
		int t = (int) Math.floor(y);
		if (Math.abs(t - y) < 1e-10) {
			t--;
		}
		return t;
	}

	private int[] getMinMax(Point[] a) {
		int minX = Integer.MAX_VALUE;
		int maxX = Integer.MIN_VALUE;

		for (Point p : a) {
			minX = Math.min(minX, p.x);
			maxX = Math.max(maxX, p.x);
		}

		return new int[] { minX, maxX };
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