import java.util.Scanner;

public class Main {
	static Scanner sc = new Scanner(System.in);
	static int N, T;
	static int[] A, hist;

	public static void main(String[] args) {
		N = sc.nextInt();
		T = sc.nextInt();
		A = new int[N];
		hist = new int[301];
		for (int i = 0; i < N; ++i) {
			A[i] = sc.nextInt();
			hist[A[i]]++;
		}
		if (T <= 200) {
			int[][] ans = solve(T);
			int ret = 0;
			for (int v : ans[T]) {
				ret = Math.max(ret, v);
			}
			System.out.println(ret);
			return;
		}
		int[][] first = solve(100);
		int[] rev = new int[N];
		for (int i = 0; i < N; ++i) {
			rev[i] = 301 - A[N - 1 - i];
		}
		A = rev;
		int[][] last = solve(100);
		for (int i = 1; i <= 100; ++i) {
			for (int j = 0; j < 300; ++j) {
				first[i][j + 1] = Math.max(first[i][j + 1], first[i][j]);
				last[i][j + 1] = Math.max(last[i][j + 1], last[i][j]);
			}
		}
		int ans = 0;
		for (int i = 1; i <= 300; ++i) {
			if (hist[i] == 0) continue;
			for (int j = 0; j <= 100; ++j) {
				for (int k = 0; k <= 100; ++k) {
					int v = first[j][i] + hist[i] * (T - j - k) + last[k][301 - i];
					ans = Math.max(ans, v);
				}
			}
		}
		System.out.println(ans);
	}

	static int[][] solve(int rep) {
		int[] v = new int[N * rep];
		for (int i = 0; i < rep; ++i) {
			System.arraycopy(A, 0, v, i * N, N);
		}

		int[] dp = new int[301];
		int[][] ret = new int[rep + 1][];
		ret[0] = new int[301];
		for (int i = 0; i < v.length; ++i) {
			int max = 0;
			for (int j = 1; j <= v[i]; ++j) {
				max = Math.max(max, dp[j]);
			}
			dp[v[i]] = max + 1;
			if ((i + 1) % N == 0) {
				ret[(i + 1) / N] = dp.clone();
			}
		}
		return ret;
	}

}