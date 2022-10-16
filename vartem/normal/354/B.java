import java.io.*;
import java.util.*;

public class B {

	final int INF = Integer.MAX_VALUE / 2;

	public void solve() {
		int n = in.nextInt();
		char[][] c = new char[n][n];
		for (int i = 0; i < n; i++) {
			c[i] = in.nextToken().toCharArray();
		}

		if (n == 1) {
			if (c[0][0] == 'a') {
				out.println("FIRST");
			} else if (c[0][0] == 'b') {
				out.println("SECOND");
			} else {
				out.println("DRAW");
			}
			return;
		}

		int[][] diagNum = new int[n][n];
		for (int diag = 0; diag <= 2 * (n - 1); diag++) {
			int curNum = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (i + j == diag) {
						diagNum[i][j] = curNum;
						curNum++;
					}
				}
			}
		}

		int[] cx = new int[n], cy = new int[n];
		char[] chars = new char[n];

		boolean[] canMove = new boolean[26];

		int[] dp = new int[1 << n], prevDp = new int[1 << n];
		Arrays.fill(dp, INF);
		Arrays.fill(prevDp, INF);
		
		if (c[n - 1][n - 1] == 'a') {
			dp[1] = 1;
		} else if (c[n - 1][n - 1] == 'b') {
			dp[1] = -1;
		} else {
			dp[1] = 0;
		}
		
		int[][] add = new int[26][2];
		add[0][0] = add[1][1] = 1;
		add[0][1] = add[1][0] = -1;
		for (int diag = 2 * n - 3; diag >= 0; diag--) {
			int curCount = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (i + j == diag) {
						cx[curCount] = i;
						cy[curCount] = j;
						chars[curCount] = c[i][j];
						curCount++;
					}
				}
			}

			for (int mask = 1; mask < (1 << curCount); mask++) {
				int bit = -1;
				boolean skip = false;
				for (int j = 0; j < curCount; j++) {
					if ((mask & (1 << j)) != 0) {
						if (bit == -1) {
							bit = j;
						} else {
							if (chars[bit] != chars[j]) {
								skip = true;
							}
						}
					}
				}
				int ourMove = chars[bit] - 'a';
				if (skip) {
					continue;
				}

				Arrays.fill(canMove, false);

				for (int j = 0; j < curCount; j++) {
					if ((mask & (1 << j)) != 0) {
						int x = cx[j], y = cy[j];

						if (x + 1 < n) {
							canMove[c[x + 1][y] - 'a'] = true;
						}
						if (y + 1 < n) {
							canMove[c[x][y + 1] - 'a'] = true;
						}
					}
				}

				for (int move = 0; move < 26; move++) {
					if (canMove[move]) {

						int newMask = 0;
						for (int j = 0; j < curCount; j++) {
							if ((mask & (1 << j)) != 0) {
								int x = cx[j], y = cy[j];

								if (x + 1 < n && c[x + 1][y] - 'a' == move) {
									newMask |= (1 << diagNum[x + 1][y]);
								}
								if (y + 1 < n && c[x][y + 1] - 'a' == move) {
									newMask |= (1 << diagNum[x][y + 1]);
								}
							}
						}
						
						prevDp[mask] = Math.min(prevDp[mask], -dp[newMask] + add[ourMove][diag & 1]);
					}
				}
			}
			
			System.arraycopy(prevDp, 0, dp, 0, prevDp.length);
			Arrays.fill(prevDp, INF);
		}
		
		int ans = dp[1];
//		System.err.println(ans);
		if (ans == 0){ 
			out.println("DRAW");
		} else if (ans > 0) {
			out.println("FIRST");
		} else {
			out.println("SECOND");
		}
	}

	FastScanner in;
	PrintWriter out;

	public void run() {
		try {
			in = new FastScanner();
			out = new PrintWriter(System.out);
//			long time = System.currentTimeMillis();
			solve();
//			System.err.println(System.currentTimeMillis()-  time);
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		public FastScanner(String name) {
			try {
				br = new BufferedReader(new FileReader(name));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		public String nextToken() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
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
		new B().run();
	}
}