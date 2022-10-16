import java.io.*;
import java.util.*;

public class A {

	public void solve() {
		int n = in.nextInt(), l = in.nextInt(), r = in.nextInt(), ql = in
				.nextInt(), qr = in.nextInt();

		int[] w = new int[n];
		int sum = 0;
		for (int i = 0; i < n; i++) {
			w[i] = in.nextInt();
			sum += w[i];
		}
		
		int[] pref = new int[n];
		pref[0] = w[0];
		for (int i = 1; i < n; i++) {
			pref[i] = w[i] + pref[i - 1];
		}

		long min = Long.MAX_VALUE;
		for (int left = 0; left <= n; left++) {
			int sum1 = 0;
			if (left > 0) {
				sum1 = pref[left - 1];
			}
			
			int sum2 = sum - sum1;
			
			long ans = l * sum1 + r * sum2;
			
			int right = n - left;
			
			if (left < right) {
				long rmn = right - left - 1;
				ans += rmn * qr;
			} else if (left > right) {
				long rmn = left - right - 1;
				ans += rmn * ql;
			}
			min = Math.min(ans, min);
		}
		
		out.println(min);
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
		new A().run();
	}
}