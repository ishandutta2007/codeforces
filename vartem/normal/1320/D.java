import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.Random;
import java.io.InputStreamReader;
import java.io.FileNotFoundException;
import java.security.SecureRandom;
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
        DDostizhimieStroki solver = new DDostizhimieStroki();
        solver.solve(1, in, out);
        out.close();
    }

    static class DDostizhimieStroki {
        int BASE = 1000003;
        Random rng = new SecureRandom();
        int mod1 = BigInteger.probablePrime(30, rng).intValue();
        int mod2 = BigInteger.probablePrime(30, rng).intValue();
        int[] pref;

        int sum(int l, int r) {
            return pref[r + 1] - pref[l];
        }

        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.nextInt();
            char[] s = in.next().toCharArray();

            int[] pow1 = new int[n + 1], pow2 = new int[n + 1];
            pow1[0] = pow2[0] = 1;
            for (int i = 1; i <= n; i++) {
                pow1[i] = (int) ((long) pow1[i - 1] * BASE % mod1);
                pow2[i] = (int) ((long) pow2[i - 1] * BASE % mod2);
            }
            pref = new int[n + 1];
            for (int i = 0; i < n; i++) {
                pref[i + 1] = pref[i] + s[i] - '0';
            }

            int[] next0 = new int[n], prev0 = new int[n];
            int last = -1;
            for (int i = 0; i < n; i++) {
                if (s[i] == '0') {
                    last = i;
                }
                prev0[i] = last;
            }
            last = n;
            for (int i = n - 1; i >= 0; i--) {
                if (s[i] == '0') {
                    last = i;
                }
                next0[i] = last;
            }
            long[] hash1 = new long[n];
            long[] hash2 = new long[n];
            int last0 = -1;
            for (int i = 0; i < n; i++) {
                if (s[i] == '0') {
                    int lastBlock = (i - last0 - 1) % 2 + 1;
                    if (last0 >= 0) {
                        hash1[i] = hash1[last0] * BASE;
                        hash2[i] = hash2[last0] * BASE;
                    }
                    hash1[i] = (hash1[i] + lastBlock) % mod1;
                    hash2[i] = (hash2[i] + lastBlock) % mod2;
                    last0 = i;
                }
            }

            int q = in.nextInt();
            long[] result = new long[2];
            int[] inL = new int[2];
            for (int i = 0; i < q; i++) {
                inL[0] = in.nextInt() - 1;
                inL[1] = in.nextInt() - 1;
                int len = in.nextInt();
                for (int j = 0; j < 2; j++) {
                    int l = inL[j], r = l + len - 1;
                    int left0 = next0[l];
                    if (left0 > r) {
                        // 11..11
                        result[j] = (sum(l, r)) | ((long) sum(l, r) << 32);
                    } else {
                        int right0 = prev0[r];
                        int blocksInside = (right0 - left0 + 1) - sum(left0, right0) - 1;
                        long tmp1 = getHash(pow1[blocksInside], hash1, mod1, l, r, left0, right0);
                        long tmp2 = getHash(pow2[blocksInside], hash2, mod2, l, r, left0, right0);
                        result[j] = (tmp1 * BASE + sum(l, r)) % mod1;
                        result[j] |= ((tmp2 * BASE + sum(l, r)) % mod2) << 32;
                    }
                    result[j] = (result[j] * BASE + sum(l, r));
                }
                out.println(result[0] == result[1] ? "Yes" : "No");
            }
        }

        private long getHash(int pBI, long[] hash1, int mod, int l, int r, int left0, int right0) {
            long tmp = 0;
            tmp = (hash1[right0] + (mod - pBI) * hash1[left0]) % mod;
            tmp = (tmp + pBI * ((left0 - l) % 2 + 1)) % mod;
            tmp = (tmp * BASE + ((r - right0) % 2 + 1)) % mod;
            return tmp;
        }

    }

    static class FastScanner {
        public BufferedReader br;
        public StringTokenizer st;

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