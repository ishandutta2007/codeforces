import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class Main {
	static Scanner sc = new Scanner(System.in);
	static int N;
	static int[] A;

	public static void main(String[] args) {
		N = sc.nextInt();
		A = new int[N];
		for (int i = 0; i < N; ++i) {
			A[i] = Integer.parseInt(sc.next());
		}
		HashMap<Integer, ArrayList<Integer>> map = new HashMap<>();
		for (int i = 1; i < N; ++i) {
			if (N % i == 0) {
				ArrayList<Integer> count = count(i);
				map.put(i, count);
			}
		}
		long ans = 0;
		for (int i = 1; i < N; ++i) {
			int gcd = gcd(N, i);
			ArrayList<Integer> seq = map.get(gcd);
			ArrayList<Integer> next = new ArrayList<>();
			for (int j = 0; j < seq.size(); ++j) {
				int s = seq.get(j);
				if (s >= i) {
					ans += s == N ? N : s - i + 1;
					next.add(s);
				}
			}
			map.put(gcd, next);
		}
		System.out.println(ans);
	}

	static ArrayList<Integer> count(int s) {
		int[] max = new int[s];
		int pos = 0;
		for (int i = 0; i < N / s; ++i) {
			for (int j = 0; j < s; ++j, ++pos) {
				max[j] = Math.max(max[j], A[pos]);
			}
		}
		int start = -1;
		for (int i = 0; i < N; ++i) {
			if (A[i] != max[i % s]) {
				start = i + 1;
				break;
			}
		}
		ArrayList<Integer> ret = new ArrayList<>();
		if (start == -1) {
			ret.add(N);
			return ret;
		}

		int seq = 0;
		for (int i = 0; i < N; ++i) {
			if (A[(i + start) % N] == max[(i + start) % s]) {
				++seq;
			} else {
				if (seq > 0) {
					ret.add(seq);
				}
				seq = 0;
			}
		}
		return ret;
	}

	static int gcd(int a, int b) {
		return b == 0 ? a : gcd(b, a % b);
	}

}