import java.io.*;
import java.util.*;

public class B {

	FastScanner in;
	PrintWriter out;
	final String fileName = "B".toLowerCase();

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		int[] x = new int[m], y = new int[m];
		int[] deg = new int[n];
		
		int maxDeg = 0;
		for (int i = 0; i < m; i++) {
			x[i] = in.nextInt() - 1;
			y[i] = in.nextInt() - 1;
			deg[x[i]]++;
			deg[y[i]]++;
			maxDeg = Math.max(maxDeg, deg[x[i]]);
			maxDeg = Math.max(maxDeg, deg[y[i]]);
		}
		
		if (m > n) {
			out.println("unknown topology");
			return;
		}
		
		if (m == n) {
			if (maxDeg == 2) {
				out.println("ring topology");
			} else {
				out.println("unknown topology");
			}
			return;
		}
		
		if (m == n - 1) {
			if (maxDeg == 2) {
				out.println("bus topology");
			} else if (maxDeg == n - 1) {
				out.println("star topology");
			} else {
				out.println("unknown topology");
			}
			return;
		}
	}

	void run() {
		try {
			in = new FastScanner();
			out = new PrintWriter(System.out);
			solve();
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		String next() {
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
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}

	public static void main(String[] args) {
		new B().run();
	}
}