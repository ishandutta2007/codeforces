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
		int K1 = sc.nextInt();
		int K2 = sc.nextInt();
		boolean ret = false;
		for (int i = 0; i < K1; i++) {
			int a = sc.nextInt();
			if (a == N) ret = true;
		}
		for (int i = 0; i < K2; i++) {
			sc.next();
		}
		return ret;
	}
}