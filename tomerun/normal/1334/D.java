import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	static Scanner sc = new Scanner(System.in);
	static PrintWriter writer = new PrintWriter(System.out);

	public static void main(String[] args) {
		int T = sc.nextInt();
		for (int i = 0; i < T; i++) {
			solve();
		}
		writer.flush();
	}

	static void solve() {
		int N = sc.nextInt();
		long L = sc.nextLong() - 1;
		long R = sc.nextLong();
		ArrayList<Integer> ans = new ArrayList<>();
		if (L <= 0) {
			ans.add(1);
		}
		long idx = 1;
		for (int i = 2; i < N; i++) {
			if (L <= idx && idx < R) {
				ans.add(i);
			}
			idx++;
			if (L <= idx && idx < R) {
				ans.add(1);
			}
			idx++;
		}
		if (L <= idx && idx < R) {
			ans.add(N);
		}
		idx++;
		for (int i = 2; i < N && idx < R; i++) {
			long add = (N - i) * 2;
			if (L <= idx + add) {
				if (L <= idx && idx < R) {
					ans.add(i);
				}
				idx++;
				for (int j = i + 1; j < N; j++) {
					if (L <= idx && idx < R) {
						ans.add(j);
					}
					idx++;
					if (L <= idx && idx < R) {
						ans.add(i);
					}
					idx++;
				}
				if (L <= idx && idx < R) {
					ans.add(N);
				}
				idx++;
			} else {
				idx += add;
			}
		}
		if (L <= idx && idx < R) {
			ans.add(1);
		}
		for (int i = 0; i < ans.size(); i++) {
			writer.print(ans.get(i) + (i == ans.size() - 1 ? "\n" : " "));
		}
	}
}