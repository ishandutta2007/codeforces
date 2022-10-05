import java.util.*;
import java.io.*;

public class NastyaHasntWrittenALegend {

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(in.readLine());
		StringTokenizer tokenizer = new StringTokenizer(in.readLine());
		long[] array = new long[n + 1];
		RangeBIT bit = new RangeBIT(n);
		for (int j = 1; j <= n; j++) {
			array[j] = Long.parseLong(tokenizer.nextToken());
			bit.update(j, j, array[j]);
		}
		tokenizer = new StringTokenizer(in.readLine());
		long[] shifts = new long[n + 1];
		for (int j = 1; j < n; j++) {
			shifts[j] = Long.parseLong(tokenizer.nextToken());
		}
		for (int j = n - 1; j >= 1; j--) {
			shifts[j] += shifts[j + 1];
		}
		TreeSet<Integer> treeSet = new TreeSet<>();
		treeSet.add(1);
		for (int j = 2; j <= n; j++) {
			if (array[j] > array[j - 1] + (shifts[j - 1] - shifts[j])) {
				treeSet.add(j);
			}
		}
		treeSet.add(n + 1);
		StringBuilder out = new StringBuilder();
		int q = Integer.parseInt(in.readLine());
		for (; q > 0; q--) {
			tokenizer = new StringTokenizer(in.readLine());
			if (tokenizer.nextToken().charAt(0) == '+') {
				int j = Integer.parseInt(tokenizer.nextToken());
				long x = Long.parseLong(tokenizer.nextToken());
				if (x > 0L) {
					long newVal = bit.query(j, j) + x;
					treeSet.add(j);
					int k = treeSet.higher(j);
					bit.update(j, k - 1, x);
					while (k != n + 1) {
						long curr = bit.query(k, k);
						if (curr < newVal + shifts[j] - shifts[k]) {
							treeSet.remove(k);
							int nk = treeSet.higher(j);
							bit.update(k, nk - 1, newVal + shifts[j] - shifts[k] - curr);
							k = nk;
						} else {
							break;
						}
					}
				}
			} else {
				int l = Integer.parseInt(tokenizer.nextToken());
				int r = Integer.parseInt(tokenizer.nextToken());
				out.append(bit.query(l, r)).append('\n');
			}
		}
		System.out.print(out);
	}
		



static class RangeBIT {
    final long[] value;
    final long[] weightedVal;

    RangeBIT(int treeTo) {
        value = new long[treeTo + 2];
        weightedVal = new long[treeTo + 2];
    }

    void updateHelper(int index, long delta) {
        long weightedDelta = ((long) index) * delta;
        for (int j = index; j < value.length; j += j & -j) {
            value[j] += delta;
            weightedVal[j] += weightedDelta;
        }
    }

    void update(int from, int to, long delta) {
        updateHelper(from, delta);
        updateHelper(to + 1, -delta);
    }

    long query(int to) {
        long res = 0;
        long weightedRes = 0;
        for (int j = to; j > 0; j -= j & -j) {
            res += value[j];
            weightedRes += weightedVal[j];
        }
        return (((long) (to + 1)) * res) - weightedRes;
    }

    long query(int from, int to) {
        if (to < from) {
            return 0;
        }
        return query(to) - query(from - 1);
    }
}
	
}