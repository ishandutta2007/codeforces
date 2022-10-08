import java.io.*;

public class CF513C {

    public static void solve(Input in, PrintWriter out) throws IOException {
        int n = in.nextInt();
        int[] l = new int[n];
        int[] r = new int[n];
        for (int i = 0; i < n; ++i) {
            l[i] = in.nextInt();
            r[i] = in.nextInt();
        }
        double ans = 0.0, ansp = 0.0;
        for (int x = 1; x <= 10000; ++x) {
            double p = 0.0;
            for (int more = -1; more < n; ++more) {
                double[] ps = new double[n + 1];
                ps[0] = 1.0;
                for (int i = 0; i < n; ++i) {
                    if (i == more) {
                        double pMore = l[i] <= x ? Math.max(0, r[i] - x) / (r[i] - l[i] + 1.0) : 1.0;
                        for (int t = 0; t <= n; ++t) {
                            ps[t] *= pMore;
                        }
                    } else {
                        double pEq = l[i] <= x && x <= r[i] ? 1.0 / (r[i] - l[i] + 1.0) : 0.0;
                        double pLess = x <= r[i] ? Math.max(0, x - l[i]) / (r[i] - l[i] + 1.0) : 1.0;
                        for (int t = n; t > 0; --t) {
                            ps[t] = ps[t - 1] * pEq + ps[t] * pLess;
                        }
                        ps[0] *= pLess;
                    }
                }
                for (int i = more == -1 ? 2 : 1; i <= n; ++i) {
//                    if (ps[i] != 0) {
//                        System.err.println(x + " " + more + " " + i + " " + ps[i]);
//                    }
                    p += ps[i];
                }
            }
            ansp += p;
            ans += x * p;
        }
        out.println(ans);
//        System.err.println(ansp);
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