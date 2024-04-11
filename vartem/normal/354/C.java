import java.io.*;
import java.util.*;

public class C {

	final int MAX = 1_000_001;

	public void solve() {
		int n = in.nextInt(), k = in.nextInt();
		int[] count = new int[MAX];

		for (int i = 0; i < n; i++) {
			count[in.nextInt()]++;
		}
		
		for (int i = 1; i < MAX; i++) {
			count[i] += count[i - 1];
		}
		
		int bestAns = 1;
		for (int ans = 2; ans < MAX; ans++) {
			
			int cur = 0;
			for (int start = ans; start < MAX; start += ans) {
				int r = Math.min(MAX - 1, Math.min(start + k, start + ans - 1));
				cur += count[r] - count[start - 1];
			}
			
			if (cur == n) {
				bestAns = Math.max(bestAns, ans);
			}
		}
		out.println(bestAns);
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
		new C().run();
	}
}