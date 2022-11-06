import java.util.Scanner;

public class Main {
	static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		System.out.println(solve() ? "Yes" : "No");
	}

	static boolean solve() {
		int N = sc.nextInt();
		int M = sc.nextInt();
		boolean[][] A = new boolean[N][M];
		boolean[][] B = new boolean[N][M];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				A[i][j] = sc.next().equals("1");
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				B[i][j] = sc.next().equals("1");
			}
		}
		int[] row = new int[N];
		int[] col = new int[M];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (A[i][j] != B[i][j]) {
					row[i]++;
					col[j]++;
				}
			}
		}
		for (int i = 0; i < N; i++) {
			if (row[i] % 2 != 0) return false;
		}
		for (int i = 0; i < M; i++) {
			if (col[i] % 2 != 0) return false;
		}
		return true;
	}

}