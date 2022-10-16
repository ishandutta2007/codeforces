import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.Reader;
import java.util.StringTokenizer;

public class B {

	MyScanner in;
	PrintWriter out;
	final static String filename = "";

	class MyScanner {
		BufferedReader br;
		StringTokenizer st;

		public MyScanner(String filename) {
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
	
	int get(int x, int y) {
		if (x <= 0 || y <= 0)
			return 0;
		if ((x * y) % 2 == 0) 
			return (x * y) / 2;
		else 
			return (x * y + 1) / 2;
	}
	
	void solve() throws IOException {
		int n = in.nextInt();
		int m = in.nextInt();
		int x = in.nextInt();
		int size = 2 * (n + m);
		int[] a = new int[size];
		for (int i = 0; i < size; i++) {
			a[i] = get(n - 2 * i, m - 2 * i);
			if (a[i] == 0) 
				break;
		}
		if (x >= size) 
			out.println(0);
		else 
			out.println(a[x - 1] - a[x]);
	}

	void run() {
		try {
			in = new MyScanner(filename + ".in");
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