import java.io.*;
import java.util.*;

public class DoubleCola {

	final String[] s = new String[]{"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
	
	void solve() throws Exception {
		int n = nextInt() - 1;
		long k = 0;
		long c = 1;
		while (n >= k * 2 + 5) {
			k = k * 2 + 5;
			c *= 2;
		}
		int g = (int)((n - k) / c);
		out.println(s[g]);
	}

	void run() {
		try {
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
	final String filename = new String("DoubleCola").toLowerCase();

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
		new DoubleCola().run();
	}

}