import java.io.*;
import java.util.*;

public class Distance {

	final String filename = new String("Distance").toLowerCase();

	long ans = 0;
	int k;
	
	ArrayList<Integer>[] graph;

	int[] dfs(int u, int par) {
		int[] count = new int[k + 1];
		
		for (int v : graph[u]) {
			if (v != par) {
				int[] res = dfs(v, u);
				
				for (int i = 0; i <= k; i++) {
					ans += (long) res[i] * (long) count[k - i];
				}
				for (int i = 0; i <= k; i++) {
					count[i] += res[i];
				}
			}
		}
		ans += count[k];
		for (int i = k; i > 0; i--) {
			count[i] = count[i - 1];
		}
		count[1] = 1;
		return count;
	}

	void solve() throws Exception {
		int n = nextInt();
		k = nextInt();
		graph = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			graph[i] = new ArrayList<Integer>();
		}
		for (int i = 0; i < n - 1; i++) {
			int x = nextInt() - 1;
			int y = nextInt() - 1;
			graph[x].add(y);
			graph[y].add(x);
		}
		dfs(0, -1);
		out.println(ans);
	}

	void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			// in = new BufferedReader(new FileReader("input.txt"));
			// out = new PrintWriter("output.txt");

			solve();

			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	BufferedReader in;
	StringTokenizer st;
	PrintWriter out;

	String nextToken() throws Exception {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}

	int nextInt() throws Exception {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws Exception {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws Exception {
		return Double.parseDouble(nextToken());
	}

	public static void main(String[] args) {
		new Distance().run();
	}

}