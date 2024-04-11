import java.util.*;
import java.io.*;

public class B {

	void solve() {
		int n = in.nextInt(), m = in.nextInt();
		Set<String> a = new HashSet<>(), b = new HashSet<>();
		for (int i = 0; i < n; i++) {
			a.add(in.nextToken());
		}
		for (int i = 0; i < m; i++) {
			b.add(in.nextToken());
		}
		
		Set<String> inter = new HashSet<>(a);
		inter.retainAll(b);
		
		int aa = a.size() + (inter.size() + 1) / 2;
		int bb = b.size() + inter.size() / 2;
		
		if (aa > bb) {
			out.println("YES");
		} else {
			out.println("NO");
		}
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
		new B().run();
	}
}