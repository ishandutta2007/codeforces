import java.util.*;
import java.io.*;

public class A {

	void solve() {
		int n = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt() - 1;
		}
		boolean[] used = new boolean[n];
		int cycles = 0;
		for (int i = 0; i < n; i++) {
			if (!used[i]) {
				int cur = i;
				do {
					used[cur] = true;
					cur = a[cur];
				} while (cur != i);
				cycles++;
			}
		}
		int ans = 0;
		if (cycles > 1) {
			ans += cycles;
		}
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += in.nextInt();
		}
		ans += (sum + 1) % 2;
		out.println(ans);
	}

	FastScanner in;
	PrintWriter out;

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
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		public String nextToken() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
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
		new A().run();
	}
}