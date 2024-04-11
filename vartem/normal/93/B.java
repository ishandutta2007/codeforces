import java.io.*;
import java.util.*;

public class B {

	class Pair {
		int x;
		double y;

		public Pair(int x, double y) {
			super();
			this.x = x;
			this.y = y;
		}
	}

	int gcd(int a, int b) {
		return (a == 0) ? b : (gcd(b % a, a));
	}

	void solve() throws Exception {
		int n = nextInt();
		int w = nextInt();
		int m = nextInt();
		int g = gcd(n, m);
		n /= g;
		m /= g;
		double h = ((double) n * w) / (double) m;
		double[] a = new double[m];
		ArrayList<Pair>[] ans = new ArrayList[m];
		for (int i = 0; i < m; i++)
			ans[i] = new ArrayList<Pair>();
		for (int i = 0; i < n; i++) {
			int cnt = 0;
			double rmn = w;
			for (int j = 0; j < m; j++) {
				if (rmn == 0)
					break;
				if (cnt >= 2)
					break;
				if (a[j] < h) {
					double t = Math.min(h - a[j], rmn);
					cnt++;
					ans[j].add(new Pair(i, t));
					rmn -= t;
					a[j] += t;
				}
			}
			if (rmn > 1e-9) {
				out.println("NO");
				return;
			}
		}

		for (int i = 0; i < m; i++)
			if (a[i] < h - 1e-9) {
				out.println("NO");
				return;
			}

		out.println("YES");
		for (int r = 0; r < g; r++) {
			for (int i = 0; i < m; i++) {
				for (Pair p : ans[i]) {
					out.print((p.x + (r * n) + 1) + " " + p.y + " ");
				}
				out.println();
			}
		}
	}

	void run() {
		try {
			Locale.setDefault(Locale.US);
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			// in = new BufferedReader(new FileReader(filename + ".in"));
			// out = new PrintWriter(filename + ".out");

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
	final String filename = new String("B").toLowerCase();

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