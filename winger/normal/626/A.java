import java.io.*;

public class CF626A {

    public static void solve(Input in, PrintWriter out) throws IOException {
        int n = in.nextInt();
        int[][] cnt = new int[401][401];
        int x = 200, y = 200;
        cnt[x][y]++;
        String s = in.next();
        String d = "UDLR";
        int[] dx = {-1, 1, 0, 0};
        int[] dy = {0, 0, -1, 1};
        for (char c : s.toCharArray()) {
            x += dx[d.indexOf(c)];
            y += dy[d.indexOf(c)];
            cnt[x][y]++;
        }
        int ans = 0;
        for (int[] ar : cnt) {
            for (int c : ar) {
                ans += c * (c - 1) / 2;
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