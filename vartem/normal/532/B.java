import java.io.*;
import java.util.*;

public class B {

	FastScanner in;
	PrintWriter out;

	List<Integer>[] graph;
	int[] a;
	
	long[] go(int v){ 
		List<long[]> children = new ArrayList<long[]>();
		for (int u : graph[v]) {
			children.add(go(u));
		}
		
		long[] ret = new long[2];
		
		// do not take v
		long[] dp = new long[2];
		dp[1] = Long.MIN_VALUE / 4;
		for (long[] l : children) {
			long[] newDP = new long[2];
			
			newDP[0] = Math.max(dp[0] + l[0], dp[1] + l[1]);
			newDP[1] = Math.max(dp[1] + l[0], dp[0] + l[1]);
			dp = newDP;
		}
		
		ret[1] = Math.max(dp[1], a[v] + dp[0]);
		ret[0] = dp[0];
		return ret;
	}
	
	void solve() {
		int n = in.nextInt();
		graph = new List[n];
		int[] p = new int[n];
		a = new int[n];
		for (int i = 0; i < n; i++) {
			graph[i] = new ArrayList<Integer>();
		}
		for (int i = 0; i < n; i++) {
			p[i] = in.nextInt() - 1;
			if (p[i] >= 0) {
				graph[p[i]].add(i);
			}
			a[i] = in.nextInt();
		}
		
		long[] ans = go(0);
		out.println(Math.max(ans[0], ans[1]));
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