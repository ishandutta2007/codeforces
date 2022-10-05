import java.util.*;

public class TokitsukazeAndStrangeRectangle {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        Point[] points = new Point[n];
        Point[] pointsByX = new Point[n];
        Map<Integer, Integer> amtAtX = new HashMap<>();
        for (int i = 0; i < n; i++) {
            int x = in.nextInt();
            int y = in.nextInt();
            points[i] = new Point(x, y);
            pointsByX[i] = points[i];
            amtAtX.merge(x, 1, (a, b) -> a + b);
        }
        Arrays.sort(points);
        Arrays.sort(pointsByX, (p1, p2) -> {
            if (p1.x != p2.x) {
                return p1.x - p2.x;
            } else {
                return p1.y - p2.y;
            }
        });
        for (int i = 0, ix = 1; i < n; i++) {
            if (i > 0 && pointsByX[i].x > pointsByX[i - 1].x) {
                ix++;
            }
            pointsByX[i].xix = ix;
        }
        int maxix = pointsByX[n - 1].xix;
        SegmentTree segTree = new SegmentTree(1, maxix);
        for (int i = 1; i <= maxix; i++) {
            segTree.update(i, 1);
        }
        long answer = 0;
        for (int i = 0; i < n;) {
            int y = points[i].y;
            int iMin = i;
            for (; i < n && points[i].y == y; i++) {
                amtAtX.merge(points[i].x, -1, (a, b) -> a + b);
                if (amtAtX.get(points[i].x) == 0) {
                    segTree.update(points[i].xix, 0);
                }
            }
            int iMax = i;
            long amtHere = iMax - iMin;
            answer += amtHere;
            long prev = segTree.query(1, points[iMin].xix - 1);
            //System.out.println("iMin = " + iMin + ", iMax = " + iMax + ", answer = " + answer + ", prev = " + prev);
            for (i = iMin; i < iMax; i++) {
                answer += prev;
                prev++;
                long next = segTree.query(points[i].xix + 1, i < iMax - 1 ? (points[i + 1].xix - 1) : maxix);
                answer += prev * next;
                prev += next;
                //System.out.println("points[" + i + "] = " + points[i] + ", prev = " + prev + ", next = " + next + ", answer = " + answer);
            }
            i = iMax;
        }
        System.out.println(answer);
    }

    static class Point implements Comparable<Point> {
        final int x;
        final int y;
        int xix = -1;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public int compareTo(Point o) {
            if (y != o.y) {
                return y - o.y;
            } else {
                return x - o.x;
            }
        }

        @Override
        public String toString() {
            return "Point{" +
                    "x=" + x +
                    ", y=" + y +
                    ", xix=" + xix +
                    '}';
        }
    }

    static class SegmentTree {
        final long[] val;
        final int treeFrom;
        final int treeTo;

        public static final long IDENTITY = 0;

        long combine(long a, long b) {
            return a + b;
        }

        SegmentTree(int treeFrom, int treeTo) {
            this.treeFrom = treeFrom;
            this.treeTo = treeTo;
            int length = treeTo - treeFrom + 1;
            int l;
            for (l = 0; (1 << l) < length; l++);
            val = new long[1 << (l + 1)];
        }

        void update(int index, long newVal) {
            update(1, treeFrom, treeTo, index, newVal);
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
            if (to < from) {
                return 0;
            }
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