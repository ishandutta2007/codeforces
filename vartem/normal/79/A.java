import java.io.*;
import java.util.*;

public class Game {

	MyScanner in;
	PrintWriter out;
	final static String filename = new String("Game").toLowerCase();

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
		int m = in.nextInt();
		int c = 0;
		while (100 * n + 10 * m >= 220 && m >= 2) {
			if (c % 2 == 0) {
				if (n >= 2) {
					n -= 2;
					m -= 2;
				} else if (n == 1) {
					n--;
					m -= 12;
				} else {
					m -= 22;
				}
			} else {
				if (m >= 22) {
					m -= 22;
				} else if (m >= 12) {
					m -= 12;
					n--;
				} else {
					n -= 2;
					m -= 2;
				}
			}
			
			c++;
		}
		
		if (c % 2 == 0) {
			out.println("Hanako");
		} else {
			out.println("Ciel");
		}
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
		new Game().run();
	}

}