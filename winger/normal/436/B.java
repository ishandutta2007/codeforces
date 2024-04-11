import java.io.*;

public class cf436B {

    public static void solve(Input in, PrintWriter out) throws IOException {
        int n = in.nextInt();
        int m = in.nextInt();
        int k = in.nextInt();
        char[][] f = new char[n][];
        for (int i = 0; i < n; ++i) {
            f[i] = in.next().toCharArray();
        }
        int[] ans = new int[m];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (f[i][j] == 'L') {
                    // i, j-t
                    if (j - i >= 0) {
                        ans[j - i]++;
                    }
                } else if (f[i][j] == 'R') {
                    //i, j + t
                    if (j + i < m) {
                        ans[j + i]++;
                    }
                } else if (f[i][j] == 'U') {
                    //i-t, j
                    if (i % 2 == 0) {
                        ans[j]++;
                    }
                } else if (f[i][j] == 'D') {
                    //i+t, j
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            out.print(ans[i] + " ");
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