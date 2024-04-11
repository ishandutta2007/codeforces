import java.io.*;

public class CF325A {

    public static void solve(Input in, PrintWriter out) throws IOException {
        int n = in.nextInt();
        long minx = 1000000000, miny = 1000000000, maxx = -1000000000, maxy = -1000000000;
        long s = 0;
        for (int i = 0; i < n; ++i) {
            long x1 = in.nextInt();
            long y1 = in.nextInt();
            long x2 = in.nextInt();
            long y2 = in.nextInt();
            s += (x2 - x1) * (y2 - y1);
            minx = Math.min(minx, x1);
            miny = Math.min(miny, y1);
            maxx = Math.max(maxx, x2);
            maxy = Math.max(maxy, y2);
        }
        out.println(maxx - minx == maxy - miny && s == (maxx - minx) * (maxy - miny) ? "YES" : "NO");
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