import java.io.*;

public class memsqlB {

    public static void solve(Input in, PrintWriter out) throws IOException {
        String s = in.next();
        int[] cs = new int[26];
        for (char c : s.toCharArray()) {
            cs[c - 'a']++;
        }
        for (int i = 0; i < 26; ++i) {
            if (cs[i] >= 100) {
                StringBuilder sb = new StringBuilder();
                for (int t = 0; t < 100; ++t) {
                    sb.append((char)(i + 'a'));
                }
                out.println(sb);
                return;
            }
        }
        int n = s.length();
        int[][] d = new int[n + 1][n + 1];
        int ansi = -1, ansj = -1, ans = 0;
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (d[i][j] <= 100 && d[i][j] > ans) {
                    ans = d[i][j];
                    ansi = i;
                    ansj = j;
                }
                if (i + j >= n) {
                    continue;
                }
                if (s.charAt(i) == s.charAt(n - j - 1)) {
                    d[i + 1][j + 1] = Math.max(d[i + 1][j + 1], d[i][j] + (i == n - j - 1 ? 1 : 2));
                }
                if (i + 1 <= n) {
                    d[i + 1][j] = Math.max(d[i + 1][j], d[i][j]);
                }
                if (j + 1 <= n) {
                    d[i][j + 1] = Math.max(d[i][j + 1], d[i][j]);
                }
            }
        }
        StringBuilder sb = new StringBuilder();
        StringBuilder sb1 = new StringBuilder();
        while (ansi > 0 || ansj > 0) {
            if (ansi > 0 && d[ansi][ansj] == d[ansi - 1][ansj]) {
                ansi--;
                continue;
            }
            if (ansj > 0 && d[ansi][ansj] == d[ansi][ansj - 1]) {
                ansj--;
                continue;
            }
            if (s.charAt(ansi - 1) == s.charAt(n - (ansj - 1) - 1) && d[ansi][ansj] == d[ansi - 1][ansj - 1] + (ansi - 1 == n - (ansj - 1) - 1 ? 1 : 2)) {
                sb.append(s.charAt(ansi - 1));
                if (ansi - 1 != n - (ansj - 1) - 1) {
                    sb1.append(s.charAt(ansi - 1));
                }
                ansi--;
                ansj--;
            }
        }
        out.print(sb.reverse());
        out.println(sb1);
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