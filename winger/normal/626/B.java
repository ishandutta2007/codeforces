import java.io.*;

public class CF626B {

    public static void solve(Input in, PrintWriter out) throws IOException {
        int n = in.nextInt();
        String s = in.next();
        int r = 0, g = 0, b = 0;
        for (char c : s.toCharArray()) {
            if (c == 'R') r++;
            if (c == 'G') g++;
            if (c == 'B') b++;
        }
        boolean[][][] col = new boolean[201][201][201];
        int ansMask = dfs(r, g, b, col);
        String ans = "";
        for (int i : new int[] {2, 1, 0}) {
            if ((ansMask & (1 << i)) != 0) {
                ans += "RGB".charAt(i);
            }
        }
        out.println(ans);
//        int[][] d = new int[n + 1][n + 1];
//        for (int i = 0; i < n; ++i) {
//            d[i][i + 1] |= 1 << ("RGB".indexOf(s.charAt(i)));
//        }
//        for (int len = 2; len <= n; ++len) {
//            for (int i = 0; i + len <= n; ++i) {
//                int j = i + len;
//                for (int k = i + 1; k < j; ++k) {
//                    for (int u = 0; u < 3; ++u) {
//                        for (int v = 0; v < 3; ++v) {
//                            if ((d[i][k] & (1 << u)) != 0 && (d[k][j] & (1 << v)) != 0) {
//                                d[i][j] |= u == v ? 1 << u : 1 << (3 - u - v);
//                            }
//                        }
//                    }
//                }
//            }
//        }
//        String ans = "";
//        for (int i = 0; i < 3; ++i) {
//            if ((d[0][n] & (1 << i)) != 0) {
//                ans += "RGB".charAt(i);
//            }
//        }
//        out.println(ans);
    }

    private static int dfs(int r, int g, int b, boolean[][][] col) {
        if (r < 0 || g < 0 || b < 0 || r >= col.length || g >= col[0].length || b >= col[1].length || col[r][g][b]) {
            return 0;
        }
//        System.err.println(r + " " + g + " " + b);
        if (r + g + b == 1) {
            return 1 * r + 2 * g + 4 * b;
        }
        col[r][g][b] = true;
        int ret = 0;
        if (r >= 2) ret |= dfs(r - 1, g, b, col);
        if (g >= 2) ret |= dfs(r, g - 1, b, col);
        if (b >= 2) ret |= dfs(r, g, b - 1, col);
        ret |= dfs(r - 1, g - 1, b + 1, col);
        ret |= dfs(r - 1, g + 1, b - 1, col);
        ret |= dfs(r + 1, g - 1, b - 1, col);
        return ret;
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