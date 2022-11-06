import java.io.PrintWriter;
import java.util.Scanner;

public class Main {
	static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int N = sc.nextInt();
		int M = sc.nextInt();
		int[] L = new int[M];
		long sum = 0;
		for (int i = 0; i < M; i++) {
			L[i] = sc.nextInt();
			sum += L[i];
		}
		if (sum < N) {
			System.out.println(-1);
			return;
		}
		long sum2 = L[M - 1];
		long[] ans = new long[M];
		ans[M - 1] = 1;
		for (int i = M - 2; i >= 0; i--) {
			if (L[i] > sum2) {
				sum2 = L[i];
				ans[i] = 1;
			} else {
				sum2++;
				ans[i] = sum2 - L[i] + 1;
			}
		}
		if (sum2 > N) {
			System.out.println(-1);
			return;
		}
		long prev = N + 1;
		for (int i = 0; i < M; i++) {
			if (ans[i] + L[i] >= prev) break;
			ans[i] = prev - L[i];
			prev = ans[i];
		}
		PrintWriter writer = new PrintWriter(System.out);
		for (int i = 0; i < M; i++) {
			writer.print(ans[i] + (i == M - 1 ? "\n" : " "));
		}
		writer.flush();
	}

}