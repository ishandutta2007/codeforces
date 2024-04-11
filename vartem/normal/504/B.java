import java.io.*;
import java.util.*;

public class B {

	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		int[] a = new int[n], b = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		for (int i = 0; i < n; i++) {
			b[i] = in.nextInt();
		}

		int[] invA = getInv(a);
		int[] invB = getInv(b);

		int[] invSum = new int[n];

		int carry = 0;
		for (int i = n - 1; i >= 0; i--) {
			invSum[i] = invA[i] + invB[i] + carry;
			if (invSum[i] >= n - i) {
				invSum[i] -= n - i;
				carry = 1;
			} else {
				carry = 0;
			}
		}
		
		int[] sum = restore(invSum);
		for (int i = 0; i < n; i++) {
			out.print(sum[i] + " ");
		}

	}

	private int[] restore(int[] inv) {
		int[] a = new int[inv.length];
		BIT bit = new BIT(a.length);
		
		for (int i = 0; i < a.length; i++) {
			int left = -1, right = a.length;
			while (left < right - 1) {
				int mid = (left + right) >> 1;
				if (mid - bit.get(mid) >= inv[i]) {
					right = mid;
				} else {
					left = mid;
				}
			}
			a[i] = right;
			bit.add(a[i], 1);
		}
		
		return a;
	}

	private int[] getInv(int[] a) {
		int[] inv = new int[a.length];
		BIT bit = new BIT(a.length);

		for (int i = a.length - 1; i >= 0; i--) {
			inv[i] = bit.get(a[i]);
			bit.add(a[i], 1);
		}
		return inv;
	}

	class BIT {
		int[] tree;

		public BIT(int n) {
			tree = new int[n];
		}

		int get(int pos) {
			int res = 0;
			while (pos >= 0) {
				res += tree[pos];
				pos = (pos & (pos + 1)) - 1;
			}
			return res;
		}

		void add(int pos, int val) {
			while (pos < tree.length) {
				tree[pos] += val;
				pos |= pos + 1;
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
		new B().run();
	}
}