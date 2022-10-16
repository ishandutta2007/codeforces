import java.util.*;
import java.io.*;

public class C {

	List<Integer>[] tree;
	long[][] cnt, sum;
	long result = 0;
	int k;

	long[] tmpCnt, tmpSum;

	void dfs(int u, int p) {
		cnt[u][0] = 1;
		sum[u][0] = 0;
		for (int t = 0; t < tree[u].size(); t++) {
			int v = tree[u].get(t);
			if (v == p) {
				continue;
			}
			
			dfs(v, u);
			for (int i = 0; i < k; i++) {
				for (int j = 0; j < k; j++) {
					long jumps1 = (sum[u][i] - cnt[u][i] * i) / k;
					long jumps2 = (sum[v][j] - cnt[v][j] * j) / k;
					
					result += jumps1 * cnt[v][j] + jumps2 * cnt[u][i];
					result += (i + j + k - 1) / k * cnt[v][j] * cnt[u][i];
				}
			}
			for (int i = 0; i < k; i++) {
				sum[u][i] += sum[v][i];
				cnt[u][i] += cnt[v][i];
			}
		}
		
		for (int i = 0; i < k; i++) {
			tmpCnt[i] = cnt[u][(i + k - 1) % k];
			tmpSum[i] = sum[u][(i + k - 1) % k] + tmpCnt[i];
		}
		for (int i = 0; i < k; i++) {
			cnt[u][i] = tmpCnt[i];
			sum[u][i] = tmpSum[i];
		}
		
	}

	void solve() {
		int n = in.nextInt();
		k = in.nextInt();
		tree = new List[n];
		for (int i = 0; i < n; i++) {
			tree[i] = new ArrayList<Integer>();
		}
		for (int i = 0; i < n - 1; i++) {
			int from = in.nextInt() - 1, to = in.nextInt() - 1;
			tree[from].add(to);
			tree[to].add(from);
		}
		cnt = new long[n][k];
		sum = new long[n][k];
		tmpCnt = new long[k];
		tmpSum = new long[k];
		
		dfs(0, -1);
		out.println(result);
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