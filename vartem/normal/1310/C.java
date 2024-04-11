import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.FileNotFoundException;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.FileReader;
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
        CKrasniiMost solver = new CKrasniiMost();
        solver.solve(1, in, out);
        out.close();
    }

    static class CKrasniiMost {
        long MAX = (long) 1e18;
        int n;
        int m;
        char[] s;
        int[][] lcp;

        int cmp(int l1, int r1, int l2, int r2) {
            int l = lcp[l1][l2];
            if (l1 + l > r1 || l2 + l > r2) {
                return (r1 - l1) - (r2 - l2);
            } else {
                return s[l1 + l] - s[l2 + l];
            }
        }

        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            n = in.nextInt();
            m = in.nextInt();
            long k = in.nextLong();
            s = in.next().toCharArray();
            lcp = new int[n][n];
            for (int i = n - 1; i >= 0; i--) {
                for (int j = n - 1; j >= 0; j--) {
                    if (s[i] != s[j]) {
                        lcp[i][j] = 0;
                    } else {
                        lcp[i][j] = 1;
                        if (i + 1 < n && j + 1 < n) {
                            lcp[i][j] += lcp[i + 1][j + 1];
                        }
                    }
                }
            }

            Substr[] all = new Substr[n * (n + 1) / 2];
            int ptr = 0;
            for (int i = 0; i < n; i++) {
                for (int j = i; j < n; j++) {
                    all[ptr++] = new Substr(i, j);
                }
            }
            Arrays.sort(all);
            long[][] dp = new long[m + 1][n + 1];

            int left = -1, right = all.length - 1;
            while (left < right - 1) {
                int mid = (left + right) >>> 1;

                int cmpL = all[mid].l, cmpR = all[mid].r;
                int cmpLen = cmpR - cmpL;
                for (int i = 0; i <= m; i++) {
                    Arrays.fill(dp[i], 0);
                }
                dp[0][0] = 1;
                dp[0][1] = -1;
                for (int cnt = 0; cnt < m; cnt++) {
                    long cur = 0;
                    long[] prevDP = dp[cnt], nextDP = dp[cnt + 1];
                    for (int i = 0; i < n; i++) {
                        cur += prevDP[i];
                        if (cur > MAX) {
                            cur = MAX;
                        }
                        if (cur == 0) {
                            continue;
                        }
                        int l = lcp[i][cmpL];
                        if (cmpL + l > cmpR) {
                            // add on segment i + cmpLen + 1 .. n
                            nextDP[i + cmpLen + 1] += cur;
                            if (nextDP[i + cmpLen + 1] >= MAX) {
                                nextDP[i + cmpLen + 1] = MAX;
                            }
                        } else {
                            if (i + l < n && s[cmpL + l] < s[i + l]) {
                                // add on segment i + l + 1 .. n
                                nextDP[i + l + 1] += cur;
                                if (nextDP[i + l + 1] >= MAX) {
                                    nextDP[i + l + 1] = MAX;
                                }
                            }
                        }
                    }
                }

                long cur = 0;
                for (int i = 0; i <= n; i++) {
                    cur = Math.min(MAX, cur + dp[m][i]);
                }
                if (cur >= k) {
                    right = mid;
                } else {
                    left = mid;
                }
            }

            for (int i = all[right].l; i <= all[right].r; i++) {
                out.print(s[i]);
            }
            out.println();
        }

        class Substr implements Comparable<Substr> {
            int l;
            int r;

            public Substr(int l, int r) {
                this.l = l;
                this.r = r;
            }

            public int compareTo(Substr substr) {
                return -cmp(l, r, substr.l, substr.r);
            }

            public String toString() {
                return "Substr{" +
                        "l=" + l +
                        ", r=" + r +
                        '}';
            }

        }

    }

    static class FastScanner {
        public BufferedReader br;
        public StringTokenizer st;

        public FastScanner(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
        }

        public FastScanner(String fileName) {
            try {
                br = new BufferedReader(new FileReader(fileName));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
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

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}