import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class Solution {
	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter out = new PrintWriter(System.out);

		int n = in.nextInt();
		String s = in.next();
		int a[] = new int[n + 1];
		for (int i = 1; i <= n; ++i) {
			a[i] = in.nextInt();
		}

		long ans[][] = new long[n][n];
		long dp[][][][] = new long[n][n][2][n + 1];
		for (int l = 0; l < n; ++l) {
			for (int r = 0; r < n; ++r) {
				for (int c = 0; c < 2; ++c) {
					for (int i = 0; i <= n; ++i) {
						dp[l][r][c][i] = -1;
					}
				}
			}
		}

		for (int len = 1; len <= n; ++len) {
			for (int l = 0; l + len - 1 < n; ++l) {
				int r = l + len - 1;
				ans[l][r] = -1;
				for (int c = 0; c < 2; ++c) {
					for (int i = 1; i <= n; ++i) {
						for (int j = l; j <= r; ++j) {
							if (j < r && dp[j + 1][r][c][i - 1] == -1 || j == r && i > 1 || s.charAt(j) - '0' != c)
								continue;
							long res = (j == l) ? 0 : ans[l][j - 1];
							res += (j == r) ? 0 : dp[j + 1][r][c][i - 1]; 
							dp[l][r][c][i] = max(dp[l][r][c][i], res);
						}
						if (dp[l][r][c][i] != -1) {
							ans[l][r] = max(ans[l][r], a[i] + dp[l][r][c][i]);
						}
					}
				}
				for (int c = 0; c < 2; ++c) {
					dp[l][r][c][0] = ans[l][r];
				}
			}
		}

		out.println(ans[0][n - 1]);
		out.close();
	}
}

class InputReader {
	public BufferedReader read;
	public StringTokenizer token;

	public InputReader(InputStream str) {
		read = new BufferedReader(new InputStreamReader(str), 1 << 15);
	}

	public String next() {
		while (token == null || !token.hasMoreTokens()) {
			try {
				token = new StringTokenizer(read.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return token.nextToken();
	}

	public int nextInt() {
		return Integer.parseInt(next());
	}
}