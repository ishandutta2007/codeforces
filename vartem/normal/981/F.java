import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
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
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        Integer[] tmp;

        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.nextInt(), L = in.nextInt();
            int[] a = in.nextIntArray(n);
            int[] b = in.nextIntArray(n);
            tmp = new Integer[n];
            sort(a);
            sort(b);

            a = Arrays.copyOf(a, 3 * n);
            for (int i = 0; i < a.length; i++) {
                if (i < n) {
                    a[i] -= L;
                } else {
                    a[i] = a[i - n] + L;
                }
            }
            int left = -1, right = (L + 1) / 2;

            int[] l = new int[n], r = new int[n];
            BITMax bitMax = new BITMax(2 * n);
            while (left < right - 1) {
                int mid = (left + right) >>> 1;

                for (int i = 0; i < n; i++) {
                    int prevL = (i == 0) ? 0 : l[i - 1];
                    int prevR = (i == 0) ? 0 : r[i - 1];

                    int pos = b[i];
                    while (a[prevL] < pos - mid) {
                        prevL++;
                    }
                    while (prevR + 1 < a.length && a[prevR + 1] <= pos + mid) {
                        prevR++;
                    }
                    l[i] = prevL;
                    r[i] = prevR;
                }

                boolean ok = true;
                bitMax.clear();
                for (int i = 0; i < 2 * n; i++) {
                    int curL = (i < n) ? l[i] : l[i - n] + n;
                    int curR = (i < n) ? r[i] : r[i - n] + n;

                    bitMax.update(2 * n - i - 1, curL - i);
                    int max = bitMax.get(Math.min(2 * n - 1, 2 * n - i - 1 + n - 1));
                    if (curR - i - max < 0) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) {
                    left = mid;
                } else {
                    right = mid;
                }
            }


            out.println(right);
        }

        private void sort(int[] a) {
            for (int i = 0; i < a.length; i++) {
                tmp[i] = a[i];
            }
            Arrays.sort(tmp);
            for (int i = 0; i < a.length; i++) {
                a[i] = tmp[i];
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

        public int[] nextIntArray(int n) {
            int[] ret = new int[n];
            for (int i = 0; i < n; i++) {
                ret[i] = nextInt();
            }
            return ret;
        }

    }

    static class BITMax {
        int[] tree;

        public BITMax(int size) {
            tree = new int[size];
            Arrays.fill(tree, Integer.MIN_VALUE);
        }

        public int get(int pos) {
            int result = Integer.MIN_VALUE;
            while (pos >= 0) {
                result = Math.max(result, tree[pos]);
                pos = (pos & (pos + 1)) - 1;
            }
            return result;
        }

        public void update(int pos, int val) {
            while (pos < tree.length) {
                tree[pos] = Math.max(tree[pos], val);
                pos |= pos + 1;
            }
        }

        public void clear() {
            Arrays.fill(tree, Integer.MIN_VALUE);
        }

    }
}