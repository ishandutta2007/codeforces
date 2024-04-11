import java.util.*;
import java.io.*;

public class B {

	void solve() {
		char[] c = in.nextToken().toCharArray();
		int best = 0;
		long result = 0;
		for (int i = 0; i <= c.length; i++) {
			char[] d = c.clone();
			if (i < c.length && c[i] > '0') {
				d[i]--;
				for (int j = i + 1; j < c.length; j++) {
					d[j] = '9';
				}
			}
			long val = Long.parseLong(new String(d));
			int sum = Long.toString(val).chars().sum() - '0' * Long.toString(val).length();
			if (sum > best || sum == best && val > result) {
				best = sum;
				result = val;
			}
		}
		out.println(result);
		
	}

	FastScanner in;
	PrintWriter out;

	void run() {
		in = new FastScanner();
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		public FastScanner(String s) {
			try {
				br = new BufferedReader(new FileReader(s));
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		public String nextToken() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
				}
			}
			return st.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(nextToken());
		}

		public long nextLong() {
			return Long.parseLong(nextToken());
		}

		public double nextDouble() {
			return Double.parseDouble(nextToken());
		}
	}

	public static void main(String[] args) {
		new B().run();
	}
}