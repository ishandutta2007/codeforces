import java.io.*;
import java.util.*;

public class Solution {

	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;

	public void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		long[] ans = new long[n];
		int[] t = new int[n];
		final int[] x = new int[n];
		for (int i = 0; i < n; ++i) {
			t[i] = nextInt();
			x[i] = nextInt();
		}
		long curTime = 0;
		int qs = 0;
		while (qs < n) {
			int add = Math.min(m, n - qs);
			curTime = Math.max(curTime, t[qs + add - 1]);
			Integer[] ids = new Integer[add];
			for (int i = 0; i < add; ++i) {
				ids[i] = qs + i;
			}
			Arrays.sort(ids, new Comparator<Integer>() {
				@Override
				public int compare(Integer o1, Integer o2) {
					return x[o1] - x[o2];
				}
			});
			for (int i = 0; i < add; ) {
				curTime += i == 0 ? x[ids[i]] : x[ids[i]] - x[ids[i - 1]];
				int j = i;
				while (j < add && x[ids[i]] == x[ids[j]]) {
					ans[ids[j++]] = curTime;
				}
				curTime += 1 + (j - i) / 2;
				i = j;
			}
			curTime += x[ids[add - 1]];
			qs += add;
		}
		for (int i = 0; i < n; ++i) {
			out.print(ans[i] + " ");
		}
		out.println();
	}

	public void run() throws IOException {
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		eat("");

		solve();

		out.close();
	}

	void eat(String s) {
		st = new StringTokenizer(s);
	}

	String next() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null) {
				return null;
			}
			eat(line);
		}
		return st.nextToken();
	}

	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	long nextLong() throws IOException {
		return Long.parseLong(next());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	static boolean failed = false;

	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		new Solution().run();
	}

}