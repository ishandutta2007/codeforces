import java.io.*;
import java.util.*;

public class A {

	final String filename = new String("A").toLowerCase();

	void solve() throws Exception {
		int n = nextInt();
		int m = nextInt();
		int k = nextInt();
		int[][] a = new int[n][m], b = new int[n][m], c = new int[n][m];
		for (int i = 0; i < n; i++) {
			nextToken();
			for (int j=  0; j < m; j++) {
				a[i][j] = nextInt();
				b[i][j] = nextInt();
				c[i][j] = nextInt();
			}
		}
		
		int[][] dp = new int[m + 1][k + 1];
		int best = 0;
		for (int first = 0; first < n; first++) {
			for (int second = 0; second < n; second++) {
				if (first == second) {
					continue;
				}
				for (int[] i : dp) {
					Arrays.fill(i, 0);
				}
				for (int i = 1; i <= m; i++) {
					for (int j = 1; j <= k; j++) {
						for (int t = 0; t <= c[first][i - 1] && t <= j; t++) {
							dp[i][j] = Math.max(dp[i][j], dp[i - 1][j - t] + (b[second][i - 1] - a[first][i - 1]) * t);
						}
					}
				}
				for (int i = 0; i <= k; i++) {
					best = Math.max(best, dp[m][i]);
				}
			}
		}
		out.println(best);
	}

	void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			//			in = new BufferedReader(new FileReader("input.txt"));
			//			out = new PrintWriter("output.txt");

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
		new A().run();
	}

}