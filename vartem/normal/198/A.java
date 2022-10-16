import java.io.*;
import java.util.*;

public class Microbes {

	final String filename = new String("Microbes").toLowerCase();

	void solve() throws Exception {
		long k = nextLong();
		long b = nextLong();
		long n = nextLong();
		long t = nextLong();
		long cur = 1;
		long max = n;
		for (int ans = 0; ans <= n ; ans++) {
			if (t >= cur) {
				max = n - ans;
			} else {
				break;
			}
			cur = cur * k + b;
		}
		out.println(max);
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
		new Microbes().run();
	}

}