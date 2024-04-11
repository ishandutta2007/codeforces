import java.io.*;
import java.util.*;

public class A {

	final String filename = new String("A").toLowerCase();

	void solve() throws Exception {
		int n = nextInt();
		String[] s = new String[n];
		for (int i = 0; i < n; i++) {
			s[i] = nextToken();
		}
		int ans = 0;
		int inf = Integer.MIN_VALUE / 2;
		for (int i = 0; i < 26; i++) {
			int[] dp = new int[26];
			Arrays.fill(dp, inf);
			dp[i] = 0;
			for (int j = 0; j < n; j++) {
				int first = s[j].charAt(0) - 'a';
				int last = s[j].charAt(s[j].length() - 1) - 'a';
				if (dp[first] != inf) {
					dp[last] = Math.max(dp[last], dp[first] + s[j].length());
				}
				ans = Math.max(ans, dp[i]);
			}
			
		}
		out.println(ans);
	}

	void run() {
		try {
//			in = new BufferedReader(new FileReader(filename + ".in"));
//			out = new PrintWriter(filename + ".out");
			 in = new BufferedReader(new InputStreamReader(System.in));
			 out = new PrintWriter(System.out);

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