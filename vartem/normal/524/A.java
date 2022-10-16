import java.io.*;
import java.util.*;

public class A {

	FastScanner in;
	PrintWriter out;

	void solve() {
		int m = in.nextInt(), k = in.nextInt();

		Set<Integer> all = new TreeSet<>();

		Map<Integer, Set<Integer>> f = new TreeMap<>();
		for (int i = 0; i < m; i++) {
			int from = in.nextInt(), to = in.nextInt();
			all.add(from);
			all.add(to);

			if (!f.containsKey(from)) {
				f.put(from, new HashSet<>());
			}
			if (!f.containsKey(to)) {
				f.put(to, new HashSet<>());
			}
			f.get(from).add(to);
			f.get(to).add(from);
		}

		for (int key : f.keySet()) {
			Set<Integer> ans = new TreeSet<>();

			for (int other : f.keySet()) {
				if (key == other || f.get(key).contains(other)) {
					continue;
				}

				Set<Integer> s1 = new TreeSet<>(f.get(key));
				s1.retainAll(f.get(other));
				if (s1.size() * 100 >= f.get(key).size() * k) {
					ans.add(other);
				}
			}
			out.print(key + ": ");
			out.print(ans.size());
			for (int i : ans) {
				out.print(" " + i);
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
		new A().run();
	}
}