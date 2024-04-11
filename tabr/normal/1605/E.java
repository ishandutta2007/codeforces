import java.util.*;
import java.lang.*;
import java.io.*;

public class Main {
    public static void solve(InputReader in, PrintWriter out) {
        int n = in.nextInt();
        long[] a = new long[n];
        long[] b = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        for (int i = 0; i < n; i++) {
            b[i] = in.nextInt();
        }
        int[] c = new int[n];
        Arrays.fill(c, -1);
        for (int i = 2; i <= n; i++) {
            for (int j = i * 2; j <= n; j += i) {
                a[j - 1] += b[i - 1] - a[i - 1];
                c[j - 1] -= c[i - 1];
            }
        }
        long d = 0;
        List<Long> p = new ArrayList<>();
        List<Long> q = new ArrayList<>();
        for (int i = 1; i < n; i++) {
            a[i] -= b[i];
            if (c[i] == 1) {
                p.add(a[i]);
            } else if (c[i] == -1) {
                q.add(a[i]);
            } else {
                assert (c[i] == 0);
                d += Math.abs(a[i]);
            }
        }
        Collections.sort(p);
        Collections.sort(q);
        long[] pref_p = new long[p.size() + 1];
        long[] pref_q = new long[q.size() + 1];
        for (int i = 0; i < p.size(); i++) {
            pref_p[i + 1] = pref_p[i] + p.get(i);
        }
        for (int i = 0; i < q.size(); i++) {
            pref_q[i + 1] = pref_q[i] + q.get(i);
        }
        int tt = in.nextInt();
        while (tt-- > 0) {
            long x = in.nextInt();
            x = a[0] - x;
            long ans = Math.abs(x) + d;
            x = -x;
            int lo = -1, hi = p.size();
            while (hi - lo > 1) {
                int mid = (hi + lo) / 2;
                if (p.get(mid) >= x) {
                    hi = mid;
                } else {
                    lo = mid;
                }
            }
            ans += x * hi - pref_p[hi];
            ans += pref_p[p.size()] - pref_p[hi] - x * (p.size() - hi);
            x = -x;
            lo = -1;
            hi = q.size();
            while (hi - lo > 1) {
                int mid = (hi + lo) / 2;
                if (q.get(mid) >= x) {
                    hi = mid;
                } else {
                    lo = mid;
                }
            }
            ans += x * hi - pref_q[hi];
            ans += pref_q[q.size()] - pref_q[hi] - x * (q.size() - hi);
            out.println(ans);
        }
    }

    public static void main(String[] args) throws java.lang.Exception {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
//        int tt = in.nextInt();
        int tt = 1;
        for (int qq = 1; qq <= tt; qq++) {
            solve(in, out);
        }
        out.close();
    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }
    }
}