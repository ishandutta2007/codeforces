import java.text.DecimalFormat;
import java.util.Arrays;
import java.util.Scanner;

public class E {
	static Scanner sc = new Scanner(System.in);
	static int N;
	static double[][] p;
	static DecimalFormat format = new DecimalFormat("0.000000");

	public static void main(String[] args) throws Exception {
		N = sc.nextInt();
		p = new double[N][N];
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				p[i][j] = sc.nextDouble();
			}
		}
		double[] memo = new double[1 << N];
		memo[memo.length - 1] = 1;
		for (int i = N; i >= 2; --i) {
			int[] live = new int[N];
			for (int j = 0; j < i; ++j) {
				live[N - 1 - j] = 1;
			}
			do {
				int n = toInt(live);
				double norm = 2.0 / i / (i - 1);
				for (int f1 = 0; f1 < N; ++f1) {
					if (live[f1] == 0) continue;
					for (int f2 = f1 + 1; f2 < N; ++f2) {
						if (live[f2] == 0) continue;
						memo[n - (1 << f1)] += memo[n] * p[f2][f1] * norm;
						memo[n - (1 << f2)] += memo[n] * p[f1][f2] * norm;
					}
				}
			} while (nextPermutation(live));
			//			System.out.println(Arrays.toString(memo));
		}
		for (int i = 0; i < N; ++i) {
			System.out.print(format.format(memo[1 << i]));
			if (i < N - 1) {
				System.out.print(" ");
			}
		}
	}

	static int toInt(int[] a) {
		int ret = 0;
		for (int i = 0; i < N; ++i) {
			ret += (1 << i) * a[i];
		}
		return ret;
	}

	public static boolean nextPermutation(int[] a) {
		for (int i = a.length - 1; i > 0; --i) {
			if (a[i - 1] < a[i]) {
				int swapIndex = find(a[i - 1], a, i, a.length - 1);
				int temp = a[swapIndex];
				a[swapIndex] = a[i - 1];
				a[i - 1] = temp;
				Arrays.sort(a, i, a.length);
				return true;
			}
		}
		return false;
	}

	private static int find(int dest, int[] a, int s, int e) {
		if (s == e) {
			return s;
		}
		int m = (s + e + 1) / 2;
		return a[m] <= dest ? find(dest, a, s, m - 1) : find(dest, a, m, e);
	}
}