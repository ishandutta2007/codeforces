import java.io.*;
import java.util.*;

public class C {

	FastScanner in;
	PrintWriter out;

	long[] ans, all;
	int[] tmp;

	void mergesort(int[] a, int l, int r, int depth) {
		if (depth == 0) {
			return;
		}
		int m = (l + r) >> 1;
		mergesort(a, l, m, depth - 1);
		mergesort(a, m, r, depth - 1);

		all[depth] += 1l * (r - m) * (m - l);
		{
			int i = l, j = m;
			int it = 0;
			while (i < m && j < r) {
				if (a[i] == a[j]) {
					int i1 = i, j1 = j;
					while (i1 < m && a[i1] == a[i]) {
						tmp[it++] = a[i1];
						i1++;
					}
					while (j1 < r && a[j1] == a[j]) {
						tmp[it++] = a[j1];
						ans[depth] += m - i1;
						j1++;
					}
					all[depth] -= 1l * (i1 - i) * (j1 - j);
					
					i = i1;
					j = j1;
				} else {
					if (a[i] < a[j]) {
						tmp[it++] = a[i++];
					} else {
						tmp[it++] = a[j++];
						ans[depth] += m - i;
					}
				}
			}
			
			while (i < m) {
				tmp[it++] = a[i++];
			}
			while (j < r) {
				tmp[it++] = a[j++];
			}
		}
		System.arraycopy(tmp, 0, a, l, r - l);
	}

	void solve() {
		int n = in.nextInt();
		int m = 1 << n;
		int[] a = new int[m];
		for (int i = 0; i < m; i++) {
			a[i] = in.nextInt();
		}
		tmp = new int[m];
		ans = new long[n + 1];
		all = new long[n + 1];

		mergesort(a, 0, m, n);

		int q = in.nextInt();

		StringBuilder output = new StringBuilder();
		for (int i = 0; i < q; i++) {
			int rev = in.nextInt();
			for (int j = rev; j > 0; j--) {
				ans[j] = all[j] - ans[j];
			}
			long cur = 0;
			for (int t = 0; t <= n; t++) {
				cur += ans[t];
			}
			output.append(cur).append("\n");
		}
		out.print(output);
	}

	void run() {
		try {
			in = new FastScanner();
			out = new PrintWriter(System.out);
			solve();
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
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
		new C().run();
	}
}