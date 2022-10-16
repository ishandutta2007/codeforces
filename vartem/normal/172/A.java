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
		int lcp = s[0].length();
		for (int i = 0; i < n - 1; i++) {
			lcp = Math.min(lcp, getLCP(s[i], s[i + 1]));
		}
		out.println(lcp);
	}

	private int getLCP(String string, String string2) {
		int ans = 0;
		while (ans < string.length() && ans < string2.length() && string.charAt(ans) == string2.charAt(ans)) {
			ans++;
		}
		return ans;
	}

	void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			//			in = new BufferedReader(new FileReader("input.txt"));
			//			out = new PrintWriter("output.txt");

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