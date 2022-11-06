import java.io.PrintWriter;
import java.util.*;

public class Main {
	static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int N = sc.nextInt();
		HashSet<Long> set = new HashSet<>();
		ArrayList<Long> S = new ArrayList<>();
		for (int i = 0; i < N; i++) {
			long s = Long.parseLong(sc.next());
			if (!set.contains(s)) {
				set.add(s);
				S.add(s);
			}
		}
		Collections.sort(S);
		HashMap<Long, Integer> map = new HashMap<>();
		ArrayList<Long> diff = new ArrayList<>();
		for (int i = 0; i < S.size() - 1; i++) {
			long d = S.get(i + 1) - S.get(i);
			if (!map.containsKey(d)) {
				map.put(d, 1);
				diff.add(d);
			} else {
				map.put(d, map.get(d) + 1);
			}
		}
		diff.add(0L);
		Collections.sort(diff);
		long[] count = new long[diff.size()];
		long[] left = new long[diff.size()];
		count[0] = S.size();
		left[0] = S.size();
		for (int i = 1; i < diff.size(); i++) {
			int dc = map.get(diff.get(i));
			left[i] = left[i - 1] - dc;
			count[i] = count[i - 1] + (diff.get(i) - diff.get(i - 1) - 1) * left[i - 1] + left[i];
		}
		int Q = sc.nextInt();
		PrintWriter writer = new PrintWriter(System.out);
		for (int i = 0; i < Q; i++) {
			long L = Long.parseLong(sc.next());
			long R = Long.parseLong(sc.next());
			long v = R - L;
			int pos = Collections.binarySearch(diff, v);
			if (pos < 0) {
				pos = -pos - 2;
			}
			long ans = count[pos] + (v - diff.get(pos)) * left[pos];
			writer.print(ans + (i == Q - 1 ? "\n" : " "));
		}
		writer.flush();
	}

	static void solve() {
	}
}