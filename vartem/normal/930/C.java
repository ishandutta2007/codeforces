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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.nextInt(), m = in.nextInt();

            int[] l = new int[n], r = new int[n];
            int[] cnt = new int[m + 1];
            for (int i = 0; i < n; i++) {
                l[i] = in.nextInt() - 1;
                r[i] = in.nextInt() - 1;
                cnt[l[i]]++;
                cnt[r[i] + 1]--;
            }
            for (int i = 1; i <= m; i++) {
                cnt[i] += cnt[i - 1];
            }

            int[] dpLeft = new int[m], dpRight = new int[m];
            BITMax tree = new BITMax(n);
            for (int i = 0; i < m; i++) {
                int get = tree.get(cnt[i]);
                if (get == Integer.MIN_VALUE) {
                    get = 0;
                }
                dpLeft[i] = get + 1;
                tree.update(cnt[i], dpLeft[i]);
            }
            tree = new BITMax(n);
            for (int i = m - 1; i >= 0; i--) {
                int get = tree.get(cnt[i]);
                if (get == Integer.MIN_VALUE) {
                    get = 0;
                }
                dpRight[i] = get + 1;
                tree.update(cnt[i], dpRight[i]);
            }
            int max = 0;
            for (int i = 0; i < m; i++) {
                max = Math.max(max, dpLeft[i] + dpRight[i] - 1);
            }
            out.println(max);
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