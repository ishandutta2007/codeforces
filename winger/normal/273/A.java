import java.io.*;
import java.util.StringTokenizer;

public class CF273A {

//    static class ITree {
//        long[] max;
//        long[] val;
//        int size;
//
//        ITree(int n) {
//            size = 1;
//            while (size < n) {
//                size *= 2;
//            }
//            max = new long[2 * size - 1];
//            val = new long[2 * size - 1];
//        }
//
//        long get(int l, int r) {
//            return get(l, r, 0, 0, size);
//        }
//
//        private long get(int l, int r, int n, int nl, int nr) {
//            if (l <= nl && nr <= r) {
//                return max[n];
//            }
//            if (r <= nl || nr <= l) {
//                return 0;
//            }
//            int mid = (nl + nr) / 2;
//            return Math.max(
//                get(l, r, 2 * n + 0, nl, mid),
//                get(l, r, 2 * n + 1, mid, nr)
//            );
//        }
//
//        long set(int l, int r, long v) {
//            return set(l, r, v, 0, 0, size);
//        }
//
//        long set(int l, int r, long v, int n, int nl, int nr) {
//            if (l <= nl && nr <= r) {
//                return max[n] = val[n] = v;
//            }
//            if (r <= nl || nr <= l) {
//                return max[n];
//            }
//            int mid = (nl + nr) / 2;
//            return max[n] = Math.max(val[n], Math.max(
//                    set(l, r, v, 2 * n + 0, nl, mid),
//                    set(l, r, v, 2 * n + 1, mid, nr)
//            ));
//        }
//    }

    public static void solve(Input in, PrintWriter out) throws IOException {
        int n = in.nextInt();
        long[] a = new long[n];
        int[] b = new int[n];
        for (int i = 0; i < n; ++i) {
            a[n - i - 1] = in.nextInt();
            b[n - i - 1] = i;
        }
        int s = n;
        int m = in.nextInt();
        for (int i = 0; i < m; ++i) {
            long w = in.nextInt();
            long h = in.nextInt();
            long pos = 0;
            while (s > 0 && b[s - 1] < w) {
                pos = a[s - 1];
                --s;
            }
            out.println(pos);
            pos += h;
            while (s > 0 && a[s - 1] <= pos) {
                --s;
            }
            a[s] = pos;
            b[s] = 0;
            s++;
        }
    }

    public static void main(String[] args) throws IOException {
        PrintWriter out = new PrintWriter(System.out);
        solve(new Input(new BufferedReader(new InputStreamReader(System.in))), out);
        out.close();
    }

    static class Input {
        BufferedReader in;
        StringTokenizer st;

        public Input(BufferedReader in) {
            this.in = in;
            eat("");
        }

        public Input(String s) {
            this.in = new BufferedReader(new StringReader(s));
        }

        public void eat(String str) {
            st = new StringTokenizer(str);
        }

        public String next() throws IOException {
            while (!st.hasMoreTokens()) {
                String line = in.readLine();
                if (line == null) {
                    return null;
                }
                eat(line);
            }
            return st.nextToken();
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