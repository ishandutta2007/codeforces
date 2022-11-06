import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {

	static Scanner sc = new Scanner(System.in);
	static int N;
	static int[][] A;
	static ArrayList<State> first;
	static ArrayList<State> second;
	static final String[] name = { "MW", "LW", "LM" };

	public static void main(String[] args) {
		N = sc.nextInt();
		A = new int[N][3];
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < 3; ++j) {
				A[i][j] = sc.nextInt();
			}
		}
		if (N == 1) {
			if (A[0][0] == 0 && A[0][1] == 0) {
				System.out.println("LM");
				return;
			}
			if (A[0][1] == 0 && A[0][2] == 0) {
				System.out.println("MW");
				return;
			}
			if (A[0][0] == 0 && A[0][2] == 0) {
				System.out.println("LW");
				return;
			}
			System.out.println("Impossible");
			return;
		}
		first = new ArrayList<>(3 << (N / 2));
		second = new ArrayList<>(3 << (N / 2));
		int[] sum = new int[3];
		dfs(0, 0, 0, N / 2, sum);
		dfs(0, N / 2, N / 2, N, sum);
		Collections.sort(second, (State st1, State st2) -> {
			if (st1.d1 != st2.d1) return Integer.compare(st1.d1, st2.d1);
			if (st1.d2 != st2.d2) return Integer.compare(st1.d2, st2.d2);
			return Integer.compare(st1.s1, st2.s1);
		});
		ArrayList<State> ns = new ArrayList<>();
		for (int i = 0; i < second.size(); ++i) {
			if (i < second.size() - 1) {
				State s1 = second.get(i);
				State s2 = second.get(i + 1);
				if (s1.d1 == s2.d1 && s1.d2 == s2.d2) continue;
			}
			ns.add(second.get(i));
		}
		second = ns;
		State af = null;
		State as = null;
		int best = Integer.MIN_VALUE;
		for (State state : first) {
			State ss = new State(state);
			int pos = Collections.binarySearch(second, ss);
			if (pos < 0) continue;
			State se = second.get(pos);
			if (state.s1 + se.s1 > best) {
				af = state;
				as = se;
				best = state.s1 + se.s1;
			}
		}

		if (af == null) {
			System.out.println("Impossible");
		} else {
			for (int i = 0; i < N / 2; ++i) {
				System.out.println(name[(af.select >> (i * 2)) & 3]);
			}
			for (int i = 0; i < N - N / 2; ++i) {
				System.out.println(name[(as.select >> (i * 2)) & 3]);
			}
		}
	}

	static void dfs(int curSel, int start, int pos, int end, int[] sum) {
		if (pos == end) {
			if (pos == N) {
				second.add(new State(curSel, sum));
			} else {
				first.add(new State(curSel, sum));
			}
			return;
		}
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				if (j != i) sum[j] += A[pos][j];
			}
			curSel += (i << (2 * (pos - start)));
			dfs(curSel, start, pos + 1, end, sum);
			curSel -= (i << (2 * (pos - start)));
			for (int j = 0; j < 3; ++j) {
				if (j != i) sum[j] -= A[pos][j];
			}
		}
	}

	static class State implements Comparable<State> {
		int select;
		int s1, d1, d2;

		State(int select, int[] sum) {
			this.select = select;
			this.s1 = sum[0];
			this.d1 = sum[1] - sum[0];
			this.d2 = sum[2] - sum[0];
		}

		State(State rev) {
			this.select = rev.select;
			this.s1 = rev.s1;
			this.d1 = -rev.d1;
			this.d2 = -rev.d2;
		}

		public int compareTo(State o) {
			if (d1 != o.d1) return Integer.compare(d1, o.d1);
			return Integer.compare(d2, o.d2);
		}
	}
}