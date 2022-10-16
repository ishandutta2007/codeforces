import java.io.*;
import java.util.*;

public class F {

	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt(), k = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}

		long ans = 0;

		int[] left = new int[n], right = new int[n];

		List<Integer> stack = new ArrayList<>();
		stack.add(-1);
		for (int i = 0; i < n; i++) {
			while (true) {
				int top = stack.get(stack.size() - 1);
				if (top != -1 && a[top] < a[i]) {
					stack.remove(stack.size() - 1);
				} else {
					break;
				}
			}
			left[i] = stack.get(stack.size() - 1);
			stack.add(i);
		}

		stack.clear();
		stack.add(n);
		for (int i = n - 1; i >= 0; i--) {
			while (true) {
				int top = stack.get(stack.size() - 1);
				if (top != n && a[top] <= a[i]) {
					stack.remove(stack.size() - 1);
				} else {
					break;
				}
			}
			right[i] = stack.get(stack.size() - 1);
			stack.add(i);
		}
		
//		System.err.println(Arrays.toString(left));
//		System.err.println(Arrays.toString(right));

		
		int[] sum = new int[n + 1];
		int[] deg = new int[k];
		deg[0]++;
		for (int i = 0; i < n; i++) {
			sum[i + 1] = (sum[i] + a[i]) % k;
			deg[sum[i + 1]]++;
		}
		
		int[][] lists = new int[k][];
		for (int i = 0; i < k; i++) {
			lists[i] = new int[deg[i]];
			deg[i] = 0;
		}
		for (int i = 0; i <= n; i++) {
			lists[sum[i]][deg[sum[i]]++] = i;
		}
		
		for (int i = 0; i < n; i++) {
			if (i - left[i] < right[i] - i) {
				for (int j = left[i] + 1; j <= i; j++) {
					int needSum = (sum[j] + a[i]) % k;
					ans += getSegment(lists[needSum], i + 1, right[i]);
				}
			} else {
				for (int j = i; j <= right[i] - 1; j++) {
					int needSum = (sum[j + 1] - a[i]) % k;
					if (needSum < 0) {
						needSum += k;
					}
					ans += getSegment(lists[needSum], left[i] + 1, i);
				}
			}
			ans--;
//			System.err.println(i + " " + ans);
		}

		out.println(ans);
	}

	private long getSegment(int[] a, int i, int j) {
		return getCount(a, j) - getCount(a, i - 1);
	}

	private int getCount(int[] a, int j) {
		int left = -1, right = a.length;
		while (left < right - 1) {
			int mid = (left + right) >>> 1;
			if (a[mid] > j) {
				right = mid;
			} else {
				left = mid;
			}
		}
		return left + 1;
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
		new F().run();
	}
}