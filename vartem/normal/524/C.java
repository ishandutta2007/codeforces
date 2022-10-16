import java.io.*;
import java.util.*;

public class C {

	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt(), k = in.nextInt();
		int[] a = new int[n];
		Set<Integer> all = new HashSet<>();
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
			all.add(a[i]);
		}
		int q = in.nextInt();
		for (int Q = 0; Q < q; Q++) {
			int x = in.nextInt();
			int ans = k + 1;

			for (int i = 0; i < n; i++) {
				for (int cnt1 = 1; cnt1 <= k; cnt1++) {
					int rmn = x - cnt1 * a[i];
					if (rmn < 0) {
						break;
					}
					
					if (rmn == 0) {
						ans = Math.min(ans, cnt1);
						continue;
					}
					
					for (int cnt2 = 1; cnt2 + cnt1 <= k; cnt2++) {
						if (rmn % cnt2 != 0) {
							continue;
						}
						int r = rmn / cnt2;
						if (all.contains(r)) {
							ans = Math.min(ans, cnt1 + cnt2);
						}
					}
				}
			}

			if (ans == k + 1) {
				ans = -1;
			}
			out.println(ans);
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
		new C().run();
	}
}