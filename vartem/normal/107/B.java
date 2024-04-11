import java.io.*;
import java.util.*;

public class B {

	double ans(int sum, int n, int sh) {
		double res = 1;
		if (sum < n) {
			return 1;
		}
		for (int i = 0; i < n; i++) {
			double a = sum + sh - n + i + 1;
			double b = sum - n + i + 1;
			res = (res * b / a);
		}
		return 1 - res;
	}
	
	void solve() throws Exception {
		int n = nextInt() - 1;
		int m = nextInt();
		int h = nextInt();
		int[] s = new int[m];
		int sum = 0;
		for (int i = 0; i < m; i++) {
			s[i] = nextInt();
			sum += s[i];
		}
		sum -= s[h - 1];
		s[h - 1]--;
		if (sum + s[h - 1] < n) {
			out.println(-1);
			return;
		}
		double res = ans(sum, n, s[h - 1]);
		out.printf("%.12f", res);
	}

	void run() {
		try {
			Locale.setDefault(Locale.US);
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			//			in = new BufferedReader(new FileReader(filename + ".in"));
			//			out = new PrintWriter(filename + ".out");

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
	final String filename = new String("B").toLowerCase();

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