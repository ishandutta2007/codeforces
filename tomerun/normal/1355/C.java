import java.util.Scanner;

public class Main {
	static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		long A = sc.nextInt();
		long B = sc.nextInt();
		long C = sc.nextInt();
		long D = sc.nextInt();
		long ans = 0;
		long cur = 0;
		for (long d = Math.max(D, B + C); d >= C; --d) {
			if (d <= D) ans += cur;
//			System.err.println("d;" + d + " cur:" + cur + " ans:" + ans);
			if (d >= Math.max(A + C, 2 * B)) {
				cur += Math.max(0, B + C - d + 1);
			} else if (d < A + B) {
				// add 0
			} else if (d <= Math.min(A + C, 2 * B)) {
				cur += d - (A + B) + 1;
			} else {
				cur += Math.min(B - A, C - B) + 1;
			}
		}
//		long brute = 0;
//		for (long i = A; i <= B; i++) {
//			for (long j = B; j <= C; ++j) {
//				for (long k = C; k <= D; k++) {
//					if (i + j > k) ++brute;
//				}
//			}
//		}
//		System.err.println("naive:" + brute);
		System.out.println(ans);
	}


}