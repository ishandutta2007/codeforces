import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class H {

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
	String s;

	void solve() throws IOException {
		String s = in.next();
		int size = s.length();
		int[] a = new int[size];
		for (int i = 0; i < size; i++)
			a[i] = (int)(s.charAt(i) - '0');
		long[][] b = new long[size][10];
		for (int i = 0; i < 10; i++)
			b[0][i] = 1;
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < 10; j++) {
				if ((j + a[i + 1]) % 2 == 1) {
					b[i + 1][(j + a[i + 1]) / 2] += b[i][j];
					b[i + 1][(j + a[i + 1] + 1) / 2] += b[i][j];
				} else {
					b[i + 1][(j + a[i + 1]) / 2] += b[i][j];
				}
			}
		}
		
		long sum = 0;
		for (int i = 0; i < 10; i++) 
			sum += b[size - 1][i];
		
		boolean f = true;
		for (int i = 1; i < size; i++)
			if ((a[i] + a[i - 1]) / 2 != a[i] && ((a[i] + a[i - 1] + 1) / 2 != a[i]))
				f = false;
			
		if (f == true)
			sum--;
		out.println(sum);
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
		new H().run();
	}

}