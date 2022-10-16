import java.util.*;
import java.io.*;

public class A {

	public void solve() {
		int n = in.nextInt();
		List<Integer> left = new ArrayList<>(), right = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			int t = in.nextInt();
			if (t == 0) {
				left.add(i); 
			} else {
				right.add(i);
			}
		}
		long ans = 0;
		int[] sum = new int[n + 1];
		for (int i : right) {
			sum[i + 1]++;
		}
		for (int i = 1; i <= n; i++) {
			sum[i] += sum[i - 1];
		}
		for (int i : left) {
			ans += sum[i + 1];
		}
		out.println(ans);
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