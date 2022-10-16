import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
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
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskA {
        int n;

        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.nextInt(), k = in.nextInt();
            int[] lots = new int[2 * n];
            int[] cur = new int[2 * n];
            Arrays.fill(lots, -1);
            Arrays.fill(cur, -1);

            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == 0) {
                        lots[j] = in.nextInt() - 1;
                    } else if (i == 1) {
                        cur[j] = in.nextInt() - 1;
                    } else if (i == 2) {
                        cur[n + (n - 1 - j)] = in.nextInt() - 1;
                    } else if (i == 3) {
                        lots[n + (n - 1 - j)] = in.nextInt() - 1;
                    }
                }
            }
            this.n = n;
            List<String> ans = new ArrayList<>();
            while (true) {
//            System.err.println(Arrays.toString(cur));
//            System.err.println(Arrays.toString(lots));
                for (int i = 0; i < 2 * n; i++) {
                    if (cur[i] != -1 && cur[i] == lots[i]) {
                        if (i < n) {
                            add(ans, cur[i], 0, i);
                        } else {
                            add(ans, cur[i], 3, (n - 1) - (i - n));
                        }
                        cur[i] = lots[i] = -1;
                    }
                }
                int max = -1;
                for (int i = 0; i < 2 * n; i++) {
                    max = Math.max(cur[i], max);
                }
                if (max == -1) {
                    break;
                }

                int start = -1;
                for (int i = 0; i < 2 * n; i++) {
                    if (cur[i] == -1) {
                        start = i;
                        break;
                    }
                }
                if (start == -1) {
                    out.println(-1);
                    return;
                }

                for (int i = (start + 2 * n - 1) % (2 * n); i != start; i = (i + 2 * n - 1) % (2 * n)) {
                    if (cur[i] != -1) {
                        add(ans, cur[i], nextRow(i), nextCol(i));
                        cur[(i + 1) % (2 * n)] = cur[i];
                        cur[i] = -1;
                    }
                }
            }
            out.println(ans.size());
            for (String s : ans) {
                out.println(s);
            }
        }

        private int nextCol(int i) {
            if (i < n - 1) {
                return i + 1;
            } else if (i == n - 1) {
                return n - 1;
            } else if (i == 2 * n - 1) {
                return 0;
            } else {
                int realCol = n - 1 - (i - n);
                return realCol - 1;
            }
        }

        private int nextRow(int i) {
            if (i < n - 1 || i == 2 * n - 1) {
                return 1;
            } else {
                return 2;
            }
        }

        private void add(List<String> ans, int i, int i1, int i2) {
            ans.add(String.format("%d %d %d", i + 1, i1 + 1, i2 + 1));
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

    }
}