import java.util.Arrays;
import java.util.Scanner;
import java.util.SplittableRandom;

public class Main {
	static boolean LOCAL = false;
	static SplittableRandom rnd = new SplittableRandom();
	static Scanner sc = new Scanner(System.in);
	static int N, K, M;
	static int[] A;

	public static void main(String[] args) {
		if (LOCAL) {
			N = rnd.nextInt(100) + 2;
			K = rnd.nextInt(N - 1) + 1;
			M = rnd.nextInt(K) + 1;
			A = new int[N];
			for (int i = 0; i < N; i++) {
				A[i] = rnd.nextInt(200);
				boolean ok = true;
				for (int j = 0; j < i; j++) {
					if (A[i] == A[j]) {
						ok = false;
						break;
					}
				}
				if (!ok) --i;
			}
			System.err.println(N + " " + K + " " + M);
			System.err.println(Arrays.toString(A));
		} else {
			N = sc.nextInt();
			K = sc.nextInt();
		}
		if (K == 1) {
			answer(1);
			return;
		}
		int[] X = new int[K];
		for (int i = 0; i < K; i++) {
			X[i] = i;
		}
		int[] ps = query(X);
		int[] color = new int[N];
		color[K] = 1;
		for (int i = 0; i < K; i++) {
			if (i == ps[0]) continue;
			X[i] = K;
			int[] cs = query(X);
			if (cs[0] == ps[0]) {
				color[i] = color[K];
			} else {
				color[i] = -color[K];
			}
			X[i] = i;
		}
		int mi = ps[0] == 0 ? 1 : 0;
		for (int i = K + 1; i < N; i++) {
			X[mi] = i;
			int[] cs = query(X);
			if (cs[0] == ps[0]) {
				color[i] = color[mi];
			} else {
				color[i] = -color[mi];
			}
		}
		X[mi] = mi;
		X[ps[0]] = K;
		int[] cs = query(X);
		boolean match = (color[cs[0]] == 1) == cs[1] > ps[1];
//		System.err.println(match);
//		System.err.println(Arrays.toString(color));
		int c = 0;
		for (int i = 0; i < K; i++) {
			if (i == ps[0]) continue;
			if (color[i] == 1) c++;
		}
		if (match) {
			answer(K - c);
		} else {
			answer(c + 1);
		}
	}


	static int[] query(int[] x) {
		StringBuilder sb = new StringBuilder();
		sb.append("?");
		for (int i = 0; i < x.length; i++) {
			sb.append(" ").append(x[i] + 1);
		}
		System.out.println(sb);
		int[] ret = new int[2];
		if (LOCAL) {
			long[] as = new long[x.length];
			for (int i = 0; i < x.length; i++) {
				as[i] = ((long) A[x[i]] << 32) | x[i];
			}
			Arrays.sort(as);
			ret[0] = (int) as[M - 1];
			ret[1] = (int) (as[M - 1] >> 32);
		} else {
			ret[0] = sc.nextInt() - 1;
			ret[1] = sc.nextInt();
		}
		return ret;
	}

	static void answer(int m) {
		System.out.println("! " + m);
	}
}