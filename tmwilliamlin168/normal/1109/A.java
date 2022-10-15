import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;


public class C {


	public static void main(String[] args) throws IOException {
		try (PrintStream out = new PrintStream(new BufferedOutputStream(System.out))) {
			Scanner sc = new Scanner(new BufferedInputStream(System.in));

			int n = sc.nextInt();

			int[] as = new int[n];
			for (int i = 0; i < n; i++) as[i] = sc.nextInt();

			out.println(compute(n, as));
		}
	}

	public static long compute(int n, int[] as) {
		Map<Integer, Integer> even = new HashMap<>();
		Map<Integer, Integer> odd = new HashMap<>();

		long pairs = 0;
		int x = 0;
		for (int i = 0; i < n; i++) {
			x ^= as[i];
			if (i % 2 == 1) {
				if (x == 0) pairs++;
				Integer cnt = even.getOrDefault(x, 0) + 1;
				even.put(x, cnt);
			} else {
				Integer cnt = odd.getOrDefault(x, 0) + 1;
				odd.put(x, cnt);
			}
		}

		int agg = 0;
		for (int i = 0; i < n - 1; i++) {
			agg ^= as[i];

			if (i % 2 == 0) {
				odd.put(agg, odd.get(agg) - 1);
				pairs += odd.getOrDefault(agg, 0);
			} else {
				even.put(agg, even.get(agg) - 1);
				pairs += even.getOrDefault(agg, 0);
			}
		}
		return pairs;
	}
}