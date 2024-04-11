import java.io.*;
import java.util.*;

public class B {

	final String filename = new String("B").toLowerCase();

	void solve() throws Exception {
		String a = nextToken();
		String b = nextToken();
		int k = nextInt();
		int len = a.length();

		String text = a + a.substring(0, len - 1);
		List<Integer> occurs = new ArrayList<Integer>();
		for (int i = 0; i < len; i++) {
			boolean ok = true;
			for (int j = 0; j < len; j++) {
				if (text.charAt(i + j) != b.charAt(j)) {
					ok = false;
					break;
				}
			}
			if (ok) {
				occurs.add(i);
			}
		}
		if (k == 0) {
			if (a.equals(b)) {
				out.println(1);
			} else {
				out.println(0);
			}
			return;
		}
		int maxValue = (len - 1) * k;
		int mod = 1000 * 1000 * 1000 + 7;
		int[][] dp = new int[2][len];
		dp[0][0] = 1;
		int lastSum = 1;
		for (int i = 0; i < k; i++) {
			int f = i & 1;
			int g = 1 - f;
			Arrays.fill(dp[g], 0);
			for (int j = 0; j < len; j++) {
				dp[g][j] = (lastSum - dp[f][j] + mod);
				while (dp[g][j] >= mod) {
					dp[g][j] -= mod;
				}
			}
			lastSum = 0;
			for (int j = 0; j < len; j++) {
				lastSum += dp[g][j];
				if (lastSum >= mod) {
					lastSum -= mod;
				}
			}
		}
		int ans = 0;
		for (int i : occurs) {
			ans += dp[k & 1][i];
			if (ans >= mod) {
				ans -= mod;
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