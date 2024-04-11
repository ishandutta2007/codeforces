import java.io.*;
import java.util.*;

public class Baloons {

	final String filename = new String("Baloons").toLowerCase();

	void solve() throws Exception {
		final int n = 350;
		long[] x = new long[n], p = new long[n];
		x[0] = 0; p[0] = 1000000;
		long lastX = 1;
		for (int i = 1; i < n - 1; i++) {
			long goodR = n - i;
			while (4L * goodR * p[i - 1] > (lastX - x[i - 1]) * (lastX - x[i - 1])) {
				lastX++;
			}
			x[i] = lastX;
			p[i] = goodR;
		}
		x[n - 1] = x[n - 2] + 37364 + 10;
		p[n - 1] = 1000000;
		out.println(n);
		for (int i = 0; i < n; i++) {
			out.println((x[i] + " " + p[i]));
		}
		
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
		new Baloons().run();
	}

}