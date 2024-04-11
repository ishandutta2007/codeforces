import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;

public class C {
	Scanner sc = new Scanner(System.in);
	
	void run() {
		int L1 = sc.nextInt() - 1, R1 = sc.nextInt() - 1, L2 = sc.nextInt() - 1, R2 = sc.nextInt() - 1;
		System.out.println(rec(L1, R1, L2, R2, 30));
	}
	
	TreeMap<Entry, Integer> memo = new TreeMap<Entry, Integer>();
	
	int rec(int L1, int R1, int L2, int R2, int t) {
		if (L1 >= (1L << (t + 1))) {
			L1 -= 1 << (t + 1);
			R1 -= 1 << (t + 1);
		}
		if (L2 >= (1L << (t + 1))) {
			L2 -= 1 << (t + 1);
			R2 -= 1 << (t + 1);
		}
		if (L1 > R1 || L2 > R2) return 0;
		if (t == 0) return 1;
		Entry e = null;
		if (t <= 15) {
			e = new Entry(L1, L2, R1, R2, t);
			Integer r = memo.get(e);
			if (r != null) return r;
		}
		int p = (1 << t) - 1;
		int res = 0;
		if (L1 <= p && p <= R1 && L2 <= p && p <= R2) {
			res = min(R1, R2) - max(L1, L2) + 1;
			res = max(res, rec(L1, p - 1, p + 1, R2, t - 1));
			res = max(res, rec(p + 1, R1, L2, p - 1, t - 1));
		} else if (L1 <= p && p <= R1) {
			res = max(rec(L1, p - 1, L2, R2, t - 1), rec(p + 1, R1, L2, R2, t - 1));
		} else if (L2 <= p && p <= R2) {
			res = max(rec(L1, R1, L2, p - 1, t - 1), rec(L1, R1, p + 1, R2, t - 1));
		} else {
			res = rec(L1, R1, L2, R2, t - 1);
		}
		if (t <= 15) memo.put(e, res);
		return res;
	}
	
	class Entry implements Comparable<Entry> {
		int L1, L2, R1, R2, t;
		Entry(int L1, int L2, int R1, int R2, int t) {
			this.L1 = L1;
			this.L2 = L2;
			this.R1 = R1;
			this.R2 = R2;
			this.t = t;
		}
		public int compareTo(Entry o) {
			if (L1 != o.L1) return L1 - o.L1;
			if (L2 != o.L2) return L2 - o.L2;
			if (R1 != o.R1) return R1 - o.R1;
			if (R2 != o.R2) return R2 - o.R2;
			return t - o.t;
		}
	}
	
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static void main(String[] args) {
		new C().run();
	}
}