import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.TreeSet;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskG solver = new TaskG();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskG {
        final int MOD = 998244353;

        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.nextInt(), q = in.nextInt();
            TreeSet[] occurs = new TreeSet[n];
            SegmentTree tree = new SegmentTree(n);
            Segment[] deleted = new Segment[n];
            for (int Q = 0; Q < q; Q++) {
                int t = in.nextInt(), l = in.nextInt() - 1, r = in.nextInt() - 1;
                if (t == 1) {
                    int x = in.nextInt() - 1;
                    if (occurs[x] == null) {
                        occurs[x] = new TreeSet<>();
                    }
                    tree.apply(l, r + 1, 1, 1);
                    TreeSet<Segment> set = occurs[x];
                    Segment cur = new Segment(l, r);
                    Segment start = set.floor(cur);
                    int ptr = 0;
                    if (start != null && start.r + 1 >= l) {
                        set.remove(start);
                        deleted[ptr++] = start;
                    }
                    while (true) {
                        Segment next = set.ceiling(cur);
                        if (next == null || next.l > r + 1) {
                            break;
                        }
                        set.remove(next);
                        deleted[ptr++] = next;
                    }

                    for (int i = 0; i < ptr; i++) {
                        int L = Math.max(l, deleted[i].l), R = Math.min(r, deleted[i].r);
                        if (L <= R) {
                            tree.apply(L, R + 1, 2, MOD - 2);
                        }
                        cur.l = Math.min(cur.l, deleted[i].l);
                        cur.r = Math.max(cur.r, deleted[i].r);
                    }
                    set.add(cur);
                } else {
                    out.println(tree.get(l, r + 1));
                }
            }
        }

        class Segment implements Comparable<Segment> {
            int l;
            int r;

            public Segment(int l, int r) {
                this.l = l;
                this.r = r;
            }


            public int compareTo(Segment o) {
                return l - o.l;
            }


            public String toString() {
                return "Segment{" +
                        "l=" + l +
                        ", r=" + r +
                        '}';
            }

        }

        class SegmentTree {
            int[] sum;
            int[] a;
            int[] b;
            int[] posLeft;
            int[] posRight;
            int size;

            public SegmentTree(int n) {
                size = n;
                sum = new int[4 * n];
                a = new int[4 * n];
                b = new int[4 * n];
                posLeft = new int[4 * n];
                posRight = new int[4 * n];
                build(0, size, 0);
            }

            void build(int l, int r, int i) {
                posLeft[i] = l;
                posRight[i] = r;
                if (l + 1 == r) {
                    return;
                }
                int m = (l + r) >>> 1;
                build(l, m, 2 * i + 1);
                build(m, r, 2 * i + 2);
            }

            void apply(int i, int A, int B) {
                sum[i] = (int) (((long) sum[i] * A + (long) B * (posRight[i] - posLeft[i])) % MOD);
                a[i] = (int) ((long) a[i] * A % MOD);
                b[i] = (int) (((long) A * b[i] + B) % MOD);
            }

            void push(int i) {
                if (a[i] == 1 && b[i] == 0) {
                    return;
                }
                apply(2 * i + 1, a[i], b[i]);
                apply(2 * i + 2, a[i], b[i]);
                a[i] = 1;
                b[i] = 0;
            }

            void update(int i) {
                sum[i] = sum[2 * i + 1] + sum[2 * i + 2];
                if (sum[i] >= MOD) {
                    sum[i] -= MOD;
                }
            }

            int get(int left, int right) {
                return get(0, size, left, right, 0);
            }

            private int get(int l, int r, int left, int right, int i) {
                if (left <= l && r <= right) {
                    return sum[i];
                }
                if (right <= l || r <= left) {
                    return 0;
                }
                push(i);
                int m = (l + r) >>> 1;
                int result = get(l, m, left, right, 2 * i + 1);
                result += get(m, r, left, right, 2 * i + 2);
                if (result >= MOD) {
                    result -= MOD;
                }
                update(i);
                return result;
            }

            void apply(int left, int right, int A, int B) {
                if (left < right)
                    apply(0, size, left, right, A, B, 0);
            }

            private void apply(int l, int r, int left, int right, int A, int B, int i) {
                if (left <= l && r <= right) {
                    apply(i, A, B);
                    return;
                }
                if (right <= l || r <= left) {
                    return;
                }
                push(i);
                int m = (l + r) >>> 1;
                apply(l, m, left, right, A, B, 2 * i + 1);
                apply(m, r, left, right, A, B, 2 * i + 2);
                update(i);
            }

        }

    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public String next() {
            while (st == null || !st.hasMoreElements()) {
                String line = null;
                try {
                    line = br.readLine();
                } catch (IOException e) {
                }
                st = new StringTokenizer(line);
            }
            return st.nextToken();
        }

    }
}