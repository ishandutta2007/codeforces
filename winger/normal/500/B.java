import java.io.*;

public class CF500B {

    public static void solve(Input in, PrintWriter out) throws IOException {
        int n = in.nextInt();
        int[] p = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = in.nextInt();
        }
        boolean[][] g = new boolean[n][n];
        for (int i = 0; i < n; ++i) {
            String s = in.next();
            for (int j = 0; j < n; ++j) {
                g[i][j] = s.charAt(j) == '1';
            }
        }
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    g[i][j] |= g[i][k] & g[k][j];
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (g[i][j] && p[j] < p[i]) {
                    int tmp = p[i];
                    p[i] = p[j];
                    p[j] = tmp;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            out.print(p[i] + " ");
        }
        out.println();
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