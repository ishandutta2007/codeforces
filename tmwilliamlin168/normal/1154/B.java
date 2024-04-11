import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

public class MakeThemEqual {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		Set<Integer> a = new TreeSet<Integer>();
		for (int i = 0; i < n; i++) {
			a.add(sc.nextInt());
		}
		System.out.println(solve(n, a));
		sc.close();
	}

	private static int solve(int n, Set<Integer> a) {
		if (a.size() > 3)
			return -1;

		int[] A = new int[a.size()];
		int i = 0;
		for (int z : a) {
			A[i++] = z;
		}

		if (a.size() == 3) {
			if (2 * A[1] - A[0] == A[2])
				return A[1] - A[0];
			else
				return -1;
		} else if (a.size() == 2) {
			return ((A[1] - A[0]) % 2 == 0) ? Math.min(A[1] - A[0], (A[1] - A[0]) / 2) : (A[1] - A[0]);
		}
		return 0;
	}

}