import java.util.Scanner;

public class Main {
	static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int N = sc.nextInt();
		int[] C = new int[N];
		for (int i = 0; i < N; i++) {
			C[i] = Integer.parseInt(sc.next());
		}
		int ans = 0;
		if (C[0] != C[N - 1]) {
			ans = N - 1;
		} else {
			for (int i = 1; i < N - 1; i++) {
				if (C[i] != C[0]) {
					ans = Math.max(ans, Math.max(i, N - 1 - i));
				}
			}
		}
		System.out.println(ans);
	}

}