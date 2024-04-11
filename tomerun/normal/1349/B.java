import java.util.Scanner;

public class Main {
	static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int T = sc.nextInt();
		for (int i = 0; i < T; i++) {
			System.out.println(solve() ? "yes" : "no");
		}
	}

	static boolean solve() {
		int N = sc.nextInt();
		int K = sc.nextInt();
		int[] A = new int[N];
		for (int i = 0; i < N; i++) {
			A[i] = Integer.parseInt(sc.next());
		}
		if (N == 1) return A[0] == K;
		boolean any = false;
		for (int i = 0; i < N; i++) {
			if (A[i] != K) continue;
			any = true;
			{
				int lc = 0;
				int hc = 0;
				for (int j = i + 1; j < N; j++) {
					if (A[j] < K) {
						lc++;
					} else {
						hc++;
						if (hc >= lc) return true;
						if (A[j] == K) break;
					}
				}
			}
			{
				int lc = 0;
				int hc = 0;
				for (int j = i - 1; j >= 0; j--) {
					if (A[j] < K) {
						lc++;
					} else {
						hc++;
						if (hc >= lc) return true;
						if (A[j] == K) break;
					}
				}
			}
		}
		if (!any) return false;
		for (int i = 0; i < N; i++) {
			if (A[i] <= K) continue;
			{
				int lc = 0;
				int hc = 0;
				for (int j = i + 1; j < N; j++) {
					if (A[j] <= K) {
						lc++;
					} else {
						hc++;
						if (hc >= lc) return true;
						break;
					}
				}
			}
			{
				int lc = 0;
				int hc = 0;
				for (int j = i - 1; j >= 0; j--) {
					if (A[j] <= K) {
						lc++;
					} else {
						hc++;
						if (hc >= lc) return true;
						break;
					}
				}
			}
		}
		return false;
	}
}