import java.io.*;
import java.util.*;

public class B {

	final String filename = new String("B").toLowerCase();

	void solve() throws Exception {
		int n = nextInt();
		double[] p = new double[n];
		for (int i = 0; i < n; i++) {
			p[i] = nextDouble();
		}
		double[] dp = new double[n + 1];
		double[] dpAns = new double[n + 1];
		for (int i = 1; i <= n; i++) {
			dpAns[i] = p[i - 1] * (2 * (dp[i - 1]) + 1) + dpAns[i - 1];
			dp[i] = p[i - 1] * (dp[i - 1] + 1);
		}
		
		out.println(dpAns[n]);
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