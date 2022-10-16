import java.io.*;
import java.util.*;

public class D2 {

	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}

		int[] ans = new int[n];
		int[] add = new int[n + 1];
		for (int elem = 1; elem < n; elem++) {
			int cur = elem - 1;
			int ourA = a[elem];

			int t = 1;
			int x = cur;

			while (true) {
				int fst = t, snd = (x == 0) ? n : (cur / x + 1);
				int par = a[x];
				if (par > ourA) {
					add[fst]++;
					add[snd]--;
				}
				t = snd;
				if (x == 0) {
					break;
				}
				x = cur / t;
			}
		}

		for (int i = 1; i < n; i++) {
			add[i] += add[i - 1];
			out.print(ans[i] + add[i]);
			out.print(' ');
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
		new D2().run();
	}
}