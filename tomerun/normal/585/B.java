import java.util.Scanner;

public class Main {
	static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int T = sc.nextInt();
		for (int i = 0; i < T; ++i) {
			System.out.println(solve() ? "YES" : "NO");
		}
	}

	static boolean solve() {
		int N = sc.nextInt();
		int K = sc.nextInt();
		boolean[][] f = new boolean[3][N + 3];
		boolean[][] dp = new boolean[N + 1][3];
		for (int i = 0; i < 3; ++i) {
			String row = sc.next();
			for (int j = 0; j < N; ++j) {
				f[i][j] = row.charAt(j) != '.' && row.charAt(j) != 's';
			}
			if (row.charAt(0) == 's') dp[0][i] = true;
		}
		for (int i = 0; i < (N + 2) / 3; ++i) {
			boolean ok = false;
			int col = i * 3;
			for (int j = 0; j < 3; ++j) {
				if (!dp[i][j]) continue;
				ok = true;
				if (f[j][col + 1]) continue;
				if (!f[j][col + 2] && !f[j][col + 3]) dp[i + 1][j] = true;
				if (j > 0 && !f[j - 1][col + 1] && !f[j - 1][col + 2] && !f[j - 1][col + 3]) dp[i + 1][j - 1] = true;
				if (j < 2 && !f[j + 1][col + 1] && !f[j + 1][col + 2] && !f[j + 1][col + 3]) dp[i + 1][j + 1] = true;
			}
			if (!ok) return false;
		}
		return dp[(N + 2) / 3][0] || dp[(N + 2) / 3][1] || dp[(N + 2) / 3][2];
	}
}