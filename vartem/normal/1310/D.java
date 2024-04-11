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
        DPuteshestvie solver = new DPuteshestvie();
        solver.solve(1, in, out);
        out.close();
    }

    static class DPuteshestvie {
        int[][][] bestV;
        int[][][] bestCost;
        int n;
        int k;
        int[] p;
        boolean[] used;
        int bestAns = Integer.MAX_VALUE;

        void go(int pos) {
            if (pos == 0) {
                p[0] = 0;
                go(pos + 1);
                return;
            }
            if (pos == k >> 1) {
                p[pos] = 0;
                for (int i = 0; i < k >> 1; i++) {
                    used[p[i]] = true;
                }

                int cur = 0;
                for (int i = 0; i < k >> 1; i++) {
                    int u = p[i], v = p[i + 1];
                    int[] curV = bestV[u][v];
                    int ind = 0;
                    while (used[curV[ind]]) {
                        ind++;
                    }
                    cur += bestCost[u][v][ind];
                }
                bestAns = Math.min(bestAns, cur);
                for (int i = 0; i < k >> 1; i++) {
                    used[p[i]] = false;
                }
                return;
            }
            for (int i = 0; i < n; i++) {
                p[pos] = i;
                go(pos + 1);
            }
        }

        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            n = in.nextInt();
            k = in.nextInt();
            p = new int[k / 2 + 1];
            used = new boolean[n];
            int[][] dist = new int[n][n];
            for (int i = 0; i < n; i++) {
                dist[i] = in.nextIntArray(n);
            }
            bestV = new int[n][n][k / 2];
            bestCost = new int[n][n][k / 2];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    int[] curV = bestV[i][j];
                    int[] curCost = bestCost[i][j];
                    Arrays.fill(curCost, Integer.MAX_VALUE);
                    for (int t = 0; t < n; t++) {
                        if (t == i || t == j) {
                            continue;
                        }
                        int cur = dist[i][t] + dist[t][j];
                        for (int pos = 0; pos < k / 2; pos++) {
                            if (cur < curCost[pos]) {
                                for (int shift = k / 2 - 1; shift > pos; shift--) {
                                    curCost[shift] = curCost[shift - 1];
                                    curV[shift] = curV[shift - 1];
                                }
                                curCost[pos] = cur;
                                curV[pos] = t;
                                break;
                            }
                        }
                    }
                }
            }
            go(0);
            out.println(bestAns);

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

        public int[] nextIntArray(int n) {
            int[] ret = new int[n];
            for (int i = 0; i < n; i++) {
                ret[i] = nextInt();
            }
            return ret;
        }

    }
}