import java.io.*;
import java.util.*;

public class C2 {

    void solve() {

        int n = in.nextInt();
        int[] l = new int[n], r = new int[n];
        for (int i = 0; i < n; i++) {
            l[i] = in.nextInt();
            r[i] = in.nextInt();
        }

        double exp = 0;

        for (int mask = 1; mask < 1 << n; mask++) {
            if (Integer.bitCount(mask) >= 2) {
                for (int value = 0; value <= 10000; value++) {
                    double prob = 1;
                    for (int i = 0; i < n; i++) {
                        if ((mask & (1 << i)) != 0) {
                            if (l[i] > value || r[i] < value) {
                                prob = 0;
                            } else {
                                prob *= 1.0 / (r[i] - l[i] + 1);
                            }
                        } else {
                            int from = Math.max(l[i], 0), to = Math.min(r[i],
                                    value - 1);
                            if (from <= to) {
                                prob *= 1.0 * (to - from + 1)
                                        / (r[i] - l[i] + 1);
                            } else {
                                prob = 0;
                            }
                        }
                    }
                    exp += prob * value;
                }
            }
        }
        for (int best = 0; best < n; best++) {
            for (int mask = 1; mask < 1 << n; mask++) {
                if ((mask & (1 << best)) != 0) {
                    continue;
                }
                for (int value = 0; value <= 10000; value++) {
                    double prob = 1;
                    for (int i = 0; i < n; i++) {
                        if ((mask & (1 << i)) != 0) {
                            if (l[i] > value || r[i] < value) {
                                prob = 0;
                            } else {
                                prob *= 1.0 / (r[i] - l[i] + 1);
                            }
                        } else if (i == best) {
                            int from = Math.max(l[i], value + 1), to = Math
                                    .min(r[i], 10000);
                            if (from <= to) {
                                prob *= 1.0 * (to - from + 1)
                                        / (r[i] - l[i] + 1);
                            } else {
                                prob = 0;
                            }
                        } else {
                            int from = Math.max(l[i], 0), to = Math.min(r[i],
                                    value - 1);
                            if (from <= to) {
                                prob *= 1.0 * (to - from + 1)
                                        / (r[i] - l[i] + 1);
                            } else {
                                prob = 0;
                            }
                        }
                    }
                    exp += prob * value;
                }
            }
        }

        out.println(exp);
    }

    FastScanner in;
    PrintWriter out;

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

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    // TODO Auto-generated catch block
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    public static void main(String[] args) {
        new C2().run();

    }
}