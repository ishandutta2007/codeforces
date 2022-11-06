import java.util.BitSet;
import java.util.Scanner;

public class A {
	static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) throws Exception {
		BitSet primes = primes(1001);
		int N = sc.nextInt();
		int K = sc.nextInt();
		int count = 0;
		for (int i = 2; i <= N; ++i) {
			if (!primes.get(i)) continue;
			int res = i - 1;
			boolean found = false;
			for (int j = 2; j <= i / 2; ++j) {
				if (primes.get(j) && primes.nextSetBit(j + 1) == res - j) {
					found = true;
					break;
				}
			}
			if (found) {
				++count;
			}
		}
		System.out.println(count >= K ? "YES" : "NO");
	}

	public static BitSet primes(int max) {
		BitSet primeSet = new BitSet(max + 1);
		if (max < 2) {
			return primeSet;
		}
		int limit = (int) Math.sqrt(max + 1);
		primeSet.set(2);
		for (int i = 3; i < max + 1; i += 2) {
			primeSet.set(i);
		}
		for (int i = 3; i <= limit; i += 2) {
			if (!primeSet.get(i)) {
				continue;
			}
			for (int j = i * i; j < max; j += i) {
				primeSet.clear(j);
			}
		}
		return primeSet;
	}

}