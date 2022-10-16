import java.io.*;
import java.util.*;

public class CopyOfC {

	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		int[] xs = new int[n];
		for (int i = 0; i < n; i++) {
			xs[i] = in.nextInt();
		}
		Random rng = new Random(123321);
		for (int i = 1; i < n; i++) {
			int pos = rng.nextInt(i + 1);
			int tmp = xs[i];
			xs[i] = xs[pos];
			xs[pos] = tmp;
		}

		Arrays.sort(xs);

		int b = in.nextInt(), a = in.nextInt();
		int m = b - a + 1;

		int[] max = new int[m];
		Arrays.fill(max, 1);
		for (int i = 0; i < n; i++) {
			if (i > 0 && xs[i] == xs[i - 1]) {
				continue;
			}
			int x = xs[i];
			int ceil = (a + x - 1) / x;
			int floor = b / x;

			for (int j = ceil * x; j <= floor * x; j += x) {
				max[j - a] = x;
			}
		}
		BIT bit = new BIT(m);
		int[] ans = new int[m];
		Arrays.fill(ans, INF);
		ans[m - 1] = 0;
		bit.set(m - 1, 0);
		for (int i = m - 2; i >= 0; i--) {
			ans[i] = ans[i + 1] + 1;
			int mx = max[i];
			if (mx > 1) {
				int to = Math.min(m, i + mx) - 1;
				ans[i] = Math.min(ans[i], bit.get(to) + 1);
			}
			if (ans[i] < INF) {
				bit.set(i, ans[i]);
			}
		}

		out.println(ans[0]);
	}

	final int INF = Integer.MAX_VALUE / 2;

	class BIT {
		int[] tree;

		public BIT(int n) {
			this.tree = new int[n];
			Arrays.fill(tree, INF);
		}

		public int get(int pos) {
			int res = INF;
			while (pos >= 0) {
				int tmp = tree[pos];
				if (tmp < res) {
					res = tmp;
				}
				pos = (pos & (pos + 1)) - 1;
			}
			return res;
		}

		public void set(int pos, int val) {
			while (pos < tree.length) {
				if (val < tree[pos]) {
					tree[pos] = val;
				}
				pos = pos | (pos + 1);
			}
		}
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

		String nextToken() {
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
		new CopyOfC().run();
	}
}