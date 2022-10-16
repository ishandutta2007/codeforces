import java.util.*;
import java.io.*;

public class A {

	List<Integer>[] graph;

	int[] result;
	
	void go(int u, int p, int color) {
		int lastColor = 1;
		result[u] = color;
		for (int t = 0; t < graph[u].size(); t++) {
			int v = graph[u].get(t);
			if (v == p) {
				continue;
			}
			while (lastColor == color || (p != -1 && lastColor == result[p])) {
				lastColor++;
			}
			go(v, u, lastColor);
			lastColor++;
		}
	}
	
	void solve() {
		int n = in.nextInt();
		graph = new List[n];
		for (int i = 0; i < n; i++) {
			graph[i] = new ArrayList<>();
		}
		for (int i = 0; i < n - 1; i++) {
			int from = in.nextInt() - 1, to = in.nextInt() - 1;
			graph[from].add(to);
			graph[to].add(from);
		}
		int max = 0;
		for (int i = 1; i < n; i++) {
			if (graph[i].size() > graph[max].size()) {
				max = i;
			}
		}
		result = new int[n];
		out.println(graph[max].size() + 1);
		go(max, -1, 1);
		for (int i = 0; i < n; i++) {
			out.print(result[i] + " ");
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
		new A().run();
	}
}