import java.io.*;
import java.util.*;

public class C {

	final String filename = new String("C").toLowerCase();

	class Pair implements Comparable<Pair> {
		long k, c;

		public Pair(long k, long c) {
			super();
			this.k = k;
			this.c = c;
		}

		@Override
		public int compareTo(Pair o) {
			return Long.signum(c - o.c);
		}
	}

	void solve() throws Exception {
		int n = nextInt();
		Pair[] a = new Pair[n];
		for (int i = 0; i < n; i++) {
			a[i] = new Pair(nextInt(), nextInt());
		}
		Arrays.sort(a);
		int t = nextInt();
		long[] p = new long[t + 1];
		for (int i = 0; i < t; i++) {
			p[i] = nextLong();
		}
		p[t] = Long.MAX_VALUE;
		long curCount = 0;
		long ans = 0;
		int j = 0;
		for (int i = 0; i < n; ) {
			long nextCount = Math.min(p[j], curCount + a[i].k);
			ans += (long) (nextCount - curCount) * (long) a[i].c * (j + 1);
			if (nextCount == p[j]) {
				j++;
			}
			if (nextCount - curCount == a[i].k) {
				i++;
			} else {
				a[i].k -= nextCount - curCount;
			}
			curCount = nextCount;
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
		new C().run();
	}

}