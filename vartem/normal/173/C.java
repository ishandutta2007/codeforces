import java.io.*;
import java.util.*;

public class C {

	final String filename = new String("C").toLowerCase();

	int getSum(int l1, int r1, int l2, int r2) {
		int ans = sum[l2][r2];
		if (l1 > 0) {
			ans -= sum[l1 - 1][r2];
		}
		if (r1 > 0) {
			ans -= sum[l2][r1 - 1];
		}
		if (l1 > 0 && r1 > 0) {
			ans += sum[l1 - 1][r1 - 1];
		}
		return ans;
	}

	int n, m;
	int[][] a, sum;

	void solve() throws Exception {
		n = nextInt();
		m = nextInt();
		a = new int[n][m];
		sum = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				a[i][j] = nextInt();
				sum[i][j] = a[i][j];
				if (i > 0) {
					sum[i][j] += sum[i - 1][j];
				}
				if (j > 0) {
					sum[i][j] += sum[i][j - 1];
				}
				if (i > 0 && j > 0) {
					sum[i][j] -= sum[i - 1][j - 1];
				}
			}
		}

		int best = -Integer.MAX_VALUE;
		for (int cx = 1; cx < n - 1; cx++) {
			for (int cy = 1; cy < m - 1; cy++) {
				int curL1 = cx - 1;
				int curL2 = cx + 1;
				int curR1 = cy - 1;
				int curR2 = cy + 1;
				int sum = a[cx][cy];
				while (curL1 >= 0 && curR1 >= 0 && curL2 < n && curR2 < m) {
					sum = getSum(curL1, curR1, curL2, curR2) - sum - a[curL1 + 1][curR1];
					best = Math.max(best, sum);
					curL1--; curR1--;
					curL2++; curR2++;
				}
			}
		}
		out.println(best);
	}

	void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
//			 in = new BufferedReader(new FileReader("input.txt"));
			// out = new PrintWriter("output.txt");

			long time = System.currentTimeMillis();
			solve();
			System.err.println(System.currentTimeMillis() - time);

			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	BufferedReader in;
	StringTokenizer st;
	PrintWriter out;

	String nextToken() throws Exception {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}

	int nextInt() throws Exception {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws Exception {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws Exception {
		return Double.parseDouble(nextToken());
	}

	public static void main(String[] args) {
		new C().run();
	}

}