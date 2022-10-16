import java.util.*;
import java.io.*;

public class D {

	class BIT {
		int[] tree;
		public BIT(int n) {
			tree = new int[n];
		}
		
		void add(int pos, int val) {
			while (pos < tree.length) {
				tree[pos] += val;
				pos |= pos + 1;
			}
		}
		
		int get(int l, int r) {
			int res = get(r);
			if (l > 0) {
				res -= get(l - 1);
			}
			return res;
		}
		
		int get(int pos) {
			int res = 0;
			while (pos >= 0) {
				res += tree[pos];
				pos = (pos & (pos + 1)) - 1;
			}
			return res;
		}
	}
	
	void solve() {
		int n = in.nextInt(), k = in.nextInt();
		k = Math.min(k, n - k);
		
		BIT end = new BIT(n);
		long ans = 1;
		int cur = 0;
		StringBuilder sb = new StringBuilder();
		for (int i = 1; i <= n; i++) {
			int newCur = (cur + k) % n;
			int left = (cur + 1) % n, right = (cur + k - 1) % n;
			int add = 0;
			if (left <= right) {
				add += end.get(left, right);
			} else {
				add += end.get(left, n - 1) + end.get(0, right);
			}
			ans += add + 1;
			sb.append(ans).append(' ');
			end.add(cur, 1);
			end.add(newCur, 1);
			cur = newCur;
		}
		out.println(sb.toString());
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
		new D().run();
	}
}