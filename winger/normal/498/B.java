import java.io.*;

public class CF498B {

    public static void solve(Input in, PrintWriter out) throws IOException {
//        long t0 = System.currentTimeMillis();
        int n = in.nextInt();
        int t = in.nextInt();
//        int n = 5000, t = 5000;
        double[] d = new double[t + 1];
        double[] nd = new double[t + 1];
        d[0] = 1.0;
        double ans = 0.0;
        for (int i = 0; i < n; ++i) {
            double p = in.nextDouble() / 100.0;
            int k = in.nextInt();
//            double p = 0.3;
//            int k = 5000;
            double pk = Math.pow(1.0 - p, k);
            double cur = 0.0;
            for (int j = 0; j <= t; ++j) {
                nd[j] = cur * p;
                cur = cur * (1 - p) + d[j];
                if (j >= k) {
                    nd[j] += d[j - k] * pk;
                    cur -= d[j - k] * pk;
                }
            }
            for (int j = 0; j <= t; ++j) {
                ans += nd[j];
            }
            double[] tmp = d;
            d = nd;
            nd = tmp;
//            System.err.println(Arrays.toString(d));
        }
        out.println(ans);
//        System.err.println(System.currentTimeMillis() - t0);
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