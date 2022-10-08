import java.io.*;
import java.util.Arrays;
import java.util.Random;

public class VK3B {

    static final Random rnd = new Random(42);

    static class Node {
        int x, y;
        int val, add;
        int min;

        Node l, r;

        public Node(int x, int val) {
            this.x = x;
            this.y = rnd.nextInt();
            this.val = this.min = val;
        }
    }

    static Node pushDown(Node n) {
        n.val += n.add;
        if (n.l != null) {
            n.l.add += n.add;
            n.l.min += n.add;
        }
        if (n.r != null) {
            n.r.add += n.add;
            n.r.min += n.add;
        }
        n.add = 0;
        return n;
    }

    static Node mergeUp(Node n) {
        n.min = n.val;
        if (n.l != null) {
            n.min = Math.min(n.min, n.l.min);
        }
        if (n.r != null) {
            n.min = Math.min(n.min, n.r.min);
        }
        n.min += n.add;
        return n;
    }

    static Node merge(Node l, Node r) {
        if (l == null) {
            return r;
        }
        if (r == null) {
            return l;
        }
        if (l.x >= r.x) {
            throw new AssertionError();
        }
        if (l.y > r.y) {
            pushDown(l);
            l.r = merge(l.r, r);
            return mergeUp(l);
        } else {
            pushDown(r);
            r.l = merge(l, r.l);
            return mergeUp(r);
        }
    }

    static Node[] split(Node n, int x) {
        if (n == null) {
            return new Node[] {null, null};
        }
        pushDown(n);
        Node[] ret;
        if (x <= n.x) {
            ret = split(n.l, x);
            n.l = ret[1];
            ret[1] = mergeUp(n);
        } else {
            ret = split(n.r, x);
            n.r = ret[0];
            ret[0] = mergeUp(n);
        }
        return ret;
    }

    static Node left(Node n) {
        while (n.l != null) {
            pushDown(n);
            n = n.l;
        }
        pushDown(n);
        return n;
    }

    static Node right(Node n) {
        while (n.r != null) {
            pushDown(n);
            n = n.r;
        }
        pushDown(n);
        return n;
    }

    static Node popLeft(Node n) {
        if (n.l == null) {
            return n.r;
        }
        n.l = popLeft(n.l);
        return mergeUp(n);
    }

    static Node next(Node n, int x) {
        if (n == null) {
            return null;
        }
        if (x < n.x) {
            Node ret = next(n.l, x);
            return ret == null ? n : ret;
        } else {
            return next(n.r, x);
        }
    }

    static Node inc(Node n, int x) {
        Node[] p = split(n, x);
        if (p[0] != null) {
            int val = right(p[0]).val;
            if (p[1] == null || left(p[1]).x > x) {
                if (p[1] != null && left(p[1]).val == val) {
                    left(p[1]).x = x;
                } else {
                    Node nn = new Node(x, val);
                    p[1] = merge(nn, p[1]);
                }
            }
            p[0].add++;
            mergeUp(p[0]);
            if (p[1] != null && left(p[0]).val == right(p[1]).val) {
                p[1] = popLeft(p[1]);
            }
        }
        return merge(p[0], p[1]);
    }

    public static void solve(Input in, PrintWriter out) throws IOException {
        int n = in.nextInt();
        int d = in.nextInt();
        int[] l = new int[n];
        int[] r = new int[n];
        for (int i = 0; i < n; ++i) {
            l[i] = in.nextInt();
            r[i] = in.nextInt();
            if (r[i] < 0) {
                --n;
                --i;
            } else {
                l[i] = Math.max(l[i], 0);
                r[i] = Math.max(r[i], 0);
            }
        }
        l = Arrays.copyOf(l, n);
        r = Arrays.copyOf(r, n);
        out.println(solveFast(d, l, r));
    }

