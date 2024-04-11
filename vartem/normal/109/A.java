import java.io.*;
import java.util.*;

public class A {

	void solve() throws Exception {
		int n = nextInt();
		int minL = Integer.MAX_VALUE;
		for (int i = 0; i <= n; i += 4) {
			if ((n - i) % 7 == 0) {
				minL = i / 4;
				for (int j = 0; j < minL; j++) {
					out.print("4");
				}
				minL = (n - i) / 7;
				for (int j = 0; j < minL; j++) {
					out.print("7");
				}
				return;
			}
			
		}
		out.println(-1);
	}

	void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			// in = new BufferedReader(new FileReader(filename + ".in"));
			// out = new PrintWriter(filename + ".out");

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
	final String filename = new String("A").toLowerCase();

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