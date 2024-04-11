import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class CF273E {

    final static long mod = 1000000007;

    public static void solve(Input in, PrintWriter out) throws IOException {
        int n = in.nextInt();
        int p = in.nextInt();
        ArrayList<Long> starts = new ArrayList<Long>();
        ArrayList<Integer> gs = new ArrayList<Integer>();
        starts.add(0L);
        gs.add(0);
        starts.add(3L);
        gs.add(1);
        long u = 3, v = 1;
        for (int j1 = 0, j2 = 0; u < p; ) {
            while (starts.get(j1 + 1) <= u / 3) {
                ++j1;
            }
            while (starts.get(j2 + 1) <= u - u / 3) {
                ++j2;
            }
            long next1 = starts.get(j1 + 1) * 3;
            if (next1 / 3 < starts.get(j1 + 1) || (next1 - 1) / 3 >= starts.get(j1 + 1)) {
                throw new AssertionError();
            }
            long next2 = (starts.get(j2 + 1) * 3) / 2;
            while (next2 - next2 / 3 < starts.get(j1 + 1)) {
                next2++;
            }
            while (next2 - 1 - (next2 - 1) / 3 >= starts.get(j2 + 1)) {
                next2--;
            }
            if (next2 - next2 / 3 < starts.get(j2 + 1) || next2 - 1 - (next2 - 1) / 3 >= starts.get(j2 + 1)) {
                throw new AssertionError();
            }
            long next = Math.min(next1, next2);
            int val = mutex(gs.get(next >= next1 ? j1 + 1 : j1), gs.get(next >= next2 ? j2 + 1 : j2));
            if (val != v) {
                starts.add(next);
                gs.add(val);
            }
            u = next;
            v = val;
        }
//        System.err.println(starts.size());
        long[] c = new long[3];
        for (int i = 0; i < starts.size(); ++i) {
            long from = starts.get(i);
            long to = i == starts.size() - 1 ? p - 1 : starts.get(i + 1) - 1;
            if (to >= p) {
                to = p - 1;
            }
            if (from > to) {
                continue;
            }
//            System.err.println(from + " " + to + " " + gs.get(i));
//            System.err.println((to - from + 1) * p);
//            System.err.println(to * (to + 1) / 2);
//            System.err.println((from - 1) * (from) / 2);
            c[gs.get(i)] = (c[gs.get(i)] + (to - from + 1) * p) % mod;
            c[gs.get(i)] = (c[gs.get(i)] + mod - (to * (to + 1) / 2 % mod)) % mod;
            c[gs.get(i)] = (c[gs.get(i)] + (from - 1) * (from) / 2) % mod;
        }
        c[0] = (c[0] + mod - p) % mod;
//        for (int i = 1; i < p; ++i) {
//            c[g[i]] = (c[g[i]] + p - i) % mod;
//        }
        long[] d = new long[4];
        d[0] = 1;
        for (int it = 0; it < n; ++it) {
            long[] dd = new long[4];
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 3; ++j) {
                    dd[i ^ j] = (dd[i ^ j] + d[i] * c[j]) % mod;
                }
            }
            d = dd;
        }
        long ans = (d[1] + d[2] + d[3]) % mod;
        out.println(ans);
    }

    private static int mutex(int a, int b) {
        if (a != 0 && b != 0) return 0;
        if (a != 1 && b != 1) return 1;
        return 2;
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