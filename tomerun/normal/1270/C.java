import java.util.Scanner;

public class Main {
	static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int T = sc.nextInt();
		for (int i = 0; i < T; i++) {
			long[] ans = solve();
			System.out.println(ans.length);
			for (int j = 0; j < ans.length; j++) {
				System.out.print(ans[j] + (j == ans.length - 1 ? "\n" : " "));
			}
		}
	}

	static long[] solve() {
		int N = sc.nextInt();
		long S = 0;
		long X = 0;
		for (int i = 0; i < N; i++) {
			int A = Integer.parseInt(sc.next());
			S += A;
			X ^= A;
		}
		long[] ret = new long[2];
		ret[0] = X;
		S += X;
		ret[1] = S;
		return ret;
	}
}