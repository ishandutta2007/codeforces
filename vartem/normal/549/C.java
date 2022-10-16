import java.io.*;
import java.util.*;

public class C {

	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt(), k = in.nextInt();
		int[] cnt = new int[2];
		for (int i = 0; i < n; i++) {
			cnt[in.nextInt() % 2]++;
		}
		if (n == k) {
			if (cnt[1] % 2 == 0) {
				out.println("Daenerys");
			} else {
				out.println("Stannis");
			}
			return;
		}

		if ((n - k) % 2 == 0) {
			int moves = (n - k) / 2;
			if (k % 2 == 0) {
				out.println("Daenerys");
			} else {
				if (cnt[0] <= moves) {
					out.println("Stannis");
				} else {
					out.println("Daenerys");
				}
			}
		} else {
			int moves = (n - k - 1) / 2;
			
			if (k % 2 == 0) {
				if (cnt[0] <= moves || cnt[1] <= moves) {
					out.println("Daenerys");
				} else {
					out.println("Stannis");
				}
			} else {
				if (cnt[1] <= moves) {
					out.println("Daenerys");
				} else {
					out.println("Stannis");
				}
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