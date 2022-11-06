import java.io.PrintWriter;
import java.util.Scanner;

public class Main {
	static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int T = sc.nextInt();
		PrintWriter writer = new PrintWriter(System.out);
		for (int i = 0; i < T; i++) {
			writer.println(solve());
		}
		writer.flush();
	}

	static long solve() {
		int N = sc.nextInt();
		long[] A = new long[N + 1];
		long[] B = new long[N + 1];
		for (int i = 0; i < N; i++) {
			A[i] = Long.parseLong(sc.next());
			B[i] = Long.parseLong(sc.next());
		}
		A[N] = A[0];
		B[N] = B[0];
		long sum = 0;
		long min = Long.MAX_VALUE;
		for (int i = 0; i < N; i++) {
			sum += Math.max(0, A[i + 1] - B[i]);
			min = Math.min(min, Math.min(A[i + 1], B[i]));
		}
		return sum + min;
	}

}