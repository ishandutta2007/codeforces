import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
	static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		ArrayList<ArrayList<Integer>> counts = new ArrayList<>();
		for (int i = 0; i <= 200000; i++) {
			counts.add(new ArrayList<>());
		}
		int N = sc.nextInt();
		for (int i = 0; i < N; i++) {
			int A = Integer.parseInt(sc.next());
			for (long j = 2; j * j <= A; j++) {
				if (A % j == 0) {
					int count = 1;
					A /= j;
					while (A % j == 0) {
						A /= j;
						count++;
					}
					counts.get((int) j).add(count);
				}
			}
			if (A > 1) {
				counts.get(A).add(1);
			}
		}
		long ans = 1;
		for (int i = 0; i < counts.size(); i++) {
			if (counts.get(i).size() <= N - 2) continue;
			while (counts.get(i).size() < N) {
				counts.get(i).add(0);
			}
			Collections.sort(counts.get(i));
			for (int j = 0; j < counts.get(i).get(1); j++) {
				ans *= i;
			}
		}
		System.out.println(ans);
	}

}