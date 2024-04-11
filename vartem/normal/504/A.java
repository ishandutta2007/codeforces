import java.io.*;
import java.util.*;

public class A {

	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		int[] deg = new int[n], xor = new int[n];
		for (int i = 0; i < n; i++) {
			deg[i] = in.nextInt();
			xor[i] = in.nextInt();
		}

		TreeSet<Vertex> ts = new TreeSet<>();
		Vertex[] vs = new Vertex[n];
		for (int i = 0; i < n; i++) {
			vs[i] = new Vertex(i, xor[i], deg[i]);
			ts.add(vs[i]);
		}

		List<Integer> as = new ArrayList<>(), bs = new ArrayList<>();

		while (ts.size() > 0) {
			Vertex v = ts.pollFirst();
			if (v.deg == 0) {
				if (v.xor != 0) {
					throw new AssertionError();
				}
				continue;
			}
			
			if (v.deg != 1) {
				throw new AssertionError();
			}
			
			int neigh = v.xor;
			as.add(v.id);
			bs.add(neigh);
			
			ts.remove(vs[neigh]);
			vs[neigh].deg--;
			vs[neigh].xor ^= v.id;
			ts.add(vs[neigh]);
		}
		
		out.println(as.size());
		for (int i = 0; i < as.size(); i++) {
			out.println(as.get(i) + " " + bs.get(i));
		}
	}

	class Vertex implements Comparable<Vertex> {
		int id, xor, deg;

		public Vertex(int id, int xor, int deg) {
			super();
			this.id = id;
			this.xor = xor;
			this.deg = deg;
		}

		@Override
		public int compareTo(Vertex o) {
			if (deg != o.deg) {
				return Integer.compare(deg, o.deg);
			}
			return Integer.compare(id, o.id);
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