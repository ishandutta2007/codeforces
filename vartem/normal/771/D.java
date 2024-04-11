import java.util.*;
import java.io.*;

public class DStress2 {

	void solve() {
//		stress();
		 int n = in.nextInt();
		 String s = in.nextToken();
		 out.println(solve(s.toCharArray()));
	}

	void stress() {
		Random rng = new Random(123);
		for (int IT = 0; IT < 10000; IT++) {
			int n = 1 + rng.nextInt(12);
			char[] c = new char[n];
			for (int i = 0; i < n; i++) {
				c[i] = "AVK".charAt(rng.nextInt(3));
			}

			int ans1 = solve(c);
			int ans2 = stupid(c);
			if (ans1 != ans2) {
				System.err.println(IT + " " + ans1 + " " + ans2 + " " + new String(c));
				break;
			}
		}
	}

	int INF = Integer.MAX_VALUE / 3;

	int stupid(char[] s) {
		String st = new String(s);
		Queue<String> q = new ArrayDeque<>();
		Map<String, Integer> dist = new HashMap<>();
		q.add(st);
		dist.put(st, 0);
		while (!q.isEmpty()) {
			st = q.poll();
			int cur = dist.get(st);
			if (!st.contains("VK")) {
				return cur;
			}

			for (int pos = 0; pos < st.length() - 1; pos++) {
				String next = st.substring(0, pos) + st.charAt(pos + 1) + st.charAt(pos) + st.substring(pos + 2);
				if (!dist.containsKey(next)) {
					dist.put(next, cur + 1);
					q.add(next);
				}
			}
		}
		return 0;
	}

	int solve(char[] s) {
		List<Integer> vPos = new ArrayList<>(), kPos = new ArrayList<>(), otherPos = new ArrayList<>();

		for (int i = 0; i < s.length; i++) {
			if (s[i] == 'V') {
				vPos.add(i);
			} else if (s[i] == 'K') {
				kPos.add(i);
			} else {
				otherPos.add(i);
			}
		}
		
		int[][][][] dp = new int[2][vPos.size() + 1][kPos.size() + 1][otherPos.size() + 1];
		
		for (int[][][] i : dp) {
			for (int[][] j : i) {
				for (int[] k : j) {
					Arrays.fill(k, INF);
				}
			}
		}
		dp[0][0][0][0] = 0;
		
		for (int V = 0; V <= vPos.size(); V++) {
			for (int K = 0; K <= kPos.size(); K++) {
				for (int O = 0; O <= otherPos.size(); O++) {
					for (int last = 0; last < 2; last++) {
						int cur = dp[last][V][K][O];
						if (cur == INF) {
							continue;
						}
						if (V < vPos.size()) {
							dp[1][V + 1][K][O] = Math.min(dp[1][V + 1][K][O], cur + count(vPos.get(V), K, kPos) + count(vPos.get(V), O, otherPos));
						}
						if (K < kPos.size() && last == 0) {
							dp[0][V][K + 1][O] = Math.min(dp[0][V][K + 1][O], cur + count(kPos.get(K), V, vPos) + count(kPos.get(K), O, otherPos));
						}
						if (O < otherPos.size()) {
							dp[0][V][K][O + 1] = Math.min(dp[0][V][K][O + 1], cur + count(otherPos.get(O), V, vPos) + count(otherPos.get(O), K, kPos));
						}
					}
				}
			}
		}
		
		return Math.min(dp[0][vPos.size()][kPos.size()][otherPos.size()], dp[1][vPos.size()][kPos.size()][otherPos.size()]);
	}

	private int count(Integer integer, int start, List<Integer> kPos) {
		int ans = 0;
		for (int i = start; i < kPos.size(); i++) {
			if (kPos.get(i) < integer) {
				ans++;
			}
		}
		return ans;
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
		new DStress2().run();
	}
}