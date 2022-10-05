import java.util.*;

public class ChooseASquare {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        Integer[] xs = new Integer[2 * n];
        Point[] points = new Point[n];
        for (int i = 0; i < n; i++) {
            int x = in.nextInt();
            int y = in.nextInt();
            long cost = in.nextLong();
            points[i] = new Point(x, y, cost);
            xs[i << 1] = x;
            xs[(i << 1) + 1] = y;
        }
        Arrays.sort(xs);
        Arrays.sort(points, Comparator.comparingInt(p -> p.max));
        Map<Integer, Integer> xix = new HashMap<>();
        int ix = 0;
        int prevX = -1;
        for (int x : xs) {
            if (x == prevX) {
                continue;
            }
            prevX = x;
            ix++;
            xix.put(x, ix);
        }
        LazySegmentTree segTree = new LazySegmentTree(1, ix);
        long answer = 0;
        int answerMax = 0;
        //System.out.println("xix = " + xix);
        prevX = -1;
        int pointy = 0;
        for (int x : xs) {
            if (x == prevX) {
                continue;
            }
            prevX = x;
            segTree.update(xix.get(x), xix.get(x), x);
            while (pointy < n && points[pointy].max <= x) {
                segTree.update(1, xix.get(points[pointy].min), points[pointy].cost);
                pointy++;
            }
            long posAnswer = segTree.query(1, xix.get(x)) - ((long) x);
            if (posAnswer > answer) {
                answer = posAnswer;
                answerMax = x;
            }
            //System.out.println("x = " + x + ", answer = " + answer + ", answerMax = " + answerMax);
            //System.out.println("query(1, xix.get(x)) = " + segTree.query(1, xix.get(x)));
        }
        System.out.println(answer);
        //System.out.println("answerMax = " + answerMax);
        if (answer == 0) {
            System.out.println("2000000000 2000000000 2000000000 2000000000");
            return;
        }
        prevX = -1;
        pointy = 0;
        Arrays.sort(points, Comparator.comparingInt(p -> -p.min));
        for (int i = (n << 1) - 1; i >= 0; i--) {
            int answerMin = xs[i];
            if (answerMin == prevX) {
                continue;
            }
            prevX = answerMin;
            while (pointy < n && points[pointy].min >= answerMin) {
                if (points[pointy].max <= answerMax) {
                    //System.out.println("p = " + p);
                    answer -= points[pointy].cost;
                    //System.out.println("answer = " + answer);
                }
                pointy++;
            }
            if (answerMin <= answerMax && answer == answerMin - answerMax) {
                System.out.println(answerMin + " " + answerMin + " " + answerMax + " " + answerMax);
                return;
            }
        }
        System.out.println("aiya");
    }

    static class Point {
        final int min;
        final int max;
        final long cost;

        Point(int x, int y, long cost) {
            this.min = Math.min(x, y);
            this.max = Math.max(x, y);
            this.cost = cost;
        }

        @Override
        public String toString() {
            return "Point{" +
                    "min=" + min +
                    ", max=" + max +
                    ", cost=" + cost +
                    '}';
        }
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
}