import java.io.*;

public class VCFB {

    static class Fenwick {
        int[] a;

        Fenwick(int n) {
            a = new int[n];
        }

        int get(int i) {
            int ret = 0;
            while (i >= 0) {
                ret += a[i];
                i = (i & (i + 1)) - 1;
            }
            return ret;
        }

        void add(int i, int val) {
            while (i < a.length) {
                a[i] += val;
                i = i | (i + 1);
            }
        }
    }

    public static void solve(Input in, PrintWriter out) throws IOException {
        int n = in.nextInt();
        int k = in.nextInt();
        int a = in.nextInt();
        int b = in.nextInt();
        int qs = in.nextInt();
        int[] sum = new int[n];
        Fenwick la = new Fenwick(n);
        Fenwick lb = new Fenwick(n);
        for (int q = 0; q < qs; ++q) {
            if (in.nextInt() == 1) {
                int at = in.nextInt() - 1;
                int v = in.nextInt();
                la.add(at, -Math.min(a, sum[at]));
                lb.add(at, -Math.min(b, sum[at]));
                sum[at] += v;
                la.add(at, +Math.min(a, sum[at]));
                lb.add(at, +Math.min(b, sum[at]));
            } else {
                int at = in.nextInt() - 1;
                out.println(lb.get(at - 1) + la.get(n - 1) - la.get(at + k - 1));
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