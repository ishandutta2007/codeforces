import java.util.*;

public class CountTheRectangles3 {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        List<Segment> horizontal = new ArrayList<>();
        List<Segment> vertical = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int x1 = in.nextInt();
            int y1 = in.nextInt();
            int x2 = in.nextInt();
            int y2 = in.nextInt();
            if (x1 == x2) {
                vertical.add(new Segment(x1, y1, y2));
            } else {
                horizontal.add(new Segment(y1, x1, x2));
            }
        }
        if (horizontal.size() > vertical.size()) {
            List<Segment> temp = horizontal;
            horizontal = vertical;
            vertical = temp;
        }
        vertical.sort((s1, s2) -> {
            if (s1.v2 != s2.v2) {
                return s1.v2 - s2.v2;
            } else if (s1.v1 != s2.v1) {
                return s1.v1 - s2.v1;
            } else {
                return s1.u - s2.u;
            }
        });
        horizontal.sort((s1, s2) -> {
            if (s1.u != s2.u) {
                return s1.u - s2.u;
            } else if (s1.v2 != s2.v2) {
                return s1.v2 - s2.v2;
            } else {
                return s1.v1 - s2.v1;
            }
        });
        long answer = 0;
        Queue<Segment> queue = new LinkedList<>();
        BinaryIndexTree bixTree = new BinaryIndexTree(-5000, 5000);
        for (int i = 0; i < horizontal.size(); i++) {
            Segment h = horizontal.get(i);
            //System.out.println("*****h = " + h + "*****");
            for (Segment v : vertical) {
                if (v.v1 <= h.u && h.u <= v.v2 && h.v1 <= v.u && v.u <= h.v2) {
                    queue.add(v);
                    bixTree.update(v.u, 1);
                    //System.out.println("adding " + v);
                }
            }
            for (int j = i + 1; j < horizontal.size(); j++) {
                Segment ho = horizontal.get(j);
                while (!queue.isEmpty() && queue.peek().v2 < ho.u) {
                    //System.out.println("removing " + queue.peek());
                    bixTree.update(queue.remove().u, -1);
                }
                long amt = bixTree.query(ho.v1, ho.v2);
                //System.out.println("h = " + h + ", ho = " + ho + ", amt = " + amt);
                answer += (amt * (amt - 1)) >> 1L;
            }
            while (!queue.isEmpty()) {
                //System.out.println("removing " + queue.peek());
                bixTree.update(queue.remove().u, -1);
            }
        }
        System.out.println(answer);
    }

    static class Segment {
        final int u;
        final int v1;
        final int v2;

        Segment(int u, int v1, int v2) {
            this.u = u;
            this.v1 = Math.min(v1, v2);
            this.v2 = Math.max(v1, v2);
        }

        @Override
        public String toString() {
            return "Segment{" +
                    "u=" + u +
                    ", v1=" + v1 +
                    ", v2=" + v2 +
                    '}';
        }
    }

    static class BinaryIndexTree {
        final long[] val;
        final int treeFrom;

        BinaryIndexTree(int treeFrom, int treeTo) {
            val = new long[treeTo - treeFrom + 2];
            this.treeFrom = treeFrom;
        }

        void update(int index, long delta) {
            for (int i = index + 1 - treeFrom; i < val.length; i += i & -i) {
                val[i] += delta;
            }
        }

        long query(int to) {
            long res = 0;
            for (int i = to + 1 - treeFrom; i > 0; i -= i & -i) {
                res += val[i];
            }
            return res;
        }

        long query(int from, int to) {
            if (to < from) {
                return 0;
            }
            return query(to) - query(from - 1);
        }
    }
}