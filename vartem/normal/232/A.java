import java.io.*;
import java.util.*;

public class Cycles3 {

	final String filename = new String("Cycles3").toLowerCase();

	void solve() throws Exception {
		int n = nextInt();
		int k = 2;
		while (k * (k - 1) * (k - 2) / 6 <= n) {
			k++;
		}
		k--;
		
		n -= k * (k - 1) * (k - 2) / 6;
		
		int[] dp = new int[n + 1];
		int[] prev = new int[n + 1];
		Arrays.fill(dp, Integer.MAX_VALUE / 2);
		
		dp[0] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 2; j <= k; j++) {
				int c = j * (j - 1) / 2;
				if (c > i) {
					break;
				}
				if (dp[i - c] + 1 < dp[i]) {
					dp[i] = dp[i - c] + 1;
					prev[i] = j;
				}
			}
		}
		
		int best = dp[n] + k;
		boolean[][] a = new boolean[best][best];
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < k; j++) {
				a[i][j] = (i != j);
			}
		}
		
		int cur = n;
		int tmp = k;
		while (cur > 0) {
			int cnt = prev[cur];
			for (int j = 0; j < cnt; j++) {
				a[tmp][j] = a[j][tmp] = true;
			}
			tmp++;
			cur = cur - (cnt * (cnt - 1) / 2);
		}
		
		out.println(best);
		for (boolean[] aa : a) {
			for (boolean b : aa) {
				if (b) {
					out.print(1);
				} else {
					out.print(0);
				}
			}
			out.println();
		}
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
		new Cycles3().run();
	}

}