    private static int solveFast(int d, int[] l, int[] r) {
        int n = l.length;
        Integer[] ord = new Integer[n];
        for (int i = 0; i < n; ++i) {
            ord[i] = i;
        }
        Arrays.sort(ord, (o1, o2) -> Integer.compare(r[o1], r[o2]));
        Node u = new Node(Integer.MIN_VALUE, 0);
        int prevx = Integer.MIN_VALUE + d;
        for (int i = 0; i < n || next(u, prevx - d) != null; ) {
            int xAt = Integer.MAX_VALUE;
            if (i < n) {
                xAt = Math.min(xAt, r[ord[i]] + 1);
            }
            if (next(u, prevx - d) != null) {
                xAt = Math.min(xAt, next(u, prevx - d).x + d);
            }
            if (xAt == Integer.MAX_VALUE) {
                throw new AssertionError();
            }
            while (i < n && r[ord[i]] + 1 <= xAt) {
                if (r[ord[i]] + 1 < xAt) {
                    throw new AssertionError();
                }
                int x = l[ord[i]];
                u = inc(u, x);
                ++i;
            }
            Node[] p = split(u, xAt + 1 - d);
            Node nn = new Node(xAt, p[0].min);
            u = merge(p[0], p[1]);
            if (nn.val != right(u).val) {
                u = merge(u, nn);
            }
            prevx = xAt;
        }
        return n - u.min;
    }

    private static int solveSlow(int d, int[] l, int[] r) {
        int n = l.length;
        int[] din = new int[101];
        for (int i = 0; i < n; ++i) {
            if (l[i] < 0 || r[i] > din.length) {
                throw new AssertionError();
            }
        }
        for (int i = 0; i < din.length; ++i) {
            for (int t = 0; t < n; ++t) {
                if (l[t] <= i && i <= r[t]) {
                    din[i]++;
                }
            }
            for (int j = 0; j + d <= i; ++j) {
                int cur = din[j];
                for (int t = 0; t < n; ++t) {
                    if (j < l[t] && l[t] <= i && i <= r[t]) {
                        cur++;
                    }
                }
                din[i] = Math.max(din[i], cur);
            }
        }
        int ans = 0;
        for (int x : din) {
            ans = Math.max(ans, x);
        }
        return ans;
    }

    public static void main(String[] args) throws IOException {
        boolean t = false;
//        t = true;
        while (t) {
            int n = rnd.nextInt(100) + 1;
            int d = rnd.nextInt(100) + 1;
            int[] l = new int[n];
            int[] r = new int[n];
            for (int i = 0; i < n; ++i) {
                do {
                    l[i] = rnd.nextInt(100);
                    r[i] = rnd.nextInt(100);
                } while (l[i] > r[i]);
            }
            System.err.println("--------");
            if (solveFast(d, l, r) != solveSlow(d, l, r)) {
                System.err.println(n + " " + d);
                for (int i = 0; i < n; ++i) {
                    System.err.println(l[i] + " " + r[i]);
                }
                System.err.println("--------");
                System.err.println(solveFast(d, l, r) + " " + solveSlow(d, l, r));
                throw new AssertionError();
            }
        }

        PrintWriter out = new PrintWriter(System.out);
        solve(new Input(new BufferedReader(new InputStreamReader(System.in))), out);
        out.close();
    }

    static class Input {
        BufferedReader in;
        StringBuilder sb = new StringBuilder();

        public Input(BufferedReader in) {
            this.in = in;
        }

        public Input(String s) {
            this.in = new BufferedReader(new StringReader(s));
        }

        public String next() throws IOException {
            sb.setLength(0);
            while (true) {
                int c = in.read();
                if (c == -1) {
                    return null;
                }
                if (" \n\r\t".indexOf(c) == -1) {
                    sb.append((char)c);
                    break;
                }
            }
            while (true) {
                int c = in.read();
                if (c == -1 || " \n\r\t".indexOf(c) != -1) {
                    break;
                }
                sb.append((char)c);
            }
            return sb.toString();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        public double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }
    }
}