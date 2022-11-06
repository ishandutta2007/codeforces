import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {

	static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int N = sc.nextInt();
		int[] V = new int[N];
		int[] D = new int[N];
		int[] P = new int[N];
		for (int i = 0; i < N; ++i) {
			V[i] = sc.nextInt();
			D[i] = sc.nextInt();
			P[i] = sc.nextInt();
		}
		ArrayList<Integer> ans = new ArrayList<>();
		boolean[] away = new boolean[N];
		for (int i = 0; i < N; ++i) {
			if (away[i]) continue;
			ans.add(i);
			ArrayDeque<Integer> escape = new ArrayDeque<>();
			int reduce = V[i];
			for (int j = i + 1; j < N && reduce > 0; ++j) {
				if (!away[j]) {
					P[j] -= reduce;
					if (P[j] < 0) {
						escape.add(j);
						away[j] = true;
					}
					reduce--;
				}
			}
			while (!escape.isEmpty()) {
				int ei = escape.poll();
				for (int j = ei; j < N; ++j) {
					if (away[j]) continue;
					P[j] -= D[ei];
					if (P[j] < 0) {
						away[j] = true;
						escape.push(j);
					}
				}
			}
		}
		System.out.println(ans.size());
		System.out.print(ans.get(0) + 1);
		for (int i = 1; i < ans.size(); ++i) {
			System.out.print(" " + (ans.get(i) + 1));
		}
		System.out.println();
	}
}