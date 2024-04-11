import java.util.*;
import java.io.*;

public class C {

	List<Integer>[] tree;
	
	long mod = 1000000007;
	
	long[][][] dp;
	int k, x, m;
	
	long[] newDp;
	long[] curDp;
	
	void dfs(int u, int p) {
		for (int v : tree[u]) {
			if (v != p) {
				dfs(v, u);
			}
		}
		
		for (int col = 0; col < 3; col++) {
			Arrays.fill(curDp, 0);
			curDp[col == 1 ? 1 : 0] = (col == 1 ? 1 : (col == 0 ? (k - 1) : (m - k)));
			
			for (int v : tree[u]) {
				if (v != p) {
					for (int chCol = 0; chCol < 3; chCol++) {
						if (col == 1 && chCol >= 1) {
							continue;
						}
						if (col == 2 && chCol == 1) {
							continue;
						}
						long[] chDp = dp[v][chCol];
						
						for (int sz = 0; sz <= x; sz++) {
							long val = curDp[sz];
							if (val == 0) {
								continue;
							}
							for (int chSz = 0; chSz + sz <= x; chSz++) {
								newDp[sz + chSz] += val * chDp[chSz] % mod;
								if (newDp[sz + chSz] >= mod) {
									newDp[sz + chSz] -= mod;
								}
							}
						}
					}
					System.arraycopy(newDp, 0, curDp, 0, curDp.length);
					Arrays.fill(newDp, 0);
				}
			}
			System.arraycopy(curDp, 0, dp[u][col], 0, curDp.length);
		}
	}
	
	void solve() {
		int n = in.nextInt();
		m = in.nextInt();
		tree  = new List[n];
		for (int i = 0; i < n; i++) {
			tree[i] = new ArrayList<>();
		}
		for (int i = 0; i < n - 1; i++) {
			int from = in.nextInt() - 1, to = in.nextInt()  -1;
			tree[from].add(to);
			tree[to].add(from);
		}
		k = in.nextInt();
		x = in.nextInt();
		dp = new long[n][3][x + 1];
		newDp = new long[x + 1];
		curDp = new long[x + 1];
		dfs(0, -1);
		
		long result = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j <= x; j++) {
				result += dp[0][i][j];
			}
		}
		out.println(result % mod);
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