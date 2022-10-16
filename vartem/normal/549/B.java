import java.io.*;
import java.util.*;

public class B {

	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();

		int[][] mat = new int[n][n];
		for (int i = 0; i < n; i++) {
			String s = in.nextToken();
			for (int j = 0; j < n; j++) {
				mat[i][j] = s.charAt(j) - '0';
			}
		}
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		int[] deg = new int[n];

		List<Integer> ans = new ArrayList<Integer>();
		while (true) {
			int i = -1;
			for (int j = 0; j < n; j++) {
				if (deg[j] == a[j]) {
					i = j;
					break;
				}
			}
			if (i == -1) {
				break;
			}
			
			ans.add(i);
			for (int j = 0; j < n; j++) {
				deg[j] += mat[i][j];
			}
		}
		
		out.println(ans.size());
		for (int i : ans) {
			out.print((i + 1) + " ");
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
		new B().run();
	}
}