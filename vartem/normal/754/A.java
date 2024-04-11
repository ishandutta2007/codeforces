import java.util.*;
import java.io.*;

public class A {

	void solve() {
		int n = in.nextInt();
		int[] a = new int[n];
		int s = 0;
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
			s += a[i];
		}
		if (s != 0) {
			out.println("YES");
			out.println(1);
			out.println(1 + " " + n);
			return;
		}
		
		s = 0;
		for (int i = 0; i < n; i++) {
			s += a[i];
			if (s != 0) {
				out.println("YES");
				out.println(2);
				out.println(1 + " " + (i + 1));
				out.println((i + 2) + " " + n);
				return;
			}
		}
		out.println("NO");
	}

	FastScanner in;
	PrintWriter out;

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
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		public String nextToken() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
				}
			}
			return st.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(nextToken());
		}

		public long nextLong() {
			return Long.parseLong(nextToken());
		}

		public double nextDouble() {
			return Double.parseDouble(nextToken());
		}
	}

	public static void main(String[] args) {
		new A().run();
	}
}