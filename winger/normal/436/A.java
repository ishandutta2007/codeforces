import java.io.*;

public class cf436A {

    public static void solve(Input in, PrintWriter out) throws IOException {
        int n = in.nextInt();
        int x = in.nextInt();
        int[] t = new int[n];
        int[] h = new int[n];
        int[] m = new int[n];
        for (int i = 0; i < n; ++i) {
            t[i] = in.nextInt();
            h[i] = in.nextInt();
            m[i] = in.nextInt();
        }
        int ans = 0;
        for (int ft = 0; ft < 2; ++ft) {
            int cur = 0, curt = ft, curh = x;
            boolean[] col = new boolean[n];
            while (true) {
                int next = -1;
                for (int i = 0; i < n; ++i) {
                    if (!col[i] && t[i] == curt && h[i] <= curh && (next == -1 || m[next] < m[i])) {
                        next = i;
                    }
                }
                if (next == -1) {
                    break;
                }
                col[next] = true;
                curh += m[next];
                curt = 1 - curt;
                cur++;
            }
            ans = Math.max(ans, cur);
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