import java.io.*;
import java.util.*;

public class F {

	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt(), T = in.nextInt();
		
		List<Integer>[] vals = new List[T + 1];
		for (int i = 1; i <= T; i++) {
			vals[i] = new ArrayList<>();
		}
		for (int i = 0; i < n; i++) {
			int t = in.nextInt(), q = in.nextInt();
			vals[t].add(q);
		}
		
		for (int t = 1; t < T; t++) {
			Collections.sort(vals[t]);
			Collections.reverse(vals[t]);
			
			for (int i = 0; i < vals[t].size(); i += 2) {
				if (i + 1 < vals[t].size()) {
					int newVal = vals[t].get(i) + vals[t].get(i + 1);
					vals[t + 1].add(newVal);
				} else {
					vals[t + 1].add(vals[t].get(i));
				}
			}
		}
		
		Collections.sort(vals[T]);
		Collections.reverse(vals[T]);
		out.println(vals[T].get(0));
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
		new F().run();
	}
}