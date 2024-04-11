import java.util.Arrays;
import java.util.Scanner;

public class Main {
	static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int N = sc.nextInt();
		int H = sc.nextInt();
		int[] A = new int[N];
		for (int i = 0; i < N; i++) {
			A[i] = sc.nextInt();
		}
		for (int i = 3; i <= N; i++) {
			if (!ok(A, H, i)) {
				System.out.println(i - 1);
				return;
			}
		}
		System.out.println(N);
	}

	static boolean ok(int[] A, int H, int k) {
		Arrays.sort(A, 0, k);
		long h = 0;
		for (int i = k - 1; i >= 0; i -= 2) {
			h += A[i];
		}
		return h <= H;
	}
}