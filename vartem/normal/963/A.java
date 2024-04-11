import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
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
        long mod = 1000000009;

        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.nextInt(), a = in.nextInt(), b = in.nextInt(), k = in.nextInt();
            char[] c = in.next().toCharArray();

            int q = (int) (b * MathUtils.inv(a, mod) % mod);
            long ans = 0;
            long curQ = 1;
            for (int i = 0; i < k; i++) {
                ans = (ans + (c[i] == '+' ? 1 : -1) * curQ) % mod;
                curQ = curQ * q % mod;
            }
            ans = (ans % mod + mod) % mod;
            ans = ans * getSum((n + 1) / k, curQ) % mod;
            ans = ans * MathUtils.modPow(a, n, mod) % mod;
            out.println(ans);
        }

        private long getSum(int n, long curQ) {
            if (n == 1) {
                return 1;
            }
            if (n % 2 == 1) {
                return (1 + curQ * getSum(n - 1, curQ)) % mod;
            } else {
                return (1 + curQ) * getSum(n / 2, (curQ * curQ) % mod) % mod;
            }
        }

    }

    static class MathUtils {
        public static long modPow(long a, long b, long mod) {
            while (a < 0) {
                a += mod;
            }
            long res = 1;
            while (b > 0) {
                if ((b & 1) != 0) {
                    res = res * a % mod;
                }
                a = a * a % mod;
                b >>>= 1;
            }
            return res;
        }

        public static long inv(long a, long mod) {
            return modPow(a, mod - 2, mod);
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