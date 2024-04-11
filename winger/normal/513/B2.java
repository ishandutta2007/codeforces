import java.io.*;
import java.util.Arrays;

public class CF513B {

    public static void solve(Input in, PrintWriter out) throws IOException {
        int n = in.nextInt();
        long k = in.nextLong() - 1;
        int[] ans = new int[n];
        int from = 0;
        int j = n;
        for (int i = 0; from < n; ++i) {
            while (from < n - 1 && k >= 1L << (n - from - 2)) {
                k -= 1L << (n - from - 2);
                ans[--j] = from++;
            }
            ans[i] = from;
            from++;
        }
        for (int i = 0; i < n; ++i) {
            out.print((ans[i] + 1) + " ");
        }
        out.println();
//        rec(0, 0, new int[n]);
    }

    private static void rec(int it, int mask, int[] p) {
        if (it == p.length) {
            int sum = 0;
            for (int i = 0; i < p.length; ++i) {
                int v = p[i];
                for (int j = i; j < p.length; ++j) {
                    v = Math.min(v, p[j]);
                    sum += v;
                }
            }
            System.err.println(Arrays.toString(p) + " " + sum);
            return;
        }
        for (p[it] = 0; p[it] < p.length; ++p[it]) {
            if ((mask & (1 << p[it])) == 0) {
                rec(it + 1, mask | (1 << p[it]), p);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        PrintWriter out = new PrintWriter(System.out);
        solve(new Input(new BufferedReader(new InputStreamReader(System.in))), out);
        out.close();
    }

    static class Input {
        BufferedReader in;
        StringBuilder sb = new StringBuilder();

        public Input(BufferedReader in) {
            this.in = in;
        }

        public Input(String s) {
            this.in = new BufferedReader(new StringReader(s));
        }

        public String next() throws IOException {
            sb.setLength(0);
            while (true) {
                int c = in.read();
                if (c == -1) {
                    return null;
                }
                if (" \n\r\t".indexOf(c) == -1) {
                    sb.append((char)c);
                    break;
                }
            }
            while (true) {
                int c = in.read();
                if (c == -1 || " \n\r\t".indexOf(c) != -1) {
                    break;
                }
                sb.append((char)c);
            }
            return sb.toString();
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