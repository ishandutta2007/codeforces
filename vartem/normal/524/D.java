import java.io.*;
import java.util.*;

public class D {

	FastScanner in;
	PrintWriter out;

	final int MAX = 24 * 60 * 60;

	void solve() {
		int n = in.nextInt(), m = in.nextInt(), T = in.nextInt();
		int[] add = new int[MAX + 1];
		int[] rem = new int[MAX + 1];
		int[] ts = new int[n];
		for (int i = 0; i < n; i++) {
			String[] s = in.nextToken().split(":");
			ts[i] = 60 * 60 * Integer.parseInt(s[0]) + 60
					* Integer.parseInt(s[1]) + Integer.parseInt(s[2]);
			add[ts[i]]++;
			rem[ts[i] + T]++;
		}

		int[] count = new int[n];
		int[] ans = new int[n];

		int it = 0;
		int cur = 0;
		int maxCur = 0;
		for (int t = 0; t < n; t++) {
			while (ts[it] + T <= ts[t]) {
				count[ans[it]]--;
				if (count[ans[it]] == 0) {
					cur--;
				}
				it++;
			}

			if (cur == m) {
				ans[t] = ans[t - 1];
				if (count[ans[t]] == 0) {
					cur++;
				}
				count[ans[t]]++;
			} else {
				ans[t] = (t == 0 ? 0 : (ans[t - 1] + 1));
				if (count[ans[t]] == 0) {
					cur++;
				}
				count[ans[t]]++;
			}
			maxCur = Math.max(cur, maxCur);
		}

		if (maxCur < m) {
			out.println("No solution");
			return;
		}

		int max = 0;
		for (int i : ans) {
			max = Math.max(max, i);
		}
		out.println(max + 1);

		for (int i = 0; i < n; i++) {
			out.println(ans[i] + 1);
		}
	}

	class User implements Comparable<User> {
		int id, start;

		public User(int id, int start) {
			super();
			this.id = id;
			this.start = start;
		}

		@Override
		public int compareTo(User o) {
			return Integer.compare(start, o.start);
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
		new D().run();
	}
}