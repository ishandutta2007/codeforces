import java.io.*;
import java.util.*;

public class E {

    class SegmentTree {
        double[] x, y;
        double[] turn;
        int size;

        public SegmentTree(int n) {
            size = n;
            x = new double[4 * size];
            y = new double[4 * size];
            turn = new double[4 * size];
            build(0, size, 0);
        }

        void build(int l, int r, int i) {
            if (l + 1 == r) {
                x[i] = 1;
                y[i] = 0;
                turn[i] = 0;
                return;
            }
            int m = (l + r) >>> 1;
            build(l, m, 2 * i + 1);
            build(m, r, 2 * i + 2);
            x[i] = x[2 * i + 1] + x[2 * i + 2];
            y[i] = y[2 * i + 1] + y[2 * i + 2];
            turn[i] = 0;
        }

        void add(int pos, double len) {
            add(0, size, pos, len, 0);
        }

        void add(int l, int r, int pos, double len, int i) {
            if (l + 1 == r) {
                double curLen = Math.sqrt(x[i] * x[i] + y[i] * y[i]);
                double scale = (len + curLen) / curLen;
                x[i] *= scale;
                y[i] *= scale;
                return;
            }
            push(i);
            int m = (l + r) >>> 1;
            if (pos < m) {
                add(l, m, pos, len, 2 * i + 1);
            } else {
                add(m, r, pos, len, 2 * i + 2);
            }
            x[i] = x[2 * i + 1] + x[2 * i + 2];
            y[i] = y[2 * i + 1] + y[2 * i + 2];
        }

        void push(int pos) {
            turn(2 * pos + 1, turn[pos]);
            turn(2 * pos + 2, turn[pos]);
            turn[pos] = 0;
        }

        void turn(int pos, double angle) {
            turn[pos] += angle;
            double cos = Math.cos(angle), sin = Math.sin(-angle);
            double newX = x[pos] * cos - y[pos] * sin;
            double newY = x[pos] * sin + y[pos] * cos;
            x[pos] = newX;
            y[pos] = newY;
        }

        void turnAll(int from, int to, double angle) {
            turn(0, size, from, to, angle, 0);
        }

        void turn(int l, int r, int left, int right, double angle, int i) {
            if (left <= l && r <= right) {
                turn(i, angle);
                return;
            }
            if (r <= left || right <= l) {
                return;
            }
            push(i);
            int m = (l + r) >> 1;
            turn(l, m, left, right, angle, 2 * i + 1);
            turn(m, r, left, right, angle, 2 * i + 2);
            x[i] = x[2 * i + 1] + x[2 * i + 2];
            y[i] = y[2 * i + 1] + y[2 * i + 2];
        }
    }

    public void solve() {
        int n = in.nextInt(), m = in.nextInt();
        SegmentTree tree = new SegmentTree(n);

        for (int i = 0; i < m; i++) {
            int type = in.nextInt();
            int pos = in.nextInt() - 1;
            double z = in.nextDouble();
            if (type == 1) {
                tree.add(pos, z);
            } else {
                tree.turnAll(pos, n, z / 180 * Math.PI);
            }
            out.println(tree.x[0] + " " + tree.y[0]);
        }
    }

    public void run() {
        in = new FastScanner();
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    FastScanner in;
    PrintWriter out;

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(String fileName) {
            try {
                br = new BufferedReader(new FileReader(fileName));
            } catch (FileNotFoundException e) {
            }
        }

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String nextToken() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(nextToken());
        }

        long nextLong() {
            return Long.parseLong(nextToken());
        }

        double nextDouble() {
            return Double.parseDouble(nextToken());
        }
    }

    public static void main(String[] args) {
        new E().run();
    }
}