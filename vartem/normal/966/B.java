import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Comparator;
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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.nextInt(), x1 = in.nextInt(), x2 = in.nextInt();
            Pair[] a = new Pair[n];
            for (int i = 0; i < n; i++) {
                a[i] = new Pair(in.nextInt(), i + 1);
            }
            Arrays.sort(a, Comparator.comparing(p -> -p.val));


            int[] prefMin = new int[n], sufMin = new int[n];
            for (int i = 0; i < n; i++) {
                prefMin[i] = (x2 + a[i].val - 1) / a[i].val - (i + 1);
                if (i > 0) {
                    prefMin[i] = Math.min(prefMin[i - 1], prefMin[i]);
                }
            }
            for (int i = n - 1; i >= 0; i--) {
                sufMin[i] = (x2 + a[i].val - 1) / a[i].val - (i + 1);
                if (i + 1 < n) {
                    sufMin[i] = Math.min(sufMin[i], sufMin[i + 1]);
                }
            }
            int r = 0;
            for (int c = 1; c < n; c++) {
                while (r < n && (long) a[r].val * c >= x1) {
                    r++;
                }
                if (r < c) {
                    continue;
                }

                if (r - c - 1 >= 0) {
                    if (prefMin[r - c - 1] <= 0) {
                        out.println("Yes");
                        List<Integer> second = new ArrayList<>();
                        for (int i = 0; i <= r - c - 1; i++) {
                            if (prefMin[i] <= 0) {
                                for (int j = 0; j <= i; j++) {
                                    second.add(a[j].id);
                                }
                                break;
                            }
                        }
                        out.println(c + " " + second.size());
                        for (int i = r - c; i < r; i++) {
                            out.print(a[i].id + " ");
                        }
                        out.println();
                        for (int x : second) {
                            out.print(x + " ");
                        }
                        out.println();
                        return;
                    }
                }

                if (r < n) {
                    if (sufMin[r] <= -c) {
                        out.println("Yes");
                        List<Integer> second = new ArrayList<>();
                        for (int i = n - 1; i >= r; i--) {
                            if (sufMin[i] <= -c) {
                                for (int j = 0; j < r - c; j++) {
                                    second.add(a[j].id);
                                }
                                for (int j = r; j <= i; j++) {
                                    second.add(a[j].id);
                                }
                                break;
                            }
                        }
                        out.println(c + " " + second.size());
                        for (int i = r - c; i < r; i++) {
                            out.print(a[i].id + " ");
                        }
                        out.println();
                        for (int x : second) {
                            out.print(x + " ");
                        }
                        out.println();
                        return;
                    }
                }
            }

            out.println("No");
        }

        private class Pair {
            int val;
            int id;

            public Pair(int val, int id) {
                this.val = val;
                this.id = id;
            }

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