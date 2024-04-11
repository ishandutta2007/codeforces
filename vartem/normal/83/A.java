import java.io.*;
import java.util.*;

public class Array {

	void solve() throws Exception {
		int n = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < a.length; i++) {
			a[i] = nextInt();
		}
		long ans = 0;
		int i =0;
		while (i < n) {
			int j = i;
			while (j + 1 < n && a[j + 1] == a[i])
				j++;
			long k = j - i + 1;
			ans += (k * (k + 1)) / 2;
			i = j + 1;
		}
		out.println(ans);
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
	final String filename = new String("Array").toLowerCase();

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
		new Array().run();
	}

}