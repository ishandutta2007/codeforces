import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.security.SecureRandom;
import java.util.List;
import java.util.StringTokenizer;
import java.math.BigInteger;
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
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        int MAX = 300_000;
        int MAX_ANS = 20;
        int MOD = 0;

        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = in.nextIntArray(n);

            int[] count = new int[MAX + 1];
            for (int i : a) {
                count[i] = 1;
            }
            MOD = BigInteger.probablePrime(30, new SecureRandom()).intValue();
            List<Integer> primes = NumberTheory.primes(MAX + 1);
            int[] t = new int[MAX + 1];
            for (int i = 1; i <= MAX; i++) {
                for (int j = i; j <= MAX; j += i) {
                    t[i] += count[j];
                }
            }

            int[] mobius = new int[MAX + 1];
            mobius[1] = 1;
            for (int i = 1; i <= MAX; i++) {
                for (int j = i + i; j <= MAX; j += i) {
                    mobius[j] -= mobius[i];
                }
            }
            int gcd = 0;
            for (int i : a) {
                gcd = MathUtils.gcd(gcd, i);
            }
            if (gcd != 1) {
                out.println(-1);
                return;
            }
            int[] clone = t.clone();
            for (int ans = 1; ans <= MAX_ANS; ans++) {
                int inverse1 = 0;
                for (int i = 1; i <= MAX; i++) {
                    inverse1 += mobius[i] * t[i];
                    if (inverse1 < 0) {
                        inverse1 += MOD;
                    }
                    if (inverse1 >= MOD) {
                        inverse1 -= MOD;
                    }
                }
                if (inverse1 != 0) {
                    out.println(ans);
                    return;
                }
                for (int i = 1; i <= MAX; i++) {
                    t[i] = (int) (1L * t[i] * clone[i] % MOD);
                }
            }
            throw new AssertionError();
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

        public int[] nextIntArray(int n) {
            int[] ret = new int[n];
            for (int i = 0; i < n; i++) {
                ret[i] = nextInt();
            }
            return ret;
        }

    }

    static class NumberTheory {
        public static List<Integer> primes(int max) {
            boolean[] isPrime = new boolean[max + 1];
            Arrays.fill(isPrime, true);
            List<Integer> ans = new ArrayList<>();
            for (int i = 2; i <= max; i++) {
                if (isPrime[i]) {
                    ans.add(i);
                    for (int j = 2 * i; j <= max; j += i) {
                        isPrime[j] = false;
                    }
                }
            }
            return ans;
        }

    }

    static class MathUtils {
        public static int gcd(int a, int b) {
            int t;
            while (a != 0) {
                t = b % a;
                b = a;
                a = t;
            }
            return b;
        }

    }
}