import java.util.Scanner;

public class Main {
	static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int T = sc.nextInt();
		for (int i = 0; i < T; i++) {
			System.out.println(solve() ? "YES" : "NO");
		}
	}

	static boolean solve() {
		int N = sc.nextInt();
		int[] P = new int[N];
		int[] C = new int[N];
		for (int i = 0; i < N; i++) {
			P[i] = sc.nextInt();
			C[i] = sc.nextInt();
		}
		int pp = 0;
		int pc = 0;
		for (int i = 0; i < N; i++) {
			int cp = P[i] - pp;
			int cc = C[i] - pc;
			if (cp < 0 || cc < 0 || cp < cc) return false;
			pp = P[i];
			pc = C[i];
		}
		return true;
	}

}