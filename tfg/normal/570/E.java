import java.io.*;
import java.util.*;

public class e {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		solve(in, out);
		out.close();
	}

	static private void solve(InputReader in, PrintWriter out) {
		final int MOD = (int)1e9 + 7;
		int n = in.nextInt();
		int m = in.nextInt();
		String[] mat = new String[n];
		for(int i = 0; i < n; i++) {
			mat[i] = in.next();
		}
		int size = (n + m) / 2;
		int[][][] dp = new int[2][n][n];
		dp[0][0][0] = 1;
		if(mat[0].charAt(0) != mat[n-1].charAt(m-1)) {
			out.println(0);
			return;
		}
		for(int i = 0; i + 1 < size; i++) {
			for(int j = 0; j < n; j++) {
				Arrays.fill(dp[1][j], 0);
			}
			for(int j = 0; j < n; j++) {
				int x1 = i - j;
				if(x1 >= m || x1 < 0) {
					continue;
				}
				for(int k = 0; k < n; k++) {
					int x2 = (m - 1) - (i - k);
					if(x2 >= m || x2 < 0) {
						continue;
					}
					if(dp[0][j][k] == 0) {
						continue;
					}
					//out.println(i + ": on (" + j + ", " + x1 + ") (" + (n - k - 1) + ", " + x2 + ") got " + dp[0][j][k]);
					if(i + 1 == size) continue;
					if(j + 1 < n) {
						if(k + 1 < n && mat[j+1].charAt(x1) == mat[(n-1)-(k+1)].charAt(x2)) {
							dp[1][j+1][k+1] = (dp[1][j+1][k+1] + dp[0][j][k]) % MOD;
						}
						if(x2 - 1 >= 0 && mat[j+1].charAt(x1) == mat[(n-1)-k].charAt(x2-1)) {
							dp[1][j+1][k] = (dp[1][j+1][k] + dp[0][j][k]) % MOD;
						}
					}
					if(x1 + 1 < m) {
						if(k + 1 < n && mat[j].charAt(x1+1) == mat[(n-1)-(k+1)].charAt(x2)) {
							dp[1][j][k+1] = (dp[1][j][k+1] + dp[0][j][k]) % MOD;
						}
						if(x2 - 1 >= 0 && mat[j].charAt(x1+1) == mat[(n-1)-k].charAt(x2-1)) {
							dp[1][j][k] = (dp[1][j][k] + dp[0][j][k]) % MOD;
						}
					}
				}
			}
			int[][] temp = dp[0];
			dp[0] = dp[1];
			dp[1] = temp;
		}
		int ans = 0;
		if((n + m - 1) % 2 == 0) {
			//out.println("first type");
			for(int j = 0; j < n; j++) {
				int x1 = (size - 1) - j;
				if(x1 < 0 || x1 >= m) {
					continue;
				}
				if(j + 1 < n && mat[j+1].charAt(x1) == mat[j].charAt(x1)) {
					ans = (ans + dp[0][j][n - j - 2]) % MOD;
				}
				if(x1 + 1 < m && mat[j].charAt(x1+1) == mat[j].charAt(x1)) {
					ans = (ans + dp[0][j][n - j - 1]) % MOD;
				}
			}
		} else {
			//out.println("second type");
			for(int j = 0; j < n; j++) {
				ans = (ans + dp[0][j][n - j - 1]) % MOD;
			}
		}
		out.println(ans);
	}

	static class InputReader {
		public BufferedReader reader;
		public StringTokenizer tokenizer;

		public InputReader(InputStream stream) {
			reader = new BufferedReader(new InputStreamReader(stream), 32768);
			tokenizer = null;
		}

		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}
	}
}