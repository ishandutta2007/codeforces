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
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskA {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int MAX = (int) 1e6 + 10;
            boolean[] prime = new boolean[MAX];
            Arrays.fill(prime, true);
            for (int i = 2; i < MAX; i++) {
                if (prime[i]) {
                    for (int j = 2 * i; j < MAX; j += i) {
                        prime[j] = false;
                    }
                }
            }
            int n = in.nextInt();
            int max = 1;
            for (int i = 2; i < MAX; i++) {
                if (prime[i] && n % i == 0) {
                    max = i;
                }
            }

            int[] best = new int[MAX];
            Arrays.fill(best, Integer.MAX_VALUE);
            for (int i = 2; i < MAX; i++) {
                if (prime[i]) {
                    for (int j = 2 * i; j < MAX; j += i) {
                        best[j] = Math.min(best[j], j - i + 1);
                    }
                }
            }

            int result = Integer.MAX_VALUE;
            for (int i = n - max + 1; i <= n; i++) {
                result = Math.min(result, best[i]);
            }
            out.println(result);
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