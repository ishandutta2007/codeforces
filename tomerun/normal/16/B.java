import java.util.Arrays;
import java.util.Scanner;

public class B {
	static Scanner sc = new Scanner(System.in);
	static int N;
	static int M;

	public static void main(String[] args) throws Exception {
		N = sc.nextInt();
		M = sc.nextInt();

		long ans = 0;
		M[] ms = new M[M];
		for (int i = 0; i < M; ++i) {
			long a = sc.nextLong();
			long b = sc.nextLong();
			ms[i] = new M(a, b);
		}
		Arrays.sort(ms);
		for (int i = M - 1; i >= 0; --i) {
			if (N > ms[i].a) {
				N -= ms[i].a;
				ans += ms[i].a * ms[i].b;
			} else {
				ans += N * ms[i].b;
				break;
			}
		}
		System.out.println(ans);
	}

	static class M implements Comparable<M> {
		long a;
		long b;

		M(long a, long b) {
			this.a = a;
			this.b = b;
		}

		public int compareTo(M o) {
			return (int) (this.b - o.b);
		}
	}

}