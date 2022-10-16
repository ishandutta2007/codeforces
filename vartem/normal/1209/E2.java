import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.FileReader;
import java.util.Comparator;
import java.util.Collections;
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
        TaskE2 solver = new TaskE2();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE2 {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int t = in.nextInt();
            while (t-- > 0) {
                int n = in.nextInt(), m = in.nextInt();
                int[][] a = new int[n][m];
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        a[i][j] = in.nextInt();
                    }
                }
                boolean[][] interesting = new boolean[n][m];
                boolean[] hasInteresting = new boolean[m];
                for (int i = 0; i < n; i++) {
                    List<Pair> list = new ArrayList<>();
                    for (int j = 0; j < m; j++) {
                        list.add(new Pair(a[i][j], j));
                    }
                    Collections.sort(list, Comparator.comparing(pair -> -pair.val));
                    for (int j = 0; j < m && j <= n; j++) {
                        interesting[i][list.get(j).pos] = true;
                        hasInteresting[list.get(j).pos] = true;
                    }
                }
                boolean[] goodMask = new boolean[1 << n];
                for (int mask = 0; mask < 1 << n; mask++) {
                    int best = Integer.MAX_VALUE;
                    int cur = mask;
                    do {
                        best = Math.min(best, cur);
                        cur = (cur >> 1) | ((cur & 1) << (n - 1));
                    } while (cur != mask);
                    goodMask[mask] = (mask == best);
                }
                int[] dp = new int[1 << n];
                for (int i = 0; i < m; i++) {
                    if (!hasInteresting[i]) {
                        continue;
                    }
                    for (int j = 0; j < n; j++) {
                        if (!interesting[j][i]) {
                            continue;
                        }
                        int supermask = (1 << n) - 1 - (1 << j);
                        int val = a[j][i];
                        for (int mask = supermask; ; mask = (mask - 1) & supermask) {
                            if (dp[mask] + val > dp[mask | (1 << j)]) {
                                dp[mask | (1 << j)] = dp[mask] + val;
                            }
                            if (mask == 0) {
                                break;
                            }
                        }
                    }
                    for (int mask = 0; mask < 1 << n; mask++) {
                        if (!goodMask[mask]) {
                            continue;
                        }
                        int best = 0;
                        int cur = mask;
                        do {
                            best = Math.max(best, dp[cur]);
                            cur = (cur >> 1) | ((cur & 1) << (n - 1));
                        } while (cur != mask);
                        do {
                            dp[cur] = best;
                            cur = (cur >> 1) | ((cur & 1) << (n - 1));
                        } while (cur != mask);
                    }
                }
                out.println(dp[(1 << n) - 1]);
            }
        }

        class Pair {
            int val;
            int pos;

            public Pair(int val, int pos) {
                this.val = val;
                this.pos = pos;
            }

        }

    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

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

    }
}