import java.io.*;
import java.util.*;

public class B {

	final String filename = new String("B").toLowerCase();

	class Point {
		long x, y;

		public Point(long x, long y) {
			super();
			this.x = x;
			this.y = y;
		}

		public Point(Point a, Point b) {
			this.x = b.x - a.x;
			this.y = b.y - a.y;
		}
		
		public long vectMul(Point other) {
			return x * other.y - y * other.x;
		}
		
		public boolean onLine(Point a, Point b) {
			return new Point(this, a).vectMul(new Point(b, a)) == 0;
		}
	}

	void solve() throws Exception {
		int n = nextInt();
		int m = nextInt();
		Point[] a = new Point[m];
		for (int i = 0; i < m; i++) {
			a[i] = new Point(nextLong(), nextLong());
		}
		int[] ans = new int[n];
		Arrays.fill(ans, 1);
		for (int i = 0; i < m; i++) {
			for (int j = i + 1; j < m; j++) {
				if (a[i].y != a[j].y) {
					long num = (a[j].x - a[i].x) * (-a[i].y);
					long denom = (a[j].y - a[i].y);
					if (num % denom != 0) {
						continue;
					}
					long quot = (num / denom) + a[i].x; 
					if (quot < 1 || quot > n + 0.5) {
						continue;
					}
					
					int coord = (int) (quot) - 1;
					int count = 0;
					for (int k = 0; k < m; k++) {
						if (a[k].onLine(a[i], a[j])) {
							count++;
						}
					}
					ans[coord] = Math.max(ans[coord], count);
				}
			}
		}
		
		long sum = 0;
		for (int i = 0; i < n; i++) {
			sum += ans[i];
		}
		out.println(sum);
	}

	void run() {
		try {
//			in = new BufferedReader(new FileReader(filename + ".in"));
//			out = new PrintWriter(filename + ".out");
			 in = new BufferedReader(new InputStreamReader(System.in));
			 out = new PrintWriter(System.out);

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