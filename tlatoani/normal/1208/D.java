import java.util.Scanner;
import java.util.StringJoiner;

public class RestorePermutation {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        long[] s = new long[n];
        for (int i = 0; i < n; i++) {
            s[i] = in.nextLong();
        }
        SegmentTree segTree = new SegmentTree(0, n);
        for (int i = 1; i <= n; i++) {
            segTree.update(i, i);
        }
        int[] res = new int[n];
        for (int i = n - 1; i >= 0; i--) {
            int lower = 0;
            int upper = n - 1;
            while (lower < upper) {
                int mid = (lower + upper + 1) / 2;
                if (segTree.query(0, mid) <= s[i]) {
                    lower = mid;
                } else {
                    upper = mid - 1;
                }
            }
            res[i] = upper + 1;
            segTree.update(res[i], -res[i]);
        }
        StringJoiner joiner = new StringJoiner(" ");
        for (int i = 0; i < n; i++) {
            joiner.add(res[i] + "");
        }
        System.out.println(joiner);
    }

    static class SegmentTree {
        final long[] val;
        final int treeFrom;
        final int length;

        SegmentTree(int treeFrom, int treeTo) {
            this.treeFrom = treeFrom;
            int length = treeTo - treeFrom + 1;
            int l;
            for (l = 0; (1 << l) < length; l++);
            val = new long[1 << (l + 1)];
            this.length = 1 << l;
        }

        void update(int index, long delta) {
            int node = index - treeFrom + length;
            val[node] += delta;
            for (node >>= 1; node > 0; node >>= 1) {
                val[node] = val[node << 1] + val[(node << 1) + 1];
            }
        }

        long query(int from, int to) {
            if (to < from) {
                return 0;
            }
            from += length - treeFrom;
            to += length - treeFrom + 1;
            long res = 0;
            for (; from + (from & -from) <= to; from += from & -from) {
                res += val[from / (from & -from)];
            }
            for (; to - (to & -to) >= from; to -= to & -to) {
                res += val[(to - (to & -to)) / (to & -to)];
            }
            return res;
        }
    }
}