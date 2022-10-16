import java.io.*;
import java.util.*;

public class IceSculptures {

	final String filename = new String("IceSculptures").toLowerCase();

	void solve() throws Exception {
		int n = nextInt();
		int[] t = new int[n];
		int best = 0;
		for (int i = 0; i < n; i++) {
			t[i] = nextInt();
			best += t[i];
		}
		
		for (int i = 3; i <= n; i++) {
			if (n % i == 0) {
				int step = n / i;
				for (int j = 0; j < step; j++) {
					int cur = 0;
					for (int k = j; k < n; k += step) {
						cur += t[k];
					}
					best = Math.max(best, cur);
				}
			}
		}
		out.println(best);
		
	}

	void run() {
		try {
			// in = new BufferedReader(new FileReader(filename + ".in"));
			// out = new PrintWriter(filename + ".out");
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
		new IceSculptures().run();
	}

}