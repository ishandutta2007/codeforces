import java.io.*;
import java.util.*;

public class D {

	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		int k = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n - 1; i++) {
			a[i] = 1;
		}
		
		for (int outer = 0; outer < k; outer++) {
			
			for (int i = 0; i < n; i++) {
				int need = n - i - 1;
				if (2 * a[i] <= need) {
					a[i] *= 2;
					out.print((i + 1) + " ");
					continue;
				}
				int rmn = need - a[i];
				a[i] += rmn;
				out.print((n - rmn) + " ");
			}
			
			out.println();
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
		new D().run();
	}
}