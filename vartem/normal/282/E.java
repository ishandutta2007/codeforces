import java.io.*;
import java.util.*;

public class E {

	final String filename = new String("E").toLowerCase();

	void solve() throws Exception {
		int n = nextInt();
		long[] a = new long[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextLong();
		}

		long[] pref = new long[n + 1];
		long[] suf = new long[n + 1];

		pref[0] = suf[n] = 0;
		for (int i = 0; i < n; i++) {
			pref[i + 1] = a[i] ^ pref[i];
		}

		for (int i = n - 1; i >= 0; i--) {
			suf[i] = suf[i + 1] ^ a[i];
		}

		Arrays.sort(suf);
		long ans = 0;
		for (long x : pref) {

			long mask = 1L << 40;
			long cur = 0;
			for (int bit = 39; bit >= 0; bit--) {
				mask >>>= 1;

				long tmp = cur;
				if ((x & mask) == 0) {
					tmp |= mask;
				}

				int id = Arrays.binarySearch(suf, tmp);
				if (id < 0) {
					id = (-id - 1);
					if (id > n || Long.highestOneBit(suf[id] ^ tmp) >= mask) {
						tmp ^= mask;
					}
				}
				cur = tmp;
			}
			ans = Math.max(ans, cur ^ x);
		}

		out.println(ans);
	}

	public void run() {
		try {
			// in = new BufferedReader(new FileReader("gen.out"));
			// out = new PrintWriter("output.txt");
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
	PrintWriter out;
	StringTokenizer st;

	String nextToken() throws Exception {
		while (st == null || !st.hasMoreTokens()) {
			st = new StringTokenizer(in.readLine());
		}
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
		new E().run();
	}

}