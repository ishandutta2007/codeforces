import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class Main {
	static Scanner sc = new Scanner(System.in);
	static int N;
	static long A, R, M;
	static int[] H;
	static long[] sum;

	public static void main(String[] args) {
		N = sc.nextInt();
		A = sc.nextInt();
		R = sc.nextInt();
		M = sc.nextInt();
		ArrayList<Integer> HA = new ArrayList<>();
		for (int i = 0; i < N; i++) {
			HA.add(Integer.parseInt(sc.next()));
		}
		Collections.sort(HA);
		H = new int[N];
		for (int i = 0; i < N; i++) {
			H[i] = HA.get(i);
		}
		long lo = H[0];
		long hi = H[N - 1];
		sum = new long[N + 1];
		for (int i = 0; i < N; i++) {
			sum[i + 1] = sum[i] + H[i];
			H[i] *= 2;
		}
		while(hi - lo > 10000) {
			long m1 = (lo * 2 + hi) / 3;
			long m2 = (lo + hi * 2) / 3;
			long c1 = calcCost(m1);
			long c2 = calcCost(m2);
			if (c1 < c2) {
				hi = m2;
			} else {
				lo = m1;
			}
		}
		long ans = Long.MAX_VALUE;
		for (long i = lo; i <= hi; i++) {
			ans = Math.min(ans, calcCost(i));
		}
		System.out.println(ans);
	}

	static long calcCost(long h) {
		int pos = -Arrays.binarySearch(H, (int)h * 2 + 1) - 2;
		long lo = (long) (pos + 1) * h - sum[pos + 1];
		long hi = (sum[N] - sum[pos + 1]) - (long) (N - pos - 1) * h;
		if (lo < hi) {
			return Math.min(A + R, M) * lo + (hi - lo) * R;
		} else {
			return Math.min(A + R, M) * hi + (lo - hi) * A;
		}
//		System.err.println("i:" + i + " pos:" + pos + " lo:" + lo + " hi:" + hi + " cost:" + cost[i]);
	}
}