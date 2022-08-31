import java.util.*;
import java.io.*;

public class C {

	class Pair implements Comparable<Pair> {
		int a, b;

		public Pair(int a, int b) {
			super();
			this.a = a;
			this.b = b;
		}
		
		@Override
		public int compareTo(Pair o) {
			return Integer.compare(a, o.a);
		}
	}
	
	void solve() {
		int n = in.nextInt();
		int[] a = new int[n + 1];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		a[n] = a[0];
		
		Pair[] b = new Pair[n];
		for (int i = 0; i < n; i++) {
			b[i] = new Pair(n - a[i] - a[i + 1], i);
		}
		Arrays.sort(b);
		int[] ans = new int[n];
		int tmp = 0;
		for (int i = n - 1; i >= 0; i--) {
			ans[b[i].b] = tmp++;
		}
		for (int i = 0; i < n; i++) {
			out.print(ans[i] + " ");
		}
		out.println();
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
		new C().run();
	}
}