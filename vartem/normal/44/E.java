import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class E {

	MyScanner in;
	PrintWriter out;
	final static String filename = "";

	class MyScanner {
		BufferedReader br;
		StringTokenizer st;

		public MyScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		String next() {
			try {

				while (st == null || !st.hasMoreTokens())
					st = new StringTokenizer(br.readLine());
				return st.nextToken();

			} catch (IOException e) {
				e.printStackTrace();
				return null;
			}

		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		void close() {
			try {
				br.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}

	int n;
	int[][] pr;
	String s;
	
	void print(int n, int k) {
		if (n == 0) return;
		print(pr[n][k], k - 1);
		for (int i = pr[n][k] + 1; i <= n; i++)
			out.print(s.charAt(i - 1));
		out.println();
	}

	void solve() throws IOException {
		int k = in.nextInt();
		int a = in.nextInt();
		int b = in.nextInt();
		s = in.next();
		int size = s.length();
		boolean[][] g = new boolean[size + 1][k + 1];
		pr = new int[size + 1][k + 1];
		g[0][0] = true;
		for (int i = 1; i <= size; i++) {
			for (int j = 1; j <= k; j++) {
				for (int l = a; l <= b; l++) {
					if (i - l < 0) continue;
					if (g[i - l][j - 1] == true) {
						g[i][j] = true;
						pr[i][j] = i - l;
					}
				}
			}
		}
		
		if (g[size][k] == false) {
			out.println("No solution");
			return;
		}
		
		print(size, k);
	}

	void run() {
		try {
			in = new MyScanner();
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
		new E().run();
	}

}