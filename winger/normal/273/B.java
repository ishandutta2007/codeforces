import java.io.*;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class CF273B {

    static class Pair {
        int x;
        int y;

        Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Pair pair = (Pair) o;

            if (x != pair.x) return false;
            if (y != pair.y) return false;

            return true;
        }

        @Override
        public int hashCode() {
            int result = x;
            result = 239 * result + y;
            return result;
        }
    }

    public static void solve(Input in, PrintWriter out) throws IOException {
        int n = in.nextInt();
        HashMap<Integer, Integer> xs = new HashMap<Integer, Integer>();
        HashMap<Pair, Integer> ps = new HashMap<Pair, Integer>();
        for (int i = 0; i < 2 * n; ++i) {
            int x = in.nextInt();
//            int x = 1;
            int y = i % n;
            if (xs.containsKey(x)) {
                xs.put(x, xs.get(x) + 1);
            } else {
                xs.put(x, 1);
            }
            Pair p = new Pair(x, y);
            if (ps.containsKey(p)) {
                ps.put(p, ps.get(p) + 1);
            } else {
                ps.put(p, 1);
            }
        }
        long mod = in.nextLong();
        long[] fs = new long[2 * n + 1];
        for (Map.Entry<Integer, Integer> entry : xs.entrySet()) {
            fs[entry.getValue()]++;
        }
        for (Map.Entry<Pair, Integer> entry : ps.entrySet()) {
            fs[entry.getValue()]--;
        }
//        System.err.println(Arrays.toString(fs));
        for (int i = 2 * n - 1; i >= 0; --i) {
            fs[i] += fs[i + 1];
        }
        long ans = 1;
//        System.err.println(Arrays.toString(fs));
        boolean[] prime = new boolean[2 * n + 1];
        Arrays.fill(prime, true);
        for (int i = 2; i <= 2 * n; ++i) {
            if (!prime[i]) {
                continue;
            }
            long s = 0;
            for (long j = i; j <= 2 * n; j *= i) {
                for (long k = j; k <= 2 * n; k += j) {
                    s += fs[(int)k];
                    prime[(int)k] = false;
                }
            }
//            System.err.println(i + " " + s);
            if (s < 0) throw new AssertionError(i + " " + s);
            if (s > 0) {
                ans = (ans * pow(i, s, mod)) % mod;
            }
        }
        out.println(ans);
    }

    private static long pow(long x, long pow, long mod) {
        long r = 1;
        while (pow > 0) {
            if (pow % 2 == 1) {
                r = (r * x) % mod;
            }
            pow /= 2;
            x = (x * x) % mod;
        }
        return r;
    }

    public static void main(String[] args) throws IOException {
        PrintWriter out = new PrintWriter(System.out);
        solve(new Input(new BufferedReader(new InputStreamReader(System.in))), out);
        out.close();
    }

    static class Input {
        BufferedReader in;
        StringTokenizer st;

        public Input(BufferedReader in) {
            this.in = in;
            eat("");
        }

        public Input(String s) {
            this.in = new BufferedReader(new StringReader(s));
        }

        public void eat(String str) {
            st = new StringTokenizer(str);
        }

        public String next() throws IOException {
            while (!st.hasMoreTokens()) {
                String line = in.readLine();
                if (line == null) {
                    return null;
                }
                eat(line);
            }
            return st.nextToken();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        public double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }
    }
}