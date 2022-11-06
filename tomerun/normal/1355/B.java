import java.util.Scanner;

public class Main {
	static Scanner sc = new Scanner(System.in);
	static int[] histo = new int[200001];

	public static void main(String[] args) {
		int T = sc.nextInt();
		for (int i = 0; i < T; i++) {
			System.out.println(solve());
		}
	}

	static int solve() {
		int N = sc.nextInt();
		for (int i = 1; i <= N; i++) {
			histo[i] = 0;
		}
		for (int i = 0; i < N; i++) {
			int E = Integer.parseInt(sc.next());
			histo[E]++;
		}
		int ans = 0;
		int carry = 0;
		for (int i = 1; i <= N; i++) {
			carry += histo[i];
			ans += carry / i;
			carry %= i;
		}
		return ans;
	}
}