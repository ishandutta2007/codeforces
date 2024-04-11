import java.io.*;

public class CF513D {

    static class Edge {
        int to;
        boolean left;

        public Edge(int to, boolean left) {
            this.to = to;
            this.left = left;
        }
    }

    static class ITree {
        int[] max;
        int size;

        ITree(int n) {
            size = 1;
            while (size < n) {
                size *= 2;
            }
            max = new int[2 * size - 1];
        }

        public int max(int l, int r) {
            if (l >= r) {
                return -1;
            }
            return max(0, 0, size, l, r);
        }

        private int max(int n, int nl, int nr, int l, int r) {
            if (l <= nl && nr <= r) {
                return max[n];
            }
            if (nr <= l || r <= nl) {
                return -1;
            }
            int mid = (nl + nr) / 2;
            return Math.max(
                max(2 * n + 1, nl, mid, l, r),
                max(2 * n + 2, mid, nr, l, r));
        }

        public int set(int i, int val) {
            return set(0, 0, size, i, val);
        }

        private int set(int n, int nl, int nr, int i, int val) {
            if (i < nl || nr <= i) {
                return max[n];
            }
            if (nl + 1 == nr) {
                return max[n] = val;
            }
            int mid = (nl + nr) / 2;
            return max[n] = Math.max(
                set(2 * n + 1, nl, mid, i, val),
                set(2 * n + 2, mid, nr, i, val));
        }
    }

    public static void solve(Input in, PrintWriter out) throws IOException {
        int n = in.nextInt();
        int m = in.nextInt();
        int[] leftTo = new int[n];
        int[] rightFrom = new int[n];
        int[] rightTo = new int[n];
        for (int i = 0; i < n; ++i) {
            leftTo[i] = i + 1;
            rightFrom[i] = n;
            rightTo[i] = i + 1;
        }
        for (int i = 0; i < m; ++i) {
            int from = in.nextInt() - 1;
            int to = in.nextInt() - 1;
            if (from >= to) {
                out.println("IMPOSSIBLE");
                return;
            }
            if (in.next().equals("LEFT")) {
                leftTo[from] = Math.max(leftTo[from], to + 1);
            } else {
                rightFrom[from] = Math.min(rightFrom[from], to);
                rightTo[from] = Math.max(rightTo[from], to + 1);
            }
        }
        ITree t = new ITree(n);
        for (int i = n - 1; i >= 0; --i) {
            int val = t.max(i + 1, Math.max(leftTo[i], rightTo[i]));
            val = Math.max(val, i + 1);
            t.set(i, val);
        }
        for (int i = 0; i < n; ++i) {
            leftTo[i] = Math.max(i + 1, t.max(i + 1, leftTo[i]));
            if (leftTo[i] > rightFrom[i]) {
                out.println("IMPOSSIBLE");
                return;
            }
            rightFrom[i] = leftTo[i];
            rightTo[i] = Math.max(rightFrom[i], t.max(rightFrom[i], rightTo[i]));
        }
//        print(out, leftTo, 0, n);
        int[] sti = new int[n];
        int[] stto = new int[n];
        int[] ststep = new int[n];
        int stp = 1;
        sti[0] = 0;
        stto[0] = n;
        while (stp > 0) {
            int i = sti[stp - 1];
            int to = stto[stp - 1];
            int step = ststep[stp - 1]++;
            if (step == 0) {
                if (leftTo[i] > i + 1) {
                    sti[stp] = i + 1;
                    stto[stp] = leftTo[i];
                    ststep[stp] = 0;
                    stp++;
                }
            } else if (step == 1) {
                out.print((i + 1) + " ");
            } else if (step == 2) {
                if (to > leftTo[i]) {
                    sti[stp] = leftTo[i];
                    stto[stp] = to;
                    ststep[stp] = 0;
                    stp++;
                }
            } else {
                stp--;
            }
        }
        out.println();
    }

    private static void print(PrintWriter out, int[] leftTo, int i, int to) {
        if (leftTo[i] > i + 1) {
            print(out, leftTo, i + 1, leftTo[i]);
        }
        out.print((i + 1) + " ");
        if (to > leftTo[i]) {
            print(out, leftTo, leftTo[i], to);
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