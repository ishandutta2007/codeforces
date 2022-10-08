import java.io.*;

public class CF498D {

    final static int lcm = 60;

    static void gen(int a, int[] r) {
        if (lcm % a != 0) {
            throw new AssertionError();
        }
        for (int i = 0; i < lcm; ++i) {
            r[i] = i % a == 0 ? 2 : 1;
        }
    }

    static void combine(int[] a, int[] b, int[] r) {
        for (int i = 0; i < lcm; ++i) {
            r[i] = a[i] + b[(i + a[i]) % lcm];
        }
    }

    static class ITree {
        int[][] v;
        int size;

        public ITree(int[] a) {
            size = 1;
            while (size < a.length) {
                size *= 2;
            }
            v = new int[2 * size - 1][lcm];
            for (int i = 0; i < a.length; ++i) {
                gen(a[i], v[size - 1 + i]);
            }
            for (int i = size - 2; i >= 0; --i) {
                combine(v[2 * i + 1], v[2 * i + 2], v[i]);
            }
        }

        int get(int l, int r) {
            return get(0, 0, size, l, r, 0);
        }

        int get(int n, int nl, int nr, int l, int r, int cur) {
            if (l <= nl && nr <= r) {
                return cur + v[n][cur % lcm];
            }
            if (r <= nl || nr <= l) {
                return cur;
            }
            int mid = (nl + nr) / 2;
            cur = get(2 * n + 1, nl, mid, l, r, cur);
            cur = get(2 * n + 2, mid, nr, l, r, cur);
            return cur;
        }

        void set(int at, int a) {
            set(0, 0, size, at, a);
        }

        int[] set(int n, int nl, int nr, int at, int a) {
            if (nl <= at && at < nr) {
                if (nl + 1 == nr) {
                    gen(a, v[n]);
                } else {
                    int mid = (nl + nr) / 2;
                    combine(set(2 * n + 1, nl, mid, at, a), set(2 * n + 2, mid, nr, at, a), v[n]);
                }
            }
            return v[n];
        }
    }

    public static void solve(Input in, PrintWriter out) throws IOException {
        int n = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; ++i) {
            a[i] = in.nextInt();
        }
        ITree t = new ITree(a);
        int q = in.nextInt();
        for (int i = 0; i < q; ++i) {
            if (in.next().equals("A")) {
                out.println(t.get(in.nextInt() - 1, in.nextInt() - 1));
            } else {
                t.set(in.nextInt() - 1, in.nextInt());
            }
        }
    }

    public static void main(String[] args) throws IOException {
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