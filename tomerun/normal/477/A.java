import java.util.Scanner;

public class Main {

	static Scanner sc = new Scanner(System.in);
	static final int MOD = 1_000_000_007;

	public static void main(String[] args) {
		long A = sc.nextInt();
		long B = sc.nextInt();
		if (B == 1) {
			System.out.println(0);
			return;
		}
		long ans1 = B * (B - 1) / 2;
		ans1 %= MOD;
		long ans2 = A * (A + 1) / 2;
		ans2 %= MOD;
		ans2 *= B;
		ans2 += A;
		ans2 %= MOD;
		System.out.println((ans1 * ans2) % MOD);
	}

}