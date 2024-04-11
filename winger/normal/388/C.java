import java.io.*;
import java.util.Arrays;

public class CF388C {

    public static void solve(Input in, PrintWriter out) throws IOException {
        int n = in.nextInt();
        long a = 0, b = 0;
        long[] ar = new long[n];
        int arLen = 0;
        for (int i = 0; i < n; ++i) {
            int c = in.nextInt();
            for (int j = 0; j < c; ++j) {
                long x = in.nextLong();
                if (2 * j < c - 1) {
                    a += x;
                } else if (2 * j > c - 1) {
                    b += x;
                } else if (2 * j == c - 1) {
                    ar[arLen++] = x;
                }
            }
        }
        ar = Arrays.copyOf(ar, arLen);
        Arrays.sort(ar);
        for (int i = ar.length - 1; i >= 0; --i) {
            if ((ar.length - i) % 2 == 1) {
                a += ar[i];
            } else {
                b += ar[i];
            }
        }
        out.println(a + " " + b);
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