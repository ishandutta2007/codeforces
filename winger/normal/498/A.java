import java.io.*;

public class CF498A {

    public static void solve(Input in, PrintWriter out) throws IOException {
        long x0 = in.nextLong();
        long y0 = in.nextLong();
        long x1 = in.nextLong();
        long y1 = in.nextLong();
        int n = in.nextInt();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            long a = in.nextLong();
            long b = in.nextLong();
            long c = in.nextLong();
            long v0 = a * x0 + b * y0 + c;
            long v1 = a * x1 + b * y1 + c;
            if (Long.signum(v0) != Long.signum(v1)) {
                ans++;
            }
        }
        out.println(ans);
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