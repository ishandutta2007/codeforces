import java.io.*;
import java.util.*;

public class B {

	public void solve() {
		int n = in.nextInt();
		int[] count = new int[1001];
		for (int i = 0; i < n; i++) {
			count[in.nextInt()]++;
		}
		int t = in.nextInt();
		int max = 0;
		for (int i = 0; i <= 1000; i++) {
			int ans = 0;
			for (int j = 0; j <= t && i + j <= 1000; j++) {
				ans += count[i + j];
			}
			max = Math.max(ans, max);
		}
		out.println(max);
	}

	FastScanner in;
	PrintWriter out;

	public void run() {
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

		public FastScanner(String name) {
			try {
				br = new BufferedReader(new FileReader(name));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
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
		new B().run();
	}
}