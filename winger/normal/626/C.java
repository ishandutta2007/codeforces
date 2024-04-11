import java.io.*;

public class CF626C {

    public static void solve(Input in, PrintWriter out) throws IOException {
        int n = in.nextInt();
        int m = in.nextInt();
        int l = 0, r = 1000000000;
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            int only2 = mid / 2;
            int only3 = mid / 3;
            int both = mid / 6;
            only2 -= both;
            only3 -= both;
            if (Math.max(0, n - only2) + Math.max(0, m - only3) <= both) {
                r = mid;
            } else {
                l = mid;
            }
        }
        out.println(r);
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