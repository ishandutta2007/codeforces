import java.util.Scanner;

public class A {

	static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) throws Exception {
		int N = sc.nextInt();
		int L = sc.nextInt();
		int R = sc.nextInt();
		int QL = sc.nextInt();
		int QR = sc.nextInt();
		int[] w = new int[N];
		sc.nextLine();
		long all = 0;
		String[] ws = sc.nextLine().split(" ");
		for (int i = 0; i < N; ++i) {
			w[i] = Integer.parseInt(ws[i]);
			all += w[i];
		}
		long ans = Long.MAX_VALUE;
		long sum = 0;
		for (int cl = 0; cl <= N; ++cl) {
			int cr = N - cl;
			long cur = sum * L + (all - sum) * R;
			if (cl < cr) {
				cur += Math.max(0, cr - cl - 1) * QR;
			} else {
				cur += Math.max(0, cl - cr - 1) * QL;
			}
			ans = Math.min(ans, cur);
			if (cl < N) sum += w[cl];
		}
		System.out.println(ans);
	}
}