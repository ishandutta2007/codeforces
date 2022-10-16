import java.io.*;
import java.util.*;

public class B {

	FastScanner in;
	PrintWriter out;

	class Edge implements Comparable<Edge> {
		int weight, from, to;
		boolean in;
		public Edge(int weight, boolean in) {
			super();
			this.weight = weight;
			this.in = in;
		}
		
		@Override
		public int compareTo(Edge o) {
			if (weight == o.weight) {
				return -Boolean.compare(in, o.in);
			}
			return Integer.compare(weight, o.weight);
		}
	}
	
	void solve() {
		int n = in.nextInt(), m = in.nextInt();
		Edge[] edges = new Edge[m];

		for (int i = 0 ;i < m; i++) {
			edges[i] = new Edge(in.nextInt(), in.nextInt() == 1);
		}
		Edge[] ans = edges.clone();
		
		
		Arrays.sort(edges);
		
		int last = 0;
		
		List<Integer> ans1 = new ArrayList<>(), ans2 = new ArrayList<>();
		
		for (Edge e : edges) {
			if (!e.in) {
				if (ans1.isEmpty()) {
					out.println(-1);
					return;
				}
				
				e.from = ans1.remove(ans1.size() - 1);
				e.to = ans2.remove(ans2.size() - 1);
			} else {
				e.from = last;
				e.to = last + 1;
				for (int i = 0; i < last; i++) {
					if (ans1.size() >= m) {
						break;
					}
					ans1.add(i);
					ans2.add(last + 1);
				}
				last++;
			}
		}
		
		for (Edge e : ans) {
			out.println((e.from + 1) +" " + (e.to + 1));
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