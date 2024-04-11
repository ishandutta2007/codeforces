import java.io.*;

public class VCFA {

    public static void solve(Input in, PrintWriter out) throws IOException {
        long s = in.nextLong();
        long x = in.nextLong();
        long d0 = 1, d1 = 0;
        for (int i = 0; i < 60; ++i) {
            long t0, t1;
            boolean bitX = (x & (1L << i)) != 0, bitS = (s & (1L << i)) != 0;
            if (!bitX) {
                if (bitS) {
                    t0 = t1 = d1;
                } else {
                    t0 = t1 = d0;
                }
            } else {
                if (bitS) {
                    t0 = 2 * d0;
                    t1 = 0;
                } else {
                    t0 = 0;
                    t1 = 2 * d1;
                }
            }
            d0 = t0;
            d1 = t1;
        }
        if (x == s) {
            d0 -= 2;
        }
        out.println(d0);
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