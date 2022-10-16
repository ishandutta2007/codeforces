import java.io.*;
import java.util.*;

public class A {

	FastScanner in;
	PrintWriter out;

	int gcd(int a, int b) {
		if (a == 0) {
			return b;
		}
		return gcd(b % a, a);
	}
	
	void solve() {
		int n = in.nextInt();
		int[] a = new int[n];
		int g = 0;
		int max = 0;
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
			g = gcd(a[i], g);
			max = Math.max(a[i], max);
		}
		
		int count = max / g;
		int moves = count - n;
		if (moves % 2 == 1) {
			out.println("Alice");
		} else {
			out.println("Bob");
		}
	}

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

		String nextToken() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(nextToken());
		}

		long nextLong() {
			return Long.parseLong(nextToken());
		}

		double nextDouble() {
			return Double.parseDouble(nextToken());
		}
	}

	public static void main(String[] args) {
		new A().run();
	}
}