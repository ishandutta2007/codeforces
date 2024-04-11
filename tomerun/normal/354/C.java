import java.util.Scanner;

public class C {

	static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int N = sc.nextInt();
		int K = sc.nextInt();
		int[] A = new int[N];
		sc.nextLine();
		String[] elems = sc.nextLine().split(" ");
		int min = Integer.MAX_VALUE;
		int max = 0;
		for (int i = 0; i < N; ++i) {
			A[i] = Integer.parseInt(elems[i]);
			min = Math.min(min, A[i]);
			max = Math.max(max, A[i]);
		}

		if (min <= K) {
			System.out.println(min);
			return;
		}

		// answer is in [K, min]
		int[] acc = new int[max + 2];
		for (int i = 0; i < N; ++i) {
			acc[Math.max(1, A[i] - K)]++;
			acc[A[i] + 1]--;
		}
		for (int i = 1; i < acc.length; ++i) {
			acc[i] += acc[i - 1];
		}
		for (int i = min; i > K; --i) {
			int c = 0;
			for (int j = i; j <= max; j += i) {
				c += acc[j];
			}
			if (c == N) {
				System.out.println(i);
				return;
			}
		}
		System.out.println(K);
	}
}