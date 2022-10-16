import java.io.*;
import java.util.*;

public class B {

	final String filename = new String("B").toLowerCase();

	final int MAGIC = 250;

	double[][] clone(double[][] a) {
		double[][] res = new double[a.length][a[0].length];
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a[i].length; j++) {
				res[i][j] = a[i][j];
			}
		}
		return res;
	}

	void solve() throws Exception {
		int n = nextInt();
		int l = nextInt();
		int k = nextInt();
		double[] prob = new double[n];
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			prob[i] = (double) nextInt() / (double) 100;
		}
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}

		double[][] cur = new double[2 * MAGIC + 1][n + 1];
		cur[k + MAGIC][0] = 1;
		for (int i = 0; i < n; i++) {
			double[][] prev = clone(cur);
			cur = new double[2 * MAGIC + 1][n + 1];
			double p = prob[i];
			for (int j = 0; j <= 2 * MAGIC; j++) {
				for (int t = 0; t < n; t++) {
					int to = Math.max(0, Math.min(j + a[i], 2 * MAGIC));
					cur[to][t + 1] += p * prev[j][t];
					cur[j][t] += (1 - p) * prev[j][t];
				}
			}
		}
		double ans = 0;
		for (int i = l; i <= n; i++) {
			for (int j = MAGIC; j <= 2 * MAGIC; j++) {
				ans += cur[j][i];
			}
		}
		out.println(ans);
	}

	void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			// in = new BufferedReader(new FileReader("input.txt"));
			// out = new PrintWriter("output.txt");

			solve();

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
		new B().run();
	}

}