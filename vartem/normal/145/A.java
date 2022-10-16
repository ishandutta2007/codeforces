import java.io.*;
import java.util.*;

public class A {

	final String filename = new String("A").toLowerCase();

	void solve() throws Exception {
		String a = nextToken();
		String b = nextToken();
		int n = a.length();
		int cnt1 = 0;
		int cnt2 = 0;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (a.charAt(i) == b.charAt(i)) {
				cnt++;
				continue;
			}
			if (a.charAt(i) == '4')
				cnt1++;
			if (b.charAt(i) == '4')
				cnt2++;
		}
		int rem = n - cnt;
		out.println(Math.abs(cnt1 - cnt2) + (rem - Math.abs(cnt1 - cnt2)) / 2);
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