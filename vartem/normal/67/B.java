import java.io.*;
import java.util.*;

public class B {

	MyScanner in;
	PrintWriter out;
	final static String filename = "";

	class MyScanner {
		BufferedReader br;
		StringTokenizer st;

		public MyScanner(String file) {
			try {
				br = new BufferedReader(new FileReader(file));
				st = new StringTokenizer("");
			} catch (FileNotFoundException e) {
				e.printStackTrace();
				System.exit(1);
			}
		}

		public MyScanner(InputStream is) {
			br = new BufferedReader(new InputStreamReader(is));
			st = new StringTokenizer("");
		}

		String nextToken() {
			try {
				while (st == null || !st.hasMoreTokens())
					st = new StringTokenizer(br.readLine());

			} catch (IOException e) {
				e.printStackTrace();
				System.exit(1);
			}

			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(this.nextToken());
		}

		double nextDouble() {
			return Double.parseDouble(this.nextToken());
		}

		long nextLong() {
			return Long.parseLong(this.nextToken());
		}

		void close() throws IOException {
			br.close();
		}
	}

	int[] a;
	int n;

	void solve() throws IOException {
		n = in.nextInt();
		int k = in.nextInt();
		int[] b = new int[n];
		a = new int[n];
		for (int i = 0; i < n; i++)
			b[i] = in.nextInt();
		boolean[] used = new boolean[n];
		for (int i = 0; i < n; i++) {
			int t = -1;
			for (int j = 0; j < n; j++)
				if (b[j] == 0 && !used[j]) {
					t = j;
					break;
				}
			used[t] = true;
			a[i] = t;
			for (int j = 0; j < n; j++)
				if (j + k <= t)
					b[j]--;
		}
		for (int i = 0; i < n; i++)
			out.print((a[i] + 1) + " ");
	}

	void run() {
		try {
			in = new MyScanner(System.in);
			out = new PrintWriter(System.out);

			solve();

			in.close();
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(1);
		}

	}

	public static void main(String[] args) {
		new B().run();
	}

}