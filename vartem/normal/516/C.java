import java.io.*;
import java.util.*;

public class C {

    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt(), m = in.nextInt();
        long[] d = new long[n], h = new long[n];
        for (int i = 0; i < n; i++) {
            d[i] = in.nextLong();
        }
        for (int i = 0; i < n; i++) {
            h[i] = in.nextLong();
        }

        long[] s = new long[n + 1];
        s[0] = 0;
        for (int i = 0; i < n; i++) {
            s[i + 1] = s[i] + d[i];
        }
        SegmentTree s1 = new SegmentTree(n * 2), s2 = new SegmentTree(n * 2);

        for (int i = 0; i < 2 * n; i++) {
            long cur = 2 * h[i % n];
            long dist = s[i % n];
            if (i >= n) {
                dist += s[n];
            }
            s1.set(i, cur + dist);
            s2.set(i, cur - dist);
        }

        for (int i = 0; i < m; i++) {
            int a = in.nextInt() - 1, b = in.nextInt() - 1;
            int left, right;
            if (a <= b) {
                left = b + 1;
                right = a - 1 + n;
            } else {
                left = b + 1;
                right = a - 1;
            }
            int best1 = s1.get(left, right);
            int best2 = s2.get(left, right);
            long ans = Long.MIN_VALUE;
            if (best2 == best1) {
                { // change best1
                    int first = s1.get(left, best2 - 1);
                    int second = s1.get(best2 + 1, right);
                    int newBest1 = first;
                    if (newBest1 == -1 || (second != -1 && s1.a[second] > s1.a[newBest1])) {
                        newBest1 = second;
                    }
                    ans = Math.max(s1.a[newBest1] + s2.a[best2], ans);
                }
                { // change best2
                    int first = s2.get(left, best1 - 1);
                    int second = s2.get(best1 + 1, right);
                    int newBest2 = first;
                    if (newBest2 == -1 || (second != -1 && s2.a[second] > s2.a[newBest2])) {
                        newBest2 = second;
                    }
                    ans = Math.max(s1.a[best1] + s2.a[newBest2], ans);
                }
            } else {
                ans = s1.a[best1] + s2.a[best2];
            }
            out.println(ans);
        }
    }

    class SegmentTree {
        int[] max;
        long[] a;
        int size;

        public SegmentTree(int n) {
            max = new int[n * 4];
            a = new long[n];
            size = n;
            Arrays.fill(a, Long.MIN_VALUE);
            build(0, n, 0);
        }

        void build(int l, int r, int i) {
            max[i] = l;
            if (l + 1 == r) {
                return;
            }
            int m = (l + r) >> 1;
            build(l, m, 2 * i + 1);
            build(m, r, 2 * i + 2);
        }

        void set(int pos, long val) {
            set(0, size, pos, val, 0);
        }

        void set(int l, int r, int pos, long val, int i) {
            if (l + 1 == r) {
                a[pos] = val;
                return;
            }
            int m = (l + r) >>> 1;
            if (pos < m) {
                set(l, m, pos, val, i * 2 + 1);
            } else {
                set(m, r, pos, val, 2 * i + 2);
            }
            if (a[max[2 * i + 1]] > a[max[2 * i + 2]]) {
                max[i] = max[2 * i + 1];
            } else {
                max[i] = max[2 * i + 2];
            }
        }

        int get(int l, int r) {
            return get(0, size, l, r + 1, 0);
        }

        int get(int l, int r, int left, int right, int i) {
            if (left <= l && r <= right) {
                return max[i];
            }
            if (left >= r || l >= right) {
                return -1;
            }
            int m = (l + r) >> 1;
            int s1 = get(l, m, left, right, 2 * i + 1);
            int s2 = get(m, r, left, right, 2 * i + 2);

            if (s1 == -1) {
                return s2;
            }
            if (s2 == -1) {
                return s1;
            }
            if (a[s1] > a[s2]) {
                return s1;
            } else {
                return s2;
            }
        }
    }

    void run() {
        in = new FastScanner();
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public FastScanner(String s) {
            try {
                br = new BufferedReader(new FileReader(s));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        String nextToken() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
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
        new C().run();
    }
}