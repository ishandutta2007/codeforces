import java.io.*;
import java.util.*;

public class A {

    long mod = (long) 1e9 + 7;

    class Num {
        final long a, b;

        public Num(long a, long b) {
            this.a = a % mod;
            this.b = b % mod;
        }

        public Num add(Num other) {
            return new Num(a + other.a, b + other.b);
        }

        public Num multiply(Num other) {
            return new Num(a * other.a + 5 * b * other.b, a * other.b + b * other.a);
        }
    }

    int k;

    long[][] coeffs;

    void prepare() {
        coeffs = new long[k + 1][k + 1];
        long[][] tmpCoeffs = new long[k + 1][k + 1];
        long factK = 1;
        coeffs[0][0] = 1;

        for (int free = 0; free < k; free++) {
            factK = factK * (free + 1) % mod;

            for (int i = 0; i <= k; i++) {
                for (int j = 0; j <= k; j++) {
                    if (coeffs[i][j] != 0) {
                        tmpCoeffs[i + 1][j] += coeffs[i][j];
                        if (tmpCoeffs[i + 1][j] >= mod) {
                            tmpCoeffs[i + 1][j] -= mod;
                        }

                        tmpCoeffs[i][j + 1] += coeffs[i][j];
                        if (tmpCoeffs[i][j + 1] >= mod) {
                            tmpCoeffs[i][j + 1] -= mod;
                        }

                        long add = coeffs[i][j] * (mod - free) % mod;
                        tmpCoeffs[i][j] += add;
                        if (tmpCoeffs[i][j] >= mod) {
                            tmpCoeffs[i][j] -= mod;
                        }
                    }
                }
            }

            for (int i = 0; i <= k; i++) {
                for (int j = 0; j <= k; j++) {
                    coeffs[i][j] = tmpCoeffs[i][j];
                    tmpCoeffs[i][j] = 0;
                }
            }
        }

        factK = inv(factK);
        for (int i = 0; i <= k; i++) {
            for (int j = 0; j <= k; j++) {
                coeffs[i][j] = coeffs[i][j] * factK % mod;
            }
        }
//        System.err.println(Arrays.deepToString(coeffs));

        pow1 = new Num[k + 1];
        powA = new Num[k + 1];
        pow2 = new Num[k + 1];
        powB = new Num[k + 1];

        pow1[0] = pow2[0] = powA[0] = powB[0] = new Num(1, 0);
        for (int i = 1; i <= k; i++) {
            pow1[i] = pow1[i - 1].multiply(PHI1);
            pow2[i] = pow2[i - 1].multiply(PHI2);
            powA[i] = powA[i - 1].multiply(A);
            powB[i] = powB[i - 1].multiply(B);
        }
    }

    long inv(long x) {
        return pow(x, mod - 2);
    }

    long pow(long a, long b) {
        long res = 1;
        while (b != 0) {
            if ((b & 1) == 1) {
                res = res * a % mod;
            }
            a = a * a % mod;
            b >>>= 1;
        }
        return res;
    }

    final Num PHI1 = new Num(inv(2), inv(2));
    final Num PHI2 = new Num(inv(2), mod - inv(2));
    final Num A = new Num(0, inv(5));
    final Num B = new Num(0, mod - inv(5));

    final Num ONE = new Num(1, 0);

    Num[] pow1, pow2, powA, powB;

    long get(long n) {
        Num result = new Num(0, 0);

        for (int i = 0; i <= k; i++) {
            for (int j = 0; j <= k; j++) {
                long coef = coeffs[i][j];
                if (coef == 0) {
                    continue;
                }

                Num cur = new Num(coef, 0).multiply(powA[i]).multiply(powB[j]);

                Num x = pow1[i].multiply(pow2[j]);
                x = geomSum(x, n + 1);

                result = result.add(cur.multiply(x));
            }
        }
        return result.a;
    }


    Num geomSum(Num x, long n) {
        if (n == 0) {
            return new Num(0, 0);
        }
        if (n % 2 == 0) {
            Num x2 = x.multiply(x);
            Num result = geomSum(x2, n / 2);
            return (ONE.add(x)).multiply(result);
        } else {
            return ONE.add(x.multiply(geomSum(x, n - 1)));
        }
    }

    public void solve() {
        k = in.nextInt();
        prepare();
        long l = in.nextLong(), r = in.nextLong();
//        for (int i = 0; i < 20; i++) {
//            Num fib = A.multiply(pow1[i]).add(B.multiply(pow2[i]));
//            System.err.println(fib.a + " " + fib.b);
//            System.err.println(get(i + 1) - get(i));
//        }
        out.println((get(r + 2) - get(l + 1) + mod) % mod);
    }

    public void run() {
        in = new FastScanner();
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    FastScanner in;
    PrintWriter out;

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(String fileName) {
            try {
                br = new BufferedReader(new FileReader(fileName));
            } catch (FileNotFoundException e) {
            }
        }

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String nextToken() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(nextToken());
        }

        long nextLong() {
            return Long.parseLong(nextToken());
        }

        double nextDouble() {
            return Double.parseDouble(nextToken());
        }
    }

    public static void main(String[] args) {
        new A().run();
    }
}