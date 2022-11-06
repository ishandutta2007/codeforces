import java.io.PrintWriter;
import java.util.Scanner;

public class Main {
	static Scanner sc = new Scanner(System.in);
	static int[] ans = new int[1 << 20];
	static int[] v = new int[1 << 21];
	static int[] spare = new int[1 << 20];
	static int H, G;
	static int ai;

	public static void main(String[] args) {
		int T = sc.nextInt();
		PrintWriter writer = new PrintWriter(System.out);
		for (int i = 0; i < T; i++) {
			writer.println(solve());
			int c = (1 << H) - (1 << G);
			for (int j = 0; j < c; j++) {
				writer.print(ans[j] + (j == c - 1 ? "\n" : " "));
			}
		}
		writer.flush();
	}

	static long solve() {
		H = sc.nextInt();
		G = sc.nextInt();
		ai = 0;
		long sum = 0;
		for (int i = 1; i < (1 << H); i++) {
			v[i] = Integer.parseInt(sc.next());
			sum += v[i];
		}
		setSpare(1, (1 << H) - (1 << G));
		long res = solvePos(1);
		for (int i = 1; i < (1 << H); i++) {
			v[i] = 0;
		}
		return sum - res;
	}

	static long solvePos(int p) {
		long sum = 0;
		while (spare[p] > 0) {
			int cur = p;
			int ng = -1;
//			System.err.println("p:" + p + " cur:" + cur + " v:" + v[cur]);
//			for (int i = 1; i <= 7; i++) {
//				System.err.print(v[i] + " ");
//			}
//			System.err.println();
			while (true) {
				if (v[cur * 2] == 0 && v[cur * 2 + 1] == 0) break;
				if (v[cur * 2] > v[cur * 2 + 1]) {
					cur = cur * 2;
				} else {
					cur = cur * 2 + 1;
				}
				if (spare[cur] == 0 && cur < (1 << G)) {
					ng = cur;
					break;
				}
			}
//			System.err.println("ng:" + ng);
			if (ng == -1) {
				sum += v[p];
				cur = p;
				ans[ai++] = p;
				while (true) {
					if (v[cur * 2] == 0 && v[cur * 2 + 1] == 0) {
						v[cur] = 0;
						break;
					}
					spare[cur]--;
					if (v[cur * 2] > v[cur * 2 + 1]) {
						cur = cur * 2;
					} else {
						cur = cur * 2 + 1;
					}
					v[cur / 2] = v[cur];
				}
			} else {
				while (ng > p) {
					sum += solvePos(ng ^ 1);
					ng /= 2;
				}
				break;
			}
		}
		return sum;
	}

	static void setSpare(int i, int c) {
		spare[i] = c;
		if (c > 1) {
			setSpare(i * 2, c / 2);
			setSpare(i * 2 + 1, c / 2);
		}
	}
}