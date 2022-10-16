import java.io.*;
import java.util.*;

public class C {

	FastScanner in;
	PrintWriter out;

	class Conjunction implements Comparable<Conjunction> {
		int[] vars;
		int size;
		int id;

		@Override
		public int compareTo(Conjunction o) {
			if (size != o.size) {
				return Integer.compare(size, o.size);
			}
			return Integer.compare(id, o.id);
		}

		@Override
		public String toString() {
			return "Conjunction [vars=" + Arrays.toString(vars) + ", size="
					+ size + ", id=" + id + "]";
		}
	}

	void solve() {
		int n = in.nextInt(), m = in.nextInt();
		List<Integer>[] con = new List[n];
		for (int i = 0; i < n; i++) {
			con[i] = new ArrayList<>();
		}
		List<Integer>[] occ = new List[m];
		for (int i = 0; i < occ.length; i++) {
			occ[i] = new ArrayList<Integer>();
		}

		for (int i = 0; i < n; i++) {
			int k = in.nextInt();
			for (int j = 0; j < k; j++) {
				int var = in.nextInt();
				con[i].add(var);
				if (var > 0) {
					occ[var - 1].add(i + 1);
				} else {
					occ[-var - 1].add(-i - 1);
				}
			}
		}

		int[] ans = new int[m];
		Arrays.fill(ans, -1);

		TreeSet<Conjunction> conjs = new TreeSet<>();
		Conjunction[] all = new Conjunction[n];
		for (int i = 0; i < n; i++) {
			Conjunction c = new Conjunction();
			all[i] = c;
			c.id = i;
			c.size = con[i].size();
			c.vars = new int[con[i].size()];
			for (int j = 0; j < con[i].size(); j++) {
				c.vars[j] = con[i].get(j);
			}
			conjs.add(c);
		}

		boolean[] sat = new boolean[n];
		while (conjs.size() > 0) {
			Conjunction conj = conjs.pollFirst();
			if (conj.size == 0) {
				out.println("NO");
				return;
			}

			int var = -1;
			for (int j = 0; j < conj.vars.length; j++) {
				if (ans[Math.abs(conj.vars[j]) - 1] == -1) {
					var = conj.vars[j];
					break;
				}
			}
			if (var > 0) {
				ans[var - 1] = 1;
			} else {
				ans[-var - 1] = 0;
			}
			for (int t = 0; t < occ[Math.abs(var) - 1].size(); t++) {
				int id = occ[Math.abs(var) - 1].get(t);
				conjs.remove(all[Math.abs(id) - 1]);
				if (Integer.signum(id) == Integer.signum(var) || sat[Math.abs(id) - 1]) {
					sat[Math.abs(id) - 1] = true;
					continue;
				} else {
					all[Math.abs(id) - 1].size--;
					conjs.add(all[Math.abs(id) - 1]);
				}
			}
		}
		for (int i = 0; i < m; i++) {
			if (ans[i] == -1) {
				ans[i] = 0;
			}
		}
		out.println("YES");
		for (int i : ans) {
			out.print(i);
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
		new C().run();
	}
}