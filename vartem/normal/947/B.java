import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.nextInt();
            int[] v = in.nextIntArray(n);
            int[] t = in.nextIntArray(n);

            long cur = 0;
            Pair[] p = new Pair[n];
            int[] pos = new int[n];
            long tmp = 0;
            for (int i = 0; i < n; i++) {
                p[i] = new Pair(v[i] + tmp, i);
                tmp += t[i];
            }
            Arrays.sort(p);
            for (int i = 0; i < n; i++) {
                pos[p[i].id] = i;
            }

            BITSum sum = new BITSum(n);
            BITSum count = new BITSum(n);
            long prev = 0;

            for (int i = 0; i < n; i++) {
                cur += t[i];
                sum.add(pos[i], p[pos[i]].val);
                count.add(pos[i], 1);

                int l = -1, r = n;
                while (r - l > 1) {
                    int m = (l + r) / 2;
                    if (p[m].val < cur) {
                        l = m;
                    } else {
                        r = m;
                    }
                }
                long next = sum.sum(r, n - 1) - cur * count.sum(r, n - 1);
                out.print(prev - next + v[i]);
                out.print(' ');
                prev = next;
            }
        }

        class Pair implements Comparable<Pair> {
            long val;
            int id;

            public Pair(long val, int id) {
                this.val = val;
                this.id = id;
            }


            public int compareTo(Pair o) {
                return Long.compare(val, o.val);
            }

        }

        public class BITSum {
            long[] tree;

            public BITSum(int size) {
                tree = new long[size];
            }

            public long sum(int pos) {
                long result = 0;
                while (pos >= 0) {
                    result += tree[pos];
                    pos = (pos & (pos + 1)) - 1;
                }
                return result;
            }

            public long sum(int l, int r) {
                if (l > r) {
                    return 0;
                }
                long result = sum(r);
                if (l - 1 >= 0) {
                    result -= sum(l - 1);
                }
                return result;
            }

            public void add(int pos, long val) {
                while (pos < tree.length) {
                    tree[pos] += val;
                    pos |= pos + 1;
                }
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

        public int[] nextIntArray(int n) {
            int[] ret = new int[n];
            for (int i = 0; i < n; i++) {
                ret[i] = nextInt();
            }
            return ret;
        }

    }
}