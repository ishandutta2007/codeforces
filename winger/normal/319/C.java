import java.io.*;

public class CF319C {

    public static void solve(Input in, PrintWriter out) throws IOException {
        int n = in.nextInt();
        long[] a = new long[n];
        for (int i = 0; i < n; ++i) {
            a[i] = in.nextInt();
        }
        long[] b = new long[n];
        for (int i = 0; i < n; ++i) {
            b[i] = in.nextInt();
        }
        long[] d = new long[n];
        d[0] = 0;
        int[] st = new int[n];
        int stp = 1;
        // (b2-b1)/(a1-a2) >= (b3-b1)/(a1-a3)
        for (int i = 1, j = 0; i < n; ++i) {
            j = Math.min(j, stp - 1);
            while (j + 1 < stp && d[st[j + 1]] + b[st[j + 1]] * a[i] <= d[st[j]] + b[st[j]] * a[i]) {
                j++;
            }
            d[i] = d[st[j]] + b[st[j]] * a[i];
            while (stp > 1 && -1.0 * (d[st[stp - 1]] - d[st[stp - 2]]) / (b[st[stp - 1]] - b[st[stp - 2]]) >= -1.0 * (d[i] - d[st[stp - 2]]) / (b[i] - b[st[stp - 2]])) {
                stp--;
            }
            st[stp++] = i;
        }
        out.println(d[n - 1]);
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