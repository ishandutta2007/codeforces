import java.util.Scanner;

public class Main {
	static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int T = sc.nextInt();
		for (int i = 0; i < T; i++) {
			System.out.println(solve());
		}
	}

	static long solve() {
		long A = sc.nextLong();
		long K = sc.nextLong();
		for (long i = 0; i < K - 1; i++) {
			long min = 9;
			long max = 0;
			long v = A;
			while (v > 0) {
				long d = v % 10;
				min = Math.min(min, d);
				max = Math.max(max, d);
				v /= 10;
			}
			if (min == 0) break;
			A += min * max;
		}
		return A;
	}

}