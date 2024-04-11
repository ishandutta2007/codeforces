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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.nextInt(), m = in.nextInt();
            int[] x = new int[n], y = new int[n];
            for (int i = 0; i < n; i++) {
                x[i] = in.nextInt();
                y[i] = in.nextInt();
            }

            long[] ans = new long[n];
            Item[] items = new Item[n];
            for (int i = 0; i < n; i++) {
                items[i] = new Item(y[i] - x[i], i);
            }
            Arrays.sort(items);

            long sumX = 0;
            for (int i : x) {
                sumX += i;
            }

            long curSum = 0;
            for (int i = 0; i < n; i++) {
                Item cur = items[i];
                ans[cur.id] += (long) x[cur.id] * (n - 1);
                ans[cur.id] += sumX - x[cur.id];
                ans[cur.id] += (n - i - 1) * cur.value;
                ans[cur.id] += curSum;
                curSum += cur.value;
            }

            for (int i = 0; i < m; i++) {
                int from = in.nextInt() - 1, to = in.nextInt() - 1;
                long value = Math.min(x[from] + y[to], x[to] + y[from]);
                ans[from] -= value;
                ans[to] -= value;
            }
            for (int i = 0; i < n; i++) {
                out.print(ans[i] + " ");
            }
        }

        class Item implements Comparable<Item> {
            long value;
            int id;

            public Item(long value, int id) {
                this.value = value;
                this.id = id;
            }

            public int compareTo(Item o) {
                return Long.compare(value, o.value);
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