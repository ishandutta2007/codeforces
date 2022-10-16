import java.io.*;
import java.util.*;

public class D {

	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt(), k = in.nextInt();
		Queue<Long> q = new PriorityQueue<>();
		for (int i = 0; i < n; i++) {
			long start = in.nextInt(), length = in.nextInt();
			while (q.size() > 0 && q.peek() <= start) {
				q.poll();
			}
			if (q.size() == k) {
				start = q.poll();
			}
			out.println(start + length);
			q.add(start + length);
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