import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class Serg6 {
    static int MILLION = 1000000;

    public static void main(String[] args) {
        LazySegmentTree segTree = new LazySegmentTree(1, MILLION);
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        int n = in.nextInt();
        int m = in.nextInt();
        int[] a = new int[300001];
        for (int i = 1; i <= n; i++) {
            a[i] = in.nextInt();
            segTree.update(1, a[i], 1);
        }
        int[] b = new int[300001];
        for (int i = 1; i <= m; i++) {
            b[i] = in.nextInt();
            segTree.update(1, b[i], -1);
        }
        int q = in.nextInt();
        for (int k = 1; k <= q; k++) {
            int t = in.nextInt();
            int i = in.nextInt();
            int x = in.nextInt();
            if (t == 1) {
                segTree.update(1, a[i], -1);
                a[i] = x;
                segTree.update(1, a[i], 1);
            } else {
                segTree.update(1, b[i], 1);
                b[i] = x;
                segTree.update(1, b[i], -1);
            }
            if (segTree.query(1, MILLION) <= 0) {
                out.println(-1);
            } else {
                int lower = 1;
                int upper = MILLION;
                int node = 1;
                while (upper > lower) {
                    segTree.propagate(node);
                    int mid = (lower + upper) / 2;
                    if (segTree.eval((node << 1) + 1) > 0) {
                        lower = mid + 1;
                        node = (node << 1) + 1;
                    } else {
                        upper = mid;
                        node = node << 1;
                    }
                }
                out.println(lower);
            }
        }
        out.flush();
        out.close();
    }

    static class LazySegmentTree {
        final long[] val;
        final long[] lazy;
        final int treeFrom;
        final int treeTo;

        public static final long IDENTITY = Long.MIN_VALUE;

        long combine(long a, long b) {
            return Math.max(a, b);
        }

        LazySegmentTree(int treeFrom, int treeTo) {
            this.treeFrom = treeFrom;
            this.treeTo = treeTo;
            int length = treeTo - treeFrom + 1;
            int l;
            for (l = 0; (1 << l) < length; l++);
            val = new long[1 << (l + 1)];
            lazy = new long[1 << (l + 1)];
        }

        void propagate(int node) {
            val[node] += lazy[node];
            if ((node << 1) < val.length) {
                lazy[node << 1] += lazy[node];
                lazy[(node << 1) + 1] += lazy[node];
            }
            lazy[node] = 0;
        }

        long eval(int node) {
            return val[node] + lazy[node];
        }

        void update(int from, int to, long delta) {
            update(1, treeFrom, treeTo, from, to, delta);
        }

        void update(int node, int segFrom, int segTo, int from, int to, long delta) {
            if(segTo < from || segFrom > to) return;
            if(segFrom >= from && segTo <= to) {
                lazy[node] += delta;
                return;
            }
            propagate(node);
            int mid = (segFrom + segTo) >> 1;
            update(node << 1, segFrom, mid, from, to, delta);
            update((node << 1) + 1, mid + 1, segTo, from, to, delta);
            val[node] = combine(eval(node << 1), eval((node << 1) + 1));
        }

        long query(int from, int to) {
            return query(1, treeFrom, treeTo, from, to);
        }

        long query(int node, int segFrom, int segTo, int from, int to) {
            if(segTo < from || segFrom > to) return IDENTITY;
            if(segFrom >= from && segTo <= to) {
                return eval(node);
            }
            propagate(node);
            int mid = (segFrom + segTo) >> 1;
            long res = combine(
                    query(node << 1, segFrom, mid, from, to),
                    query((node << 1) + 1, mid + 1, segTo, from, to)
            );
            val[node] = combine(eval(node << 1), eval((node << 1) + 1));
            return res;
        }
    }

    static class SegmentTree {
        final long[] val;
        final int treeFrom;
        final int treeTo;

        public static final long IDENTITY = Long.MIN_VALUE;

        long combine(long a, long b) {
            return Math.max(a, b);
        }

        SegmentTree(int treeFrom, int treeTo) {
            this.treeFrom = treeFrom;
            this.treeTo = treeTo;
            int length = treeFrom - treeTo + 1;
            int l;
            for (l = 0; (1 << l) < length; l++);
            val = new long[1 << (l + 1)];
        }

        void update(int index, long delta) {
            update(1, treeFrom, treeTo, index, delta);
        }

        void update(int node, int segFrom, int segTo, int index, long newVal) {
            if (segFrom == segTo) {
                val[node] = newVal;
            } else {
                int mid = (segFrom + segTo) >> 1;
                if (index <= mid) {
                    update(node << 1, segFrom, mid, index, newVal);
                } else {
                    update((node << 1) + 1, mid + 1, segTo, index, newVal);
                }
                val[node] = combine(val[node << 1], val[(node << 1) + 1]);
            }
        }

        long query(int from, int to) {
            return query(1, treeFrom, treeTo, from, to);
        }

        long query(int node, int segFrom, int segTo, int from, int to) {
            if(segTo < from || segFrom > to) return IDENTITY;
            if(segFrom >= from && segTo <= to) {
                return val[node];
            }
            int mid = (segFrom + segTo) >> 1;
            return combine(
                    query(node << 1, segFrom, mid, from, to),
                    query((node << 1) + 1, mid + 1, segTo, from, to)
            );
        }
    }
}