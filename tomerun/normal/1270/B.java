import java.util.Scanner;

public class Main {
	static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int T = sc.nextInt();
		for (int i = 0; i < T; i++) {
			int[] ans = solve();
			if (ans == null) {
				System.out.println("NO");
			} else {
				System.out.println("YES");
				System.out.println((ans[0]+1) + " " + (ans[1]+1));
			}
		}
	}

	static int[] solve() {
		int N = sc.nextInt();
		int[] A = new int[N];
		for (int i = 0; i < N; i++) {
			A[i] = Integer.parseInt(sc.next());
		}
		for (int i = 1; i < N; i++) {
			if (Math.abs(A[i] - A[i - 1]) > 1) {
				return new int[]{i-1, i};
			}
		}
		return null;
	}
}