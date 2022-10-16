import java.util.Scanner;
import java.util.Arrays;
import java.util.TreeMap;

public class E2157 {
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		final int N = sc.nextInt();
		Integer[] a = new Integer[N];
		TreeMap<Integer, Integer> b = new TreeMap<>();
		for (int i = 0; i < N; i++) 
			a[i] = sc.nextInt();

		for (int i = 0; i < N; i++) {
			Integer temp = sc.nextInt();
			Integer qty = b.get(temp);
			if (qty == null) 
				b.put(temp, 1);
			else 
				b.put(temp, qty + 1);
		}

		for (int i = 0; i < N; i++) {
			Integer ai = a[i];
			Integer aim = ai == 0 || i == N - 1 ? 0 : N - ai;
			// System.out.println(aim);
			if (b.get(aim) == null) {
				// System.out.println("Hello" + aim);
				aim = b.higherKey(aim);
				// System.out.println(aim);
			}
			if (aim == null) {
				aim = 0;
			}
			if (b.get(aim) == null) {
				aim = b.higherKey(aim);
			}
			System.out.print((aim + ai) % N + " ");
			Integer qty = b.get(aim);
			if (qty == 1)
				b.remove(aim);
			else
				b.put(aim, qty - 1);
		}

		System.out.println();

	}
}