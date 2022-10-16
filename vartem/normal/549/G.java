import java.io.*;
import java.util.*;

public class G {

	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		Integer[] a = new Integer[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt() + i;
		}
		
		Arrays.sort(a);
		for (int i = 0; i < n - 1; i++) {
			if (a[i] - i > a[i + 1] - (i + 1)) {
				out.println(":(");
				return;
			}
			if (a[i] - i < 0) {
				out.println(":(");
				return;
			}
		}

		for (int i = 0; i < n; i++) {
			a[i] -= i;
			out.print(a[i] + " ");
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

		public FastScanner(String s) {
			try {
				br = new BufferedReader(new FileReader(s));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		String nextToken() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
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
		new G().run();
	}
}