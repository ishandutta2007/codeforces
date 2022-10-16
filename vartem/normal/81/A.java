import java.io.*;
import java.util.*;

public class Plugin {

	void solve() throws Exception {
		String s = nextToken();
		char[] a = new char[s.length()];
		int head = 0;
		for (int i = 0; i < s.length(); i++) {
			if (head > 0 && s.charAt(i) == a[head - 1]) {
				head--;
			} else {
				a[head++] = s.charAt(i);
			}
		}
		for (int i = 0; i < head; i++) {
			out.print(a[i]);
		}
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
	final String filename = new String("Plugin").toLowerCase();

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
		new Plugin().run();
	}

}