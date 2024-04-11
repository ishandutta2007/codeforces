import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Random;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        int v;
        int mod;
        PrintWriter out;
        int[] path = new int[1000];
        Random rng = new Random();

        void go(int depth, int size, int maxLen, List<Integer> result) {
            int u = path[size - 1];
            result.add(u);
            if (depth >= maxLen) {
                return;
            }

            {
                int oldSize = size;
                int k = 1;
                for (int i = 0; i < k; i++) {
                    path[size] = path[size - 1] + 1;
                    if (path[size] == mod) {
                        path[size] -= mod;
                    }
                    size++;
                }
                path[size] = MathUtils.invInt(path[size - 1], mod);
                size++;
                go(depth + 1, size, maxLen, result);
                size = oldSize;
            }

            {
                int oldSize = size;
                int k = 1;
                for (int i = 0; i < k; i++) {
                    path[size] = path[size - 1] - 1;
                    if (path[size] == -1) {
                        path[size] += mod;
                    }
                    size++;
                }
                path[size] = MathUtils.invInt(path[size - 1], mod);
                size++;
                go(depth + 1, size, maxLen, result);
                size = oldSize;
            }
        }

        boolean collect(int depth, int size, int maxLen, List<Integer> result) {
            int u = path[size - 1];
            if (u == v) {
                int curU = path[0];
                for (int i = 1; i < size; i++) {
                    int p = path[i];
                    if ((p - curU + mod) % mod == 1) {
                        result.add(1);
                    } else if ((p - curU + mod) % mod == mod - 1) {
                        result.add(2);
                    } else {
                        result.add(3);
                    }
                    curU = p;
                }
                return true;
            }

            if (depth >= maxLen) {
                return false;
            }

            {
                int oldSize = size;
                int k = 1;
                for (int i = 0; i < k; i++) {
                    path[size] = path[size - 1] + 1;
                    if (path[size] == mod) {
                        path[size] -= mod;
                    }
                    size++;
                }
                path[size] = MathUtils.invInt(path[size - 1], mod);
                size++;
                if (collect(depth + 1, size, maxLen, result)) {
                    return true;
                }
                size = oldSize;
            }

            {
                int oldSize = size;
                int k = 1;
                for (int i = 0; i < k; i++) {
                    path[size] = path[size - 1] - 1;
                    if (path[size] == -1) {
                        path[size] += mod;
                    }
                    size++;
                }
                path[size] = MathUtils.invInt(path[size - 1], mod);
                size++;
                if (collect(depth + 1, size, maxLen, result)) {
                    return true;
                }
                size = oldSize;
            }
            return false;
        }

        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int u = in.nextInt(), v = in.nextInt(), p = in.nextInt();
            this.out = out;
            this.v = v;
            this.mod = p;
            this.rng = new Random(p);
            List<Integer> fromU = new ArrayList<>(), fromV = new ArrayList<>();
            path[0] = u;
            go(0, 1, 19, fromU);
            path[0] = v;
            go(0, 1, 19, fromV);
            Collections.sort(fromU);
            Collections.sort(fromV);

            int ptr = 0;
            for (int val : fromU) {
                while (ptr < fromV.size() && fromV.get(ptr) < val) {
                    ptr++;
                }

                if (val >= fromV.get(ptr) && val - fromV.get(ptr) <= 110) {
                    printAnswer(u, val, fromV.get(ptr), v);
                    return;
                } else if (ptr + 1 < fromV.size() && fromV.get(ptr + 1) - val <= 110) {
                    printAnswer(u, val, fromV.get(ptr + 1), v);
                    return;
                }
            }
            throw new AssertionError();
        }

        private void printAnswer(int u, int valU, int valV, int v) {
            List<Integer> result = new ArrayList<>();
            path[0] = u;
            this.v = valU;
            collect(0, 1, 19, result);
            int x = u;
            for (int i : result) {
                if (i == 1) {
                    x = (x + 1) % mod;
                } else if (i == 2) {
                    x = (x + mod - 1) % mod;
                } else {
                    x = MathUtils.invInt(x, mod);
                }
            }

            while (valU != valV) {
                if (valU < valV) {
                    result.add(1);
                    valU++;
                } else {
                    result.add(2);
                    valU--;
                }
            }

            List<Integer> tmpResult = new ArrayList<>();
            path[0] = v;
            this.v = valV;
            collect(0, 1, 19, tmpResult);
            for (int i = tmpResult.size() - 1; i >= 0; i--) {
                int c = tmpResult.get(i);
                result.add(new int[]{0, 2, 1, 3}[c]);
            }
            out.println(result.size());
            x = u;
            for (int i : result) {
                out.print((i + " "));
                if (i == 1) {
                    x = (x + 1) % mod;
                } else if (i == 2) {
                    x = (x + mod - 1) % mod;
                } else {
                    x = MathUtils.invInt(x, mod);
                }
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

    static class MathUtils {
        public static int invInt(int a, int mod) {
            int res = 1;
            int b = mod - 2;
            while (b > 0) {
                if ((b & 1) != 0) {
                    res = (int) ((long) res * a % mod);
                }
                a = (int) ((long) a * a % mod);
                b >>>= 1;
            }
            return res;
        }

    }
